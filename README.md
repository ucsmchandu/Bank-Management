FOLLOW THESE SQL CODE DATA STORAGE

create database bank;
use bank;

 create table account(
 id int primary key auto_increment,
 name varchar(225) not null,
 father_name varchar(225)not null,
 mother_name varchar(225) not null,
 phone varchar(225) not null,
 aadhar varchar(225) not null,
 address varchar(250),
 account_number varchar(220) not null,
 pin varchar(225) not null,
 balance double);
 
 create table nmlaccount(
 id int primary key auto_increment,
 name varchar(225) not null,
 father_name varchar(225)not null,
 mother_name varchar(225) not null,
 phone varchar(225) not null,
 aadhar varchar(225) not null,
 address varchar(250),
 account_number varchar(220) not null,
 pin int not null,
 balance double);

create table history(
id int,
transition_history varchar(250),
account_number varchar(225),
phone varchar(225),
timedate varchar(225) 
);
