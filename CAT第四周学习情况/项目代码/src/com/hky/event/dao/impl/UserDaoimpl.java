package com.hky.event.dao.impl;

import com.hky.event.dao.UserDao;
import com.hky.event.entity.User;
import com.hky.event.service.impl.UserServiceimpl;
import com.hky.event.util.DBUtil;

import java.sql.*;
import java.util.ArrayList;

public class UserDaoimpl implements UserDao {

    public User login(String loginName, String loginPwd, String status) {
        //连接数据的基本操作
        Connection conn = null;
        PreparedStatement ps = null;
        ResultSet rs = null;
        User user = new User();

        try{
            //调用工具类，注册驱动并获取连接对象
            conn = DBUtil.getConnection();

            //获取数据库操作对象
            String sql = "select * from user where loginName = ? and loginPwd = ? and status = ?";

            ps = conn.prepareStatement(sql);
            ps.setString(1, loginName);
            ps.setString(2, loginPwd);
            ps.setString(3, status);
            //执行sql语句
            rs = ps.executeQuery();
            //处理查询结果集
            if( rs.next() ){
                user.setID(rs.getInt(1));
                user.setName(rs.getString(2));
                user.setLoginName(rs.getString(3));
                user.setPassword(rs.getString(4));
                user.setBalance(rs.getDouble(5));
                user.setStatus(rs.getString(6));
            }else
                user = null;
        }catch(Exception e){
            e.printStackTrace();
        }finally{
            //释放资源
            DBUtil.close(conn, ps, rs);
        }

        return user;
    }

    public boolean regist(String name, String loginName, String loginPassword){
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
                String sql1 = "insert into user(name, loginName, loginPwd, balance, status) values('"+name+"', '"+loginName+"', '"+loginPassword+"', '0', 'user')";
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

    public boolean investment(int uID, int amount){
        boolean investSuccess = false;
        Connection conn = null;
        Statement stmt = null;
        String sql = null;
        try{
            conn = DBUtil.getConnection();
            stmt = conn.createStatement();

            sql = "update user set balance = balance + "+amount+" where uID = '"+uID+"'";
            int count = stmt.executeUpdate(sql);
            if(count == 1)
                investSuccess = true;
        }catch(SQLException e){
            e.printStackTrace();
        }finally {
            DBUtil.close(conn, stmt, null);
        }

        return investSuccess;
    }

    public boolean reviseData(String data, String str, int uID){
        boolean reviseSuccess = false;
        Connection conn = null;
        Statement stmt = null;
        String sql = null;

        try{
            conn = DBUtil.getConnection();
            stmt = conn.createStatement();
            if(str == "name")
                sql = "update user set name = '"+data+"' where uID = '"+uID+"'";
            else
                sql = "update user set loginPwd = '"+data+"' where uID = '"+uID+"'";
            int count = stmt.executeUpdate(sql);
            if(count == 1)
                reviseSuccess = true;
        }catch(SQLException e){
            e.printStackTrace();
        }finally {
            DBUtil.close(conn, stmt, null);
        }

        return reviseSuccess;
    }
}
