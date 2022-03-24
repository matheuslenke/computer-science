CREATE TYPE S_tbl AS ("time" integer, "#t" integer, "op" character, "attr" character);

CREATE TABLE "Schedule"       OF S_tbl (PRIMARY KEY(time));
CREATE TABLE "Schedule_prime" OF S_tbl (PRIMARY KEY(time));


CREATE OR REPLACE FUNCTION testeEquivalenciaPorVisao()
RETURNS integer AS
$func$ 
declare 
_count_aux integer;
BEGIN
-- 1.1) The same set of transactions participates in S and S′
select count(*) into _count_aux from
	(select "#t" from "Schedule" 
		except 
	 select "#t" from "Schedule_prime") _s;

if _count_aux > 0 then return -1; end if; 

-- 1.2) S and S′ include the same operations of those transactions. 
-- Aqui utilizamos o groupBy pois estamos considerando que uma operação (#t, op, attr) pode acontece mais de uma vez, em tempos diferentes
-- Por exemplo, uma transação t escrever mais de uma vez no atributo Y.
select count(*) into _count_aux from  
	(select  "#t", op, attr, count(*) from "Schedule"       group by "#t", op, attr
		except 
	 select  "#t", op, attr, count(*) from "Schedule_prime" group by "#t", op, attr)__s;
	
if _count_aux > 0 then return -1; end if; 

-- 2) For any operation ri(X) of Ti in S, if the value of X read by the operation has been written 
--    by an operation wj(X) of Tj,  (or if it is the original value of X before the schedule started)
--    the same condition must hold for the value of X read by operation ri(X) of Ti in S′.
--
-- Método: Agregamos as operações de escrita de cada atributo que aconteceram antes da leitura de cada um deles em ambas tabelas, 
-- e checamos se deu o mesmo resultado (Contando as divergencias com a keyword except).
--
-- Exemplo: Se em S a transação T1 possui duas operações W(X) antes de R(X) de T2, e uma operação W(Y) antes de R(Y) de T1, 
-- a tabela intermediária será a seguinte:
--  +------+-------+------+--------+
--  | s.#t | attr  |s2.#t |  count |
--  +------+-------+------+--------+
--  |    2 | X     |    1 |      2 |
--  |    1 | Y     |    1 |      1 |
--  +------+-------+------+--------+
--  Lemos a primeira linha da tabela da seguinte forma: "T2 executou R(X) após T1 executar W(X) duas vezes"
--
-- Se forem as mesmas linhas nessas tabelas de S e S', a condição 2.1 foi obedecida. 
--
-- Repare que essa solução também cobre o caso em parênteses "(or if it is the original value of X before the schedule started)",
-- afinal, se em somente um dos escalonamentos não mais ser o valor original de X ao realizar uma leitura,
-- significa que houve uma escrita, e ela aparecerá em uma das tabelas, resultando numa divergência.

select count(*) into _count_aux from 
	(select  s."#t", s.attr, s2."#t", count(*) from "Schedule" s left outer join "Schedule" s2 
			on  s.attr = s2.attr 
			where s.op = 'R'
			  and s2.op = 'W'
			  and s."time" > s2."time" 
			group by s."#t", s.attr, s2."#t"
		except
	select  s."#t", s.attr, s2."#t", count(*) from "Schedule_prime" s left outer join "Schedule_prime" s2 
			on  s.attr = s2.attr 
			where s.op = 'R'
			  and s2.op = 'W'
			  and s."time" > s2."time" 
			group by s."#t", s.attr, s2."#t")___s;

if _count_aux > 0 then return -2; end if; 

-- 3. If the operation wk(Y) of Tk is the last operation to write item Y in S, 
--    then wk(Y) of Tk must also be the last operation to write item Y in S′.

-- Utilizando a função max, identificaremos em ambas tabelas a ultima operação Write de cada atributo, e identificaremos 
-- a qual transação essa operação pertence.
-- Por fim, contamos se há divergência entre as duas tabelas resultantes.

-- Exemplo, considere as tabelas de escalonamento: 
--                  S											S' 
--      +------+----+----+------+                 +------+----+----+------+
--      | time | #t | op | attr |                 | time | #t | op | attr |
--      +------+----+----+------+                 +------+----+----+------+
--      |    1 |  1 | R  | X    |                 |    1 |  1 | R  | X    |
--      |    2 |  1 | W  | X    |                 |    2 |  2 | R  | X    |
--      |    3 |  1 | C  | -    |                 |    3 |  2 | W  | X    |
--      |    4 |  2 | R  | X    |                 |    4 |  1 | W  | X    |
--      |    5 |  2 | W  | X    |                 |    5 |  2 | C  | -    |
--      |    6 |  2 | C  | -    |                 |    6 |  1 | C  | -    |
--      +------+----+----+------+                 +------+----+----+------+
--
-- tabelas intermediarias que mostram a ultima escrita de cada atributo:
--                  S                                           S'
--            +------+----+                               +------+----+
--            | attr | #t |                               | attr | #t |
--            +------+----+                               +------+----+
--            | X    |  2 |                               | X    |  1 |
--            +------+----+                               +------+----+
-- novamente comparamos as linhas das tabelas e contamos as divergências, 
-- caso pelo menos uma divergência, os escalonamentos não são equivalentes.

select count(*) into _count_aux from 
	(select s_.attr as attr, "#t" from 
			(select attr, max("time") as lasttime from "Schedule"  where op = 'W' group by attr)s_ 
			join "Schedule" on lasttime = "time"
		except 
	select s__.attr as attr, "#t" from 
		(select attr, max("time") as lasttime from "Schedule_prime"  where op = 'W' group by attr)s__
		join "Schedule_prime" on lasttime = "time")s___;
		
if _count_aux > 0 then return -3; end if; 

-- Se chegou até aqui, os escalonamentos são equivalentes por visão :)

RETURN 1;

END 
$func$ LANGUAGE plpgsql;