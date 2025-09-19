/* Write your T-SQL query statement below */
select distinct contest_id , round(count(*) * 100.00/ (select count( distinct user_id) from Users ), 2 )  as percentage 
from Register 
group by contest_id 
order by percentage desc, contest_id asc ;  
