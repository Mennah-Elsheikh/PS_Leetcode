/* Write your T-SQL query statement below */
SELECT 
    ROUND(
        COUNT(DISTINCT a.player_id) * 1.0 / COUNT(DISTINCT f.player_id),
        2
    ) AS fraction
FROM (
    -- Step 1: get each player's first login date
    SELECT player_id, MIN(event_date) AS first_login
    FROM Activity
    GROUP BY player_id
) f
LEFT JOIN Activity a
    ON f.player_id = a.player_id
   AND a.event_date = DATEADD(day, 1, f.first_login);
