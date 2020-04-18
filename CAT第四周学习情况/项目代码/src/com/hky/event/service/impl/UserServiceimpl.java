package com.hky.event.service.impl;

import com.hky.event.dao.UserDao;
import com.hky.event.dao.impl.UserDaoimpl;
import com.hky.event.entity.User;
import com.hky.event.service.UserService;

public class UserServiceimpl implements UserService {

    private UserDao userDao = new UserDaoimpl();
    public User user = null;

    public int login(String loginName, String loginPwd, int statusCode){

        String status = null;
        if(statusCode == 0){
            status = "manager";
        }else{
            status = "user";
        }

        user = userDao.login(loginName, loginPwd, status);

        if(user == null){
            return 0;
        }else{
            if(user.getStatus().equals("user")) {
                return 1;
            }
            else
                return 2;
        }
    }

    public boolean regist(String name, String loginName, char[] loginPwd){
        String pwd = new String(loginPwd);
        return userDao.regist(name, loginName, pwd);
    }

    public User getUser(){
        return user;
    }

    public boolean investment(User user, int amount){
        user.setBalance(user.getBalance() + amount);
        return userDao.investment(user.getID(), amount);
    }

    public boolean reviseData(String data, String str){
        return userDao.reviseData(data, str, user.getID());
    }
}
