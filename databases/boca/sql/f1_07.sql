SELECT CONCAT(constructors.name) as Equipe,
CONCAT(drivers.forename, ' ', drivers.surname) as Piloto,
CONCAT(circuits.name) as Circuito,
CONCAT(races.year) as Ano
FROM drivers 
INNER JOIN results on drivers.driverId = results.driverId 
INNER JOIN races on results.raceId = races.raceId
INNER JOIN circuits on races.circuitId = circuits.circuitId
INNER JOIN constructors ON results.constructorId = constructors.constructorId

WHERE results.positionOrder = 1
AND constructors.nationality = 'French'