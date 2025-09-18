/* Write your T-SQL query statement below */
SELECT 
    p.product_id,
    isnull (ROUND(SUM(u.units * p.price) * 1.0 / SUM(u.units), 2) , 0 )  AS average_price
FROM UnitsSold u
RIGHT JOIN Prices p
    ON u.product_id = p.product_id
   AND u.purchase_date BETWEEN p.start_date AND p.end_date
GROUP BY p.product_id;
