/* Write your T-SQL query statement below */
SELECT W1.Id
FROM Weather AS W1
INNER JOIN Weather AS W2
ON W1.RecordDate = DATEADD(DAY, 1, W2.RecordDate)
WHERE W1.Temperature > W2.Temperature;
