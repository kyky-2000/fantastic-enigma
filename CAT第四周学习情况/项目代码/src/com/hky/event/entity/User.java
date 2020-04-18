package com.hky.event.entity;

public class User {
    private int uID;         //系统给用户的编号，用于对表操作时定位
    private String name;     //用户昵称，可自行修改
    private String loginName;//用户登录账号，不可修改
    private String password; //用户密码
    private double balance;  //用户余额
    private String status;   //身份（用户或管理员）

    public int getID(){
        return uID;
    }

    public void setID(int uID){
        this.uID = uID;
    }

    public String getName(){
        return name;
    }

    public void setName(String name){
        this.name = name;
    }

    public String getLoginName(){
        return loginName;
    }

    public void setLoginName(String loginName){
        this.loginName = loginName;
    }

    public String getPassword(){
        return password;
    }

    public void setPassword(String password){
        this.password = password;
    }

    public double getBalance(){
        return balance;
    }

    public void setBalance(double balance){
        this.balance = balance;
    }

    public String getStatus(){
        return status;
    }

    public void setStatus(String status){
        this.status = status;
    }
}
