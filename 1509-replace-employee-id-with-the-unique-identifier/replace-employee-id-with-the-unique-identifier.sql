# Write your MySQL query statement below
select ue.unique_id , e.name 
from EmployeeUNI as ue
right join Employees as e 
on e.id = ue.id ;
