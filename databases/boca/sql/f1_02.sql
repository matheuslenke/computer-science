SELECT drivers.nationality
FROM drivers INNER JOIN results on results.driverId = drivers.driverId
INNER JOIN constructors on results.constructorId = constructors.constructorId
WHERE results.positionOrder <= 3
EXCEPT (SELECT nationality from constructors)