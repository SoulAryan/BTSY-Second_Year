drop database if exists Platinum;
create database Platinum;
use Platinum;

Create table Student
(
	Std_ID int primary key,
    Name varchar(255),
    Roll_No int
);

insert into Student(Std_ID,Name,Roll_No)
values
(1,'Aryan Suryavanshi',8),
(2,'Soham Kane',47),
(3,'Sashreek Gokhale',37),
(4,'Shrivarad Bhagwatikar',16),
(5,'Dhawal Chaudhari',28);

Delimiter $$
create Procedure GetStudentDetails(In Sid int)
Begin
	Select * from Student
    where Std_ID = Sid;
END $$
Delimiter ;    

Call GetStudentDetails(1);
