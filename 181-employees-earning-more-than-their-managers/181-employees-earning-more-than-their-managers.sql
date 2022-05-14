# Write your MySQL query statement below
select 
    a.name as Employee
from 
    Employee as a,
    Employee as b 
where 
    b.id=a.managerId 
        and 
    a.salary>b.salary