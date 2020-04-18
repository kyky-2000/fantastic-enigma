package com.hky.event.util;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Properties;

public class HandleData {
    public static String key = "hkyabcdhky";
    public static void inputData(String loginName, String loginPwd){
        String encodePwd = DESUtils2.encode(key, loginPwd);
        Properties prop = new Properties();

        try{
            prop.setProperty("loginName", loginName);
            prop.setProperty("loginPwd", encodePwd);
            prop.store(new FileOutputStream("code.properties"), "code配置");

        }catch(IOException e){
            e.printStackTrace();
        }

    }
    public static ArrayList<String> outputData(){
        Properties prop = new Properties();
        ArrayList<String> al = new ArrayList<String>();
        File file = new File("code.properties");
        if(!file.exists()){
            return null;
        }
        try{
            prop.load(new FileInputStream("code.properties"));
            String loginName = prop.getProperty("loginName");
            String encodePwd = prop.getProperty("loginPwd");
            String loginPwd = DESUtils2.decode(key, encodePwd);
            al.add(loginName);
            al.add(loginPwd);

        }catch(IOException e){
            e.printStackTrace();
        }
        return al;
    }
}
