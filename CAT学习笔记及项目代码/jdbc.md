*在cmd窗口编译就将jar包的地址加到classpath*

*在idea编译就将jar导入模块*

# jdbc连接数据库

##### 导包

import java.sql.Driver;

import java.sql.DriverManager;

import java.sql.SQLExceptiion;

import java.sql.Statement;

*要在try，catch中实行这些语句*

## 1.注册驱动

```java
//第一种
DriverManager.registerDriver(new com.mysql.jdbc.Driver());
//可拆：
Driver driver = new com.mysql.jdbc.Driver();
DriverManager.registerDriver(driver);
//第二种
String driver = "com.mysql.jdbc.Driver";
Class.forName(driver);//运用类加载调用方法来注册，常用，可用配置                                          文件来改
```

## 2.获取连接

```java
String url = "jdbc:mysql://192.168.151.9:3306/bjpowernode";//网课老师的例子
//jdbc:mysql://  通讯协议
//192.168.151.9  本机（服务器）的ip地址 本机可用localhost
//3306           mysql的服务器端口
//bjpowernode    库名
String user = "root";
String password = "333";
Connection conn = DriverManage.getConnection(url, user, passward);
System.out.println("数据库连接对象：" + conn);
```

## 3.获取数据库操作对象

```java
Statement stmt = conn.createStatement();
```

## 4.执行sql语句

```java
String sql1 = "insert into 表名 values(......)";//sql语句不加';'
String sql2 = "delete from 表名 where  .....";
String sql3 = "update 表名 set .......  where .... ";
String sql4 = "select 字段，字段 from 表名";
int count = stmt.executeUpdate(sql1);
```

## 5.处理查询结果集

```java
ResultSet rs = null;
rs = stmt.executeQuery(sql4);
while (rs.next()){
    String 字段 = rs.getString(1);//也可以是字段，是修改最终的字段
    String 字段 = rs.getString(2);//也可以是字段
    String 字段 = rs.getString(3);//也可以是字段
    System.out.println(字段 + "," + 字段 + "," + 字段);
}
//getInt,getDouble等都可以，但要谨慎使用
```

## 6.释放资源

```java
//要将stmt等的定义提到try外面
if(stmt != null){
    stmt.close();
}
if(conn != null){
    conn.close();
}
//必须关闭，在finally中关闭，各个分开用try，catch关闭
//由小到大关闭
```

+++

****

## 7.程序例子

完成登录的例子

**小插曲(配置文件的使用)***

在程序头部导包 import  java.util.*;

在main函数开头写：

```java
ResourceBundle  bundle = ResourceBundle .getBundle("jdbc");

String driver = bundle.getString("driver");

String url = bundle.getString("url");

String user = bundle.getString("user");

String password = bundle.getString("password");
```

在当前文件夹中加一个propertises文件写：

driver =  com.mysql.jdbc.Driver

url = jdbc:mysql://192.168.151.9:3306/bjpowernode

user = hiuhih

passw =  333

## PreparedStatement的用法

```java
PreparedStatement ps = null;
String sql = "select code from LoginCode where name = ? and name = ?";
ps = conn.prepareStatement(sql);
ps.setString(1, "...");//给第一个？的地方加字符串
ps.setString(2, "...");//给第一个？的地方加字符串
//这里可以setInt，setDouble。。。。
rs = ps.executeQuery();
```

## 必须用statement的例子

```java
String keyword = s.nextLine();//保存用户输入的升序（asc）或降序（desc）
String sql = "select * from code order by" + keyword;
stmt = conn.createStatement();
rs = stmt.executeQuery(sql);
```

## 事务的处理

```java
//将自动提交改为手动提交
conn.setAutoCommit(false);
//在要事务执行结束时手动提交
conn.commit();
//在异常处理进行回滚
catch(Exception e){
	if(count != null){ //两个事务成功一个时
        try{
            conn.rollback();//rollback抛异常
        }catch(SQLException e1){
            e1.printStackTrace();
        }
    }    
}

```

## 工具类

```java
public class DBUtil{
    private DBUril(){ //防止工具类被new，工具类一般直接用类名调静态方法
    }
    static{  // 静态代码块，在类加载的时候会被执行一次，且仅执行一次
        try{
            Class.forName("com.mysql.jdbc.Driver");
        }catch(ClassNotFoundException e){
            e.printStackTrace();
        }
    }
    public static Connection getConnection() throws SQLException{
        return DriverManager.getConnection
                           ("jdbc:mysql://localhost:3306/test");
    }
    public static void close(Connection conn, Statement stmt, ResultSet rs)	   {
        if(rs != null)
            try{
                rs.close();
            }catch(SQLException e){
                e.printStackTrace();
            }
    	if(stmt != null)
            try{
                stmt.close();
            }catch(SQLException e){
                e.printStackTrace();
            }
    	if(conn != null)
            try{
                conn.close();
            }catch(SQLException e){
                e.printStackTrace();
            }
    }
}
```

***在别的类中调用工具类***

```java
//加载了工具类所以类里的静态代码块被执行，完成注册
//调用了工具类的getConnection方法完成获取连接对象
Connection conn = DBUtil.getConnection();
//在finally中要关闭时
DBUtil.close(conn, stmt/ps, rs);
```

***再来一个小插曲***

在sql语句中，在要模糊查询时（查询名字第二个字母是A的人的记录）

```java
//错误写法
String sql = "select * from code where name like '_?%'"//单引号中的？不再是占位														 符
ps = conn.prepareStatement(sql);
ps.setString(1, "A");
//正确写法
String sql = "select * from code where name like ?"
ps = conn.prepareStatement(sql);
ps.setString(1, "_A%");
```

## 悲观锁

***又名行（hang）级锁***

在 select 语句后面加 for update，此时除本身事务外，别的事务不得再修改该记录直到本身事务结束

### 乐观锁

当一个事务修改了某记录之后该记录后面的版本号会更新；若有别的事务在同时修改这个记录，且提交的比前一个事务慢，看到该记录的版本号变了会影响自身的修改可以rollback