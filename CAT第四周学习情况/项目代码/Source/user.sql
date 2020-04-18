drop table if exists user;

/*==============================================================*/
/* Table: user                                                  */
/*==============================================================*/
create table user
(
   uID                  int auto_increment,
   name                 varchar(20),
   loginName            varchar(20),
   loginPwd             varchar(20),
   balance              int,
   status               varchar(10),
   primary key (uID)
);
