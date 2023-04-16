drop table Student cascade constraints;
drop table SC  cascade constraints;
drop table Course cascade constraints;

create table Student
(
Sno char(20) primary key,
Sname char(20) not null unique,
Ssex char (2),
Sage smallint,
Sdept char(20)
);

create table Course
(
Cno char(4) primary key,
Cname char(40) not null unique,
Cpno char (4),
Ccredit smallint,
foreign key (Cpno) references Course(Cno)

);


create table SC
(
Sno char(9),
Cno char(4),
Grade smallint,
primary key (Sno,Cno),
foreign key(Sno) references Student(sno),
foreign key (Cno) references Course(Cno)
);


alter table Student add BloodType char(4) ;
alter table Student Modify(Sdept char(2));
alter table Student add constraint CK_age check(Sage>15 and Sage<30);
alter  table Student drop constraint CK_age;
alter table Student drop (BloodType);


create unique index stuname on Student(Sname,substr(Sno,-4,4));
create unique index i_sc on SC(Sno asc,Cno desc,substr(sno,-4,4));
drop index stuname;
drop index i_sc;

delete from Student where(Sno='200215121');
delete from Student where (Sno='200215122');
delete from Student where (Sno='200215123');
delete from Student where (Sno='200215125');

insert into Student(Sno,Sname,Ssex,Sage,Sdept) values('200215121','李勇','男','20','CS');
insert into Student(Sno,Sname,Ssex,Sage,Sdept) values('200215122','刘晨','女','19','CS');
insert into Student(Sno,Sname,Ssex,Sage,Sdept) values('200215123','王敏','女','18','MA');
insert into Student(Sno,Sname,Ssex,Sage,Sdept) values('200215125','张立','男','19','IS');

delete from Course where (Cno='1');
delete from Course where (Cno='2');
delete from Course where (Cno='3');
delete from Course where (Cno='4');
delete from Course where (Cno='5');
delete from Course where (Cno='6');
delete from Course where (Cno='7');

insert into Course(Cno,Cname,Cpno,Ccredit) values('2','数字',null,'2');
insert into Course(Cno,Cname,Cpno,Ccredit) values('6','数据处理',null,'2');
insert into Course(Cno,Cname,Cpno,Ccredit) values('7','PASCAL语言','6','4');
insert into Course(Cno,Cname,Cpno,Ccredit) values('4','操作系统','6','3');
insert into Course(Cno,Cname,Cpno,Ccredit) values('5','数据结构','7','4');
insert into Course(Cno,Cname,Cpno,Ccredit) values('1','数据库','5','4');
insert into Course(Cno,Cname,Cpno,Ccredit) values('3','信息系统','1','4');

delete SC where Sno='200215122';
delete SC Where Sno='200215121';

insert into SC(Sno,Cno,Grade) values('200215121','1','92');
insert into SC(Sno,Cno,Grade) values('200215121','2','85');
insert into SC(Sno,Cno,Grade) values('200215121','3','88');
insert into SC(Sno,Cno,Grade) values('200215122','4','90');
insert into SC(Sno,Cno,Grade) values('200215122','3','80');

update Student set Sage=20 where Sname='王敏';
update Student set Sage=Sage+1 ;
update SC set Grade='0' where Sno in(Select Sno from Student where Sdept='CS');



