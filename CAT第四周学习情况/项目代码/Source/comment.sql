drop table if exists comment;

/*==============================================================*/
/* Table: comment                                               */
/*==============================================================*/
create table comment
(
   cID                  int auto_increment,
   eID                  int,
   comment              varchar(50),
   primary key (cID),
   foreign key(eID) reference 
);
