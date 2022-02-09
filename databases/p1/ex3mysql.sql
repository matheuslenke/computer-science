SET @row_number = 0;
SET @group_varian = '';
SET @rank_points = -1;
SELECT rank as Pos,
name as Team,
total_points as Points,
points_season as Standings
FROM (
  SELECT
  @row_number:=( CASE 
    WHEN (@group_varian = constructorId)
      THEN @row_number
    WHEN (@group_varian != constructorId AND total_points > @rank_points)
      THEN @row_number + 1
    WHEN (@group_varian != constructorId AND total_points = @rank_points)
      THEN @row_number
    END) AS rank, 
  @group_varian:=constructorId as groupVarian,
  @rank_points = total_points,
  name,
  total_points,
  REPLACE(points_season, ',', ' | ') as points_season
  FROM (SELECT constructorId,
      name,
      GROUP_CONCAT( IF(points_per_race > 0,
        LPAD(cast(points_per_race as char), 2, '0'),
        LPAD('',2,'*')
        ) order by raceId) AS points_season,
        SUM(points_per_race) as total_points
    FROM
    (SELECT constructorId, name, raceId, SUM(points) AS points_per_race
      FROM (
        (
          SELECT DISTINCT constructorId, name
          FROM (
            SELECT * 
            FROM results JOIN (
              SELECT * 
              FROM races
              WHERE year = 2020
            ) as races_season USING (raceId)
          ) as results_races JOIN constructors USING (constructorId)
        ) as constructors_season
        CROSS JOIN 
          (
            SELECT * 
            FROM races
            WHERE year = 2020
          ) as races_season
        ) LEFT OUTER JOIN 
        (
          SELECT * 
          FROM results JOIN (
            SELECT * 
            FROM races
            WHERE year = 2020
          ) as races_season USING (raceId)
        ) as results_races
        USING (constructorId, raceId)
      GROUP BY raceId, constructorId, name
      ORDER BY raceId ASC, points_per_race DESC
    ) as constructors_result_per_race
    GROUP BY constructorId, name
    ORDER BY total_points DESC
  ) as query1
  ORDER BY rank ASC, name ASC
) as final_results
