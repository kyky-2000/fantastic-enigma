package com.hky.event.view;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import com.hky.event.dao.Login;

public class LoginView {
    public LoginView(){
        JFrame jf = new JFrame("登录");
        jf.setDefaultCloseOperation(jf.EXIT_ON_CLOSE);
        jf.setResizable(false);
        jf.setSize(800, 500);

        JPanel jp = new JPanel(null);
        //JPanel jp2 = new JPanel(null);
        JLabel jlb1 = new JLabel();
        JLabel jlb2 = new JLabel("账号");
        JTextField jtf = new JTextField();
        JLabel jlb3 = new JLabel("密码");
        JPasswordField jpf = new JPasswordField();
        Box hBox1 = Box.createHorizontalBox();
        Box hBox2 = Box.createHorizontalBox();
        JButton jbn1 = new JButton("登录");
        JButton jbn2 = new JButton("注册");
        JLabel jlb4 = new JLabel("登录身份");
        String[] identity = new String[]{"管理员", "用户"};
        JComboBox<String> jcb = new JComboBox<String>(identity);


        //jp2.setBounds(300, 100, 350, 200);
        jlb1.setIcon(new ImageIcon("Source//picture1.jpg"));
        jlb1.setBounds(50, 130, 250, 150);
        jlb2.setFont(new Font("楷体", Font.BOLD, 23));
        jlb3.setFont(new Font("楷体", Font.BOLD, 23));
        jlb4.setFont(new Font("楷体", Font.BOLD, 20));
        jtf.setFont(new Font("楷体", Font.BOLD, 18));
        jpf.setFont(new Font("楷体", Font.BOLD, 18));
        jtf.setHorizontalAlignment(SwingConstants.CENTER);
        jpf.setEchoChar('*');
        jpf.setHorizontalAlignment(SwingConstants.CENTER);
        jbn1.setBounds(450, 300, 80, 50);
        jbn2.setBounds(550, 300, 80, 50);
        jlb4.setBounds(555, 10, 100, 50);
        jcb.setBounds(550, 60, 100, 30);

        jbn1.addActionListener(new ActionListener(){ //查看鼠标是否有在选项上的监听
            @Override
            public void actionPerformed(ActionEvent e){
                String userName = jtf.getText();
                char[] userPwd = jpf.getPassword();
                if(Login.login(userName, userPwd))
                    System.out.println("登录成功");
                else
                    //系统给的可直接用的弹窗，还有可以输入信息的框和确认框
                    JOptionPane.showMessageDialog(jf, "账户或密码错误，登录失败",
                            "登录结果", JOptionPane.ERROR_MESSAGE);//最后一个是消息类型
            }
        });
        jbn2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new RegisterView();
            }
        });

        jp.add(hBox1);
        hBox1.setBounds(350, 160, 350, 40);
        hBox1.add(jlb2);
        hBox1.add(jtf);
        jp.add(hBox2);
        hBox2.setBounds(350, 220, 350, 40);
        hBox2.add(jlb3);
        hBox2.add(jpf);
        jp.add(jbn1);
        jp.add(jbn2);
        jp.add(jlb4);
        jp.add(jcb);

        jp.add(jlb1);
        jf.setLocationRelativeTo(null);
        jf.setContentPane(jp);
        jf.setVisible(true);
    }

}
