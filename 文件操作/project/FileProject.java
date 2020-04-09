package com.myproject.Test;

import java.io.*;
import java.util.Properties;
import java.util.Scanner;
import java.sql.*;
import java.lang.*;

public class FileProject{
    public static void main(String[] args) {
        String str = writeFile();//原本想稍微缩减放在主函数的东西，好像缩得太少了
        //if(str != null)
        //    searchCode(str);
    }
    public static String writeFile() {
        Scanner s = new Scanner(System.in);
        int len = -1;
        int i = 1;
        String str = null;
        String f = null;
        String dir = null;
        File file = null;
        //RandomAccessFile rf = null;

        System.out.println("请输入文件目录:");//目录和文件不存在要用两个方法来创建，所以让用户分开输入
        dir = s.nextLine();
        file = new File(dir);
        if(file.mkdirs())
            System.out.println("目录不存在，已为您创建");

        try {
            System.out.print("请输入要写入的文件名:"); //IO操作好多抛异常，所以一起放try里面
            f = s.nextLine();
            file = new File(dir + "//" +  f);//目录创建好之后连上用户输入的文件名，在该目录下创建文件
            if(!file.exists()){
                file.createNewFile();
            }
            System.out.print("请输入要插入数据的行数：");
            try {
                len = s.nextInt();         //判断用户是否正确输入行数
                if(len < 0){
                    throw new Exception();
                }
            } catch (Exception e) {
                System.out.println("请输入正确的行数");
                return null;
            }

            System.out.print("请输入要输入文件的字符串:");
            s.nextLine();
            str = s.nextLine();

            //以循环加newLine的方式写入，是在文件内容后开始算行数，不可行
//            BufferedWriter bw = null;
//            bw = new BufferedWriter(new FileWriter(file, true));
//
//            if(!file.exists()){
//                file.createNewFile();
//            }
//            while ( len >= 0){    //用循环将文件指针移动到用户指定的行
//                if (i == len) {
//                    bw.write(str);
//                    break;
//                }
//                bw.newLine();
//                i++;
//            }

            RandomAccessFile rf = null;
            //String str1 = new String(toAppend.getBytes('UTF-8'), 'ISO8859-1');//出错了，不明原因

            rf = new RandomAccessFile(file, "rw");
            rf.seek((len-1)*1025);

            //rf.getChannel().write(sb);//字符串缓冲区无法赋给字节缓冲区

            //rf.writeUTF(str);//字符前总是多一个符号

            rf.write(str.getBytes());

            rf.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return str;
    }
    public static void searchCode(String str){
        Scanner s = new Scanner(System.in);
        Connection conn = null;
        Statement stmt = null;
        ResultSet rs = null;
        try{
            Properties prop=new Properties();
            prop.load(new FileInputStream("jdbc.properties"));
//            ResourceBundle  bundle = ResourceBundle.getBundle("jdbc");//不知为什么找不到文件

            String driver = prop.getProperty("driver");
            Class.forName(driver);
            String url = prop.getProperty("url");
            String user = prop.getProperty("user");
            String password = prop.getProperty("password");

            //            Class.forName("com.mysql.jdbc.Driver"); //不用配置文件
//            String url = "jdbc:mysql://localhost:3306/test";
//            String user = "root";
//            String password = "369";

            conn = DriverManager.getConnection(url, user, password);
            stmt = conn.createStatement();
            String sql = "insert into LoginCode(code) value('"+str+"')";
            String sql1 = "select * from LoginCode";
            int count = stmt.executeUpdate(sql);
            rs = stmt.executeQuery(sql1);
            if(count == 1)
                System.out.println("数据已传入库");

            System.out.println("按Y可查询输入记录：");
            char ch = s.next().charAt(0);
            if('Y'==ch || 'y'==ch){
                while(rs.next()){
                    String code = rs.getString("code");
                    System.out.println(code);
                }
            }

        }catch(Exception e){
            e.printStackTrace();
        }finally{
            if(rs != null)
                try{
                    rs.close();
                }catch(SQLException e){
                    e.printStackTrace();
                }
            if(stmt != null)
                try{
                    stmt.close();
                }catch(SQLException e){
                    e.printStackTrace();
                }
            if(conn != null)
                try{
                    conn.close();
                }catch(SQLException e){
                    e.printStackTrace();
                }
        }
    }
}
