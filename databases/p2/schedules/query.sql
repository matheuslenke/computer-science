select  a.attr, a."#t" , a."time" , b."#t" , b."time" , c."time"
from "Schedule" a  join "Schedule" b on  a.attr = b.attr 
join "Schedule" c on b."#t" = c."#t" 
where a.op = 'R' 
	and b.op = 'W' 
    and a."#t" != b."#t" 
    and a."time" > b."time" -- seleciona reads que aconteceram após writes em #t diferentes
	and c.op = 'C' 
    and c."time" > a."time"









