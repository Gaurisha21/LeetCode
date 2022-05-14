# Write your MySQL query statement below
select Department.name as Department, Employee.name as Employee, salary 
from 
    Employee join Department on Employee.departmentId=Department.id
where 
    (Employee.DepartmentId, Salary) in 
        (select 
            DepartmentId, max(salary)
         from 
            Employee
         group by DepartmentId)
    