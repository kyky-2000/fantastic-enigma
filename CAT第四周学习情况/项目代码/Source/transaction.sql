drop table if exists transaction;

/*==============================================================*/
/* Table: transaction                                           */
/*==============================================================*/
create table transaction
(
   uID                  int,
   eID                  int,
   discount             float,
   primary key(uID, eID),
   foreign key(uID) references user(uID)
);
