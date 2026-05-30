-- GROUP BY --
drop database if exists groupby;
create database groupby;
use groupby;

drop table if exists Department;
create table Department
(
    Dept_ID int,
    Dept_Name varchar(255),
    Location varchar(255)
);

insert into department(Dept_id, Dept_Name, location)
Values
(1, 'IT', 'New York'),
(2, 'HR', 'Los Angeles'),
(3, 'Finance', 'Chicago');

drop table if exists employee;
create table Employee
(
	Emp_ID varchar(255),
    Emp_Name varchar(255),
    Dept_Name varchar(255),
    Salary int    
);

insert into employee(Emp_id, Emp_name, Dept_Name, salary)
Values
(1, 'John Doe', 'IT', 50000),
(2, 'Jane Doe', 'HR', 60000),
(3, 'Jim Brown', 'IT', 55000),
(4, 'Jack Smith', 'HR', 65000),
(5, 'Jill White', 'Finance', 70000),
(6, 'Joe Black', 'Finance', 75000);

Select Dept_Name,sum(salary)
from employee
Group by Dept_Name
Having Sum(salary) > 125000;