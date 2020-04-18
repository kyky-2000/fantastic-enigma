package com.hky.event.dao;

import com.hky.event.entity.User;
import com.hky.event.util.DBUtil;

import java.sql.*;

public interface UserDao {
    /**
     *
     * @param loginName
     * @param loginPwd
     * @param status
     * @return
     */
    User login(String loginName, String loginPwd, String status);

    /**
     *
     * @param name
     * @param loginName
     * @param loginPassword
     * @return
     */
    boolean regist(String name, String loginName, String loginPassword);

    /**
     *
     * @param data
     * @param str
     * @param uID
     * @return
     */
    boolean reviseData(String data, String str, int uID);

    /**
     *
     * @param uID
     * @param amount
     * @return
     */
    boolean investment(int uID, int amount);
}