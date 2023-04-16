create table student(
sno char(9) primary key,
sname char
(20),
ssex char(2),
sage int,
sdept char(20)
);

create table course(
cno char(4) primary key,
cname char(40),
cpno char(4),
ccredit int,
foreign key(cpno) references course(cno)
);

create table sc(
cno char(4),
sno char(9),
grade int,
primary key(sno,cno),
foreign key(sno) references student(sno),
foreign key(cno) references course(cno)
);


alter table student add BloodType char(2);
alter table student modify (sdept varchar2(70));
alter table student add constraint ck_sage check(sage>15 and sage<30);
alter table student drop constraint ck_sage;

alter table student drop(BloodType);

create unique index stusnam1130 on student(sname);

create unique index i_sc1130 on sc(sno asc,cno desc);

drop index stusnam1130;

drop index i_sc1130;

insert into Student(Sno,Sname,Ssex,Sage,Sdept) values('200215121','李勇','男','20','CS');
insert into Student(Sno,Sname,Ssex,Sage,Sdept) values('200215122','刘晨','女','19','CS');
insert into Student(Sno,Sname,Ssex,Sage,Sdept) values('200215123','王敏','女','18','MA');
insert into Student(Sno,Sname,Ssex,Sage,Sdept) values('200215125','张立','男','19','IS');

insert into Course(Cno,Cname,Cpno,Ccredit) values('2','数字',null,'2');
insert into Course(Cno,Cname,Cpno,Ccredit) values('6','数据处理',null,'2');
insert into Course(Cno,Cname,Cpno,Ccredit) values('7','PASCAL语言','6','4');
insert into Course(Cno,Cname,Cpno,Ccredit) values('4','操作系统','6','3');
insert into Course(Cno,Cname,Cpno,Ccredit) values('5','数据结构','7','4');
insert into Course(Cno,Cname,Cpno,Ccredit) values('1','数据库','5','4');
insert into Course(Cno,Cname,Cpno,Ccredit) values('3','信息系统','1','4');

insert into SC(Sno,Cno,Grade) values('200215121','1','92');
insert into SC(Sno,Cno,Grade) values('200215121','2','85');
insert into SC(Sno,Cno,Grade) values('200215121','3','88');
insert into SC(Sno,Cno,Grade) values('200215122','4','90');
insert into SC(Sno,Cno,Grade) values('200215122','3','80');

update student set sage=20 where sname='王敏';
update student set sage=sage+1;
update SC set Grade='0' where Sno in(select Sno from Student where Sdept='CS');

delete from SC where Sno in(select Sno from Student where Sdept='CS');
delete from Student where Sdept in(select Sdept from Student where Sname='刘晨');

drop table sc;
drop table student;
drop table course;

