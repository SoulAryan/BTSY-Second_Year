drop database if exists triggers;
create database triggers;
use triggers;

create table Student
(
	SID int primary key,
    Name varchar(255),
    Marks int
);

create table Student_Log   -- log table cteated
(
	Message varchar(255)
);

 delimiter //
create trigger after_insert    -- creation of trigger
after insert on student
for each row 
begin
	insert into Student_Log
    values(concat('Student Inserted : ',new.name));

end //    
delimiter ;

insert into Student(SID,Name,Marks)  -- inserting values
values
(1,'Aryan Suryavanhi',100);

select * from Student_Log;   -- show values

--   AFTER UPDATE

delimiter //
create trigger after_update
after update on Student
for each row
begin
	insert into Student_Log
    values(concat("Marks Updated : ", new.marks));
end //
delimiter ;    
    
Update Student
Set Marks = 0
where SID = 1;

select * from Student_Log;

-- BEFORE INSERT 

delimiter //
create trigger before_insert
before insert on Student
for each row
begin
	insert into Student_Log
    values(concat("Before Inserted Value : ", old.name));
end //
delimiter ;
    
     
    
    