drop table if exists EventInfo;

/*==============================================================*/
/* Table: EventInfo                                             */
/*==============================================================*/
create table EventInfo
(
   eID                  bigint auto_increment,
   eDate               datetime,
   blue                 varchar(20),
   red                  varchar(20),
   price	            double,
   primary key (eID)
);
