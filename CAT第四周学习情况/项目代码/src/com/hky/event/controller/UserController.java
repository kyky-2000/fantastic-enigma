package com.hky.event.controller;

import com.hky.event.entity.User;
import com.hky.event.service.UserService;
import com.hky.event.service.impl.UserServiceimpl;

public class UserController {
    private UserService userService = new UserServiceimpl();

    public int login(String loginName, String loginPwd, int statusCode){
        return userService.login(loginName, loginPwd, statusCode);
    }

    public boolean regist(String name, String loginName, char[] loginPwd){
        return userService.regist(name, loginName, loginPwd);
    }

    public User getUser(){
        return userService.getUser();
    }

    public boolean investment(User user, int amount){
        return userService.investment(user, amount);
    }

    public boolean reviseData(String data, String str){
        return userService.reviseData(data, str);
    }
}
