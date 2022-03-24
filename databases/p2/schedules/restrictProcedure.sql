CREATE OR REPLACE FUNCTION testeScheduleRestrito()
RETURNS integer AS $func$
DECLARE _count_bad_reads integer;
BEGIN

select count(*) into _count_bad_reads from
  (select  a.attr, a."#t" , a.time , b."#t" , b.time , c.time
  from "Schedule" a  join "Schedule" b on  a.attr = b.attr 
  join "Schedule" c on b."#t" = c."#t" 
  where (a.op = 'R' or a.op = 'W')
      and b.op = 'W' -- Precisa ser um write
      and a."#t" != b."#t" -- Transacoes diferentes
      and a."time" > b."time" 
      and (c.op = 'C' or c.op = 'A') -- Commitado ou Abortado
      and c."time" > a."time"
  ) _s;

IF _count_bad_reads > 0 THEN
	RETURN 0;
ELSE
	RETURN 1;
END IF;

RETURN 1;
END
$func$ LANGUAGE plpgsql;

SELECT testeScheduleRestrito()



