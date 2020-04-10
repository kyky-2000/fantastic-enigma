package com.hky.event.dao;

import com.hky.event.util.DBUtil;

import java.sql.*;

public class Register {
    public static boolean register(String loginName, char[] loginPassword, String name){
        String pwd = new String(loginPassword);
        //标识是否登录成功
        boolean registeSuccess = false;
        //连接数据的基本操作
        Connection conn = null;
        PreparedStatement ps = null;
        Statement stmt = null;
        ResultSet rs = null;
        try{
            //调用工具类，注册驱动并获取连接对象
            conn = DBUtil.getConnection();
            //获取数据库操作对象
            String sql = "select * from user where loginName = ?";
            //目的是防止sql注入
            ps = conn.prepareStatement(sql);
            ps.setString(1, loginName);
            //执行sql语句
            rs = ps.executeQuery();
            //处理查询结果集
            if(true == rs.next())
                return false;
            if(false == rs.next()){
                String sql1 = "insert into user values('"+loginName+"', '"+name+"', '"+pwd+"', 'user')";
                stmt = conn.createStatement();
                int count = stmt.executeUpdate(sql1);
                if(count == 1){
                    registeSuccess = true;
                }
            }
        }catch(Exception e){
            e.printStackTrace();
        }finally{
            //释放资源
            DBUtil.close(conn, ps, rs);
            if(null != stmt)
                try{
                    stmt.close();
                }catch(SQLException e){
                    e.printStackTrace();
                }
        }
        return registeSuccess;
    }
}

