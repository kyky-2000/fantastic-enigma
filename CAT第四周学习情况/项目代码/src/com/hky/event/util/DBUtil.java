package com.hky.event.util;

import java.sql.*;

/**
 * 工具类，简化数据库登录操作
 */
public class DBUtil {
    private DBUtil(){
    }
    static{
        try{
            Class.forName("com.mysql.jdbc.Driver");
        }catch(ClassNotFoundException e){
            e.printStackTrace();
        }
    }
    public static Connection getConnection() throws SQLException {
        return DriverManager.getConnection("jdbc:mysql://localhost:3306/ProjectDatabase",
                "root", "369");
    }
    public static void close(Connection conn, Statement stmt, ResultSet rs){
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
