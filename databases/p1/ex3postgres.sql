WITH "races_season" AS (
    SELECT * 
    FROM "races"
    WHERE "year" = 2020
),
    "results_races" AS (
    SELECT * 
    FROM results JOIN (
         SELECT * 
        FROM "races"
        WHERE "year" = 2020
    ) USING (raceId)
),
    "constructors_season" AS (
    SELECT DISTINCT "constructorId", "name"
    FROM "results_races" JOIN "constructors" USING ("constructorId")
),
    "constructors_result_per_race" AS (
    SELECT "constructorId", "name", "raceId", SUM("points") AS "points_per_race"
    FROM ("constructors_season" CROSS JOIN "races_season") LEFT OUTER JOIN "results_races" USING ("constructorId", "raceId")
    GROUP BY "constructorId", "name",  "raceId"
    ORDER BY "raceId"
),
    "standings" AS (
    SELECT DENSE_RANK() OVER (ORDER BY SUM("points_per_race") DESC) AS "rank",
           "constructorId",
           array_agg(CASE 
                          WHEN "points_per_race" > 0 THEN LPAD("points_per_race"::text, 2, '0')
                          ELSE LPAD('',2,'*')
                     END) AS "points_season",
           SUM("points_per_race") AS "total_points"
    FROM "constructors_result_per_race"
    GROUP BY "constructorId", "name"
    ORDER BY "rank" ASC, "total_points" DESC
)
SELECT "rank" AS "Pos",
       "name" AS "Team",
       "total_points" AS "Points",
       array_to_string("points_season", ' | ') AS "Standings"
FROM "standings" JOIN "constructors" USING ("constructorId")
ORDER BY "Pos" ASC, "Points" DESC, "Team" ASC;
