package cn.itcast.dao;

import cn.itcast.domain.User;
import cn.itcast.util.JDBCUtils;
import org.springframework.dao.DataAccessException;
import org.springframework.jdbc.core.BeanPropertyRowMapper;
import org.springframework.jdbc.core.JdbcTemplate;

import java.nio.channels.ClosedSelectorException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

/**
 * 操作数据库user表的类
 */
public class UserDao {

    //声明JDBCTemplate对象共用
    private JdbcTemplate template = new JdbcTemplate(JDBCUtils.getDataSource());

    /**
     * 登录方法
     */
    public User login(User loginUser){
        try {
            String sql = "select * from user where username = ? and password = ?";

            User user = template.queryForObject(sql, new BeanPropertyRowMapper<User>(User.class),
                    loginUser.getUsername(), loginUser.getPassword());

            return user;
        } catch (DataAccessException e) {
            e.printStackTrace();
            return null;
        }
    }

    /**
     *注册方法
     */
    public boolean register(User user){
        boolean registerSuccess = false;
        Statement stmt = null;
        int count = 0;
        try {
            Class.forName("com.mysql.jdbc.Driver");
            Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/servlet",
                    "root", "369");
            String sql = "insert into user(username, password) value('"+user.getUsername()+"', '"+user.getPassword()+"')";
            stmt = conn.createStatement();
            count = stmt.executeUpdate(sql);
            if(count == 1){
                registerSuccess = true;
            }

        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }catch(SQLException e){
            e.printStackTrace();
        }
        return registerSuccess;
    }
}
