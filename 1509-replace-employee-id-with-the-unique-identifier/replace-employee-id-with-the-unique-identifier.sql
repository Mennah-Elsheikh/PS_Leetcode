/* Write your T-SQL query statement below */
select EmployeeUNI.unique_id , Employees.name 
from Employees
LEFT JOIN EmployeeUNI 
on Employees.id = EmployeeUNI.id ; 