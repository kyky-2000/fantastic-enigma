package com.hky.event.dao;

/*
    实现用户登录功能
 */
import java.sql.*;
import com.hky.event.util.DBUtil;

public class Login {
    public static boolean login(String loginName, char[] loginPwd){
        String pwd = new String(loginPwd);
        //标识是否登录成功
        boolean loginSuccess = false;
        //连接数据的基本操作
        Connection conn = null;
        PreparedStatement ps = null;
        ResultSet rs = null;
        try{
            //调用工具类，注册驱动并获取连接对象
            conn = DBUtil.getConnection();
            //获取数据库操作对象
            //常规情况下此处应该是  "select * from t_user where loginName = '"+loginName+"' and loginPwd = '"+loginPwd+"'"
            //但这么写会导致sql注入
            String sql = "select * from user where loginName = ? and loginPwd = ?";
            //预编译sql预计，？表示留空，不可加双引号
            //目的是防止sql注入
            ps = conn.prepareStatement(sql);
            ps.setString(1, loginName);
            ps.setString(2, pwd);
            //执行sql语句
            rs = ps.executeQuery();
            //处理查询结果集
            if( rs.next() ){
                loginSuccess = true;
            }
        }catch(Exception e){
            e.printStackTrace();
        }finally{
            //释放资源
            DBUtil.close(conn, ps, rs);
        }
        return loginSuccess;
    }
}


