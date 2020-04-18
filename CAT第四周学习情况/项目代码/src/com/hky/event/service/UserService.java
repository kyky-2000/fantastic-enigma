package com.hky.event.service;

import com.hky.event.dao.UserDao;
import com.hky.event.dao.impl.UserDaoimpl;
import com.hky.event.entity.User;

public interface UserService {

    /**
     *
     * @param loginName
     * @param loginPwd
     * @param statusCode
     * @return
     */
   int login(String loginName, String loginPwd, int statusCode);

    /**
     *
      * @param name
     * @param loginName
     * @param loginPwd
     * @return
     */
   boolean regist(String name, String loginName, char[] loginPwd);

    /**
     *
      * @return
     */
   User getUser();

    /**
     *
      * @param amount
     * @return
     */
   boolean investment(User user, int amount);

    /**
     *
      * @param data
     * @param str
     * @return
     */
   boolean reviseData(String data, String str);
}
