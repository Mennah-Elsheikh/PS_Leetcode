/* Write your T-SQL query statement below */
select distinct r.contest_id , round(count(distinct r.user_id) * 100.00/ (select count( distinct user_id) from Users ), 2 )  as percentage 
from Register as r 
join Users as u 
on u.user_id = r.user_id 
group by r.contest_id 
order by percentage desc, r.contest_id asc ;  
