package com.hky.event.view;

import com.hky.event.controller.UserController;
import com.hky.event.entity.User;
import com.hky.event.util.CheckCode;
import com.hky.event.util.HandleData;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.ArrayList;

public class LoginView {
    private static int number = 1;
    private UserController userController = new UserController();

    public LoginView(){
        JFrame jf = new JFrame("登录");
        jf.setDefaultCloseOperation(jf.EXIT_ON_CLOSE);
        jf.setResizable(false);
        jf.setSize(800, 500);

        JPanel jp = new JPanel(null);
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
        jcb.setSelectedIndex(1);
        JRadioButton jrb = new JRadioButton("记住密码");
        jrb.setSelected(true);

        jlb1.setIcon(new ImageIcon("Source//picture1.jpg"));
        jlb1.setBounds(50, 130, 250, 150);
        jlb2.setFont(new Font("楷体", Font.BOLD, 23));
        jlb3.setFont(new Font("楷体", Font.BOLD, 23));
        jlb4.setFont(new Font("楷体", Font.BOLD, 20));
        jtf.setFont(new Font("楷体", Font.BOLD, 18));
        jpf.setFont(new Font("楷体", Font.BOLD, 18));
        jrb.setFont(new Font("楷体", Font.BOLD, 20));
        jtf.setHorizontalAlignment(SwingConstants.CENTER);
        jpf.setEchoChar('*');
        jpf.setHorizontalAlignment(SwingConstants.CENTER);
        jbn1.setBounds(440, 320, 100, 50);
        jbn2.setBounds(570, 320, 100, 50);
        jlb4.setBounds(555, 10, 100, 50);
        jcb.setBounds(550, 60, 100, 30);
        jrb.setBounds(440, 260, 150, 50);

        jp.add(hBox1);
        hBox1.setBounds(350, 160, 350, 40);
        hBox1.add(jlb2);
        hBox1.add(jtf);
        jp.add(hBox2);
        hBox2.setBounds(350, 210, 350, 40);
        hBox2.add(jlb3);
        hBox2.add(jpf);

        ArrayList<String> al = HandleData.outputData();
        if(al != null) {
            jtf.setText(al.get(0));
            jpf.setText(al.get(1));
        }
        jbn1.addActionListener(new ActionListener(){ //查看鼠标是否有在选项上的监听
            @Override
            public void actionPerformed(ActionEvent e){
                if(number > 3){
                    checkCode(jf);
                    return;
                }
                String userName = jtf.getText();
                int statusCode = jcb.getSelectedIndex();
                String userPwd = new String(jpf.getPassword());

                int result = userController.login(userName, userPwd, statusCode);
                User user = userController.getUser();

                if(result != 0) {
                    if (result == 1) {
                        if(jrb.isSelected()){
                            HandleData.inputData(userName, new String(userPwd));
                        }
                        new UserMainView(user);
                    }
                    else
                        new ManagerView(user);
                }
                else {
                    number++;
                    //系统给的可直接用的弹窗，还有可以输入信息的框和确认框
                    JOptionPane.showMessageDialog(jf, "账户或密码错误，登录失败",
                            "登录结果", JOptionPane.ERROR_MESSAGE);//最后一个是消息类型
                }
            }
        });
        jbn2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new RegisterView();
            }
        });

        jp.add(jbn1);
        jp.add(jbn2);
        jp.add(jlb4);
        jp.add(jcb);
        jp.add(jrb);

        jp.add(jlb1);
        jf.setLocationRelativeTo(null);
        jf.setContentPane(jp);
        jf.setVisible(true);
    }
    public void checkCode(JFrame jf){
        JDialog jd = new JDialog(jf, "验证", true);
        jd.setSize(320, 150);

        JPanel jp = new JPanel();
        JLabel jlb = new JLabel("请输入验证码");
        JTextField jtf = new JTextField();
        CheckCode cc = new CheckCode();
        jp.setPreferredSize(new Dimension(200, 100));
        jlb.setPreferredSize(new Dimension(85, 30));
        jtf.setPreferredSize(new Dimension(70, 30));
        JButton jbn = new JButton("确定");
        JLabel jlabel = new JLabel(){
            public void paint(Graphics g) {
                Color c = g.getColor();
                //g.drawString("输入密码错误多次，请进行验证后重试", 35, 50);
                cc.checkCode(g);
                g.setColor(c);
            }
        };
        jlabel.setPreferredSize(new Dimension(70, 50));
        jlabel.addMouseListener(new MouseAdapter() {
            public void mouseClicked(MouseEvent e) {
                jlabel.repaint();
            }
        });

        jbn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println(cc.session);
                System.out.println(cc.session.substring(4, 8));
                if(jtf.getText().equals(cc.session.substring(4, 8))){
                    number = 3;
                }
                jd.dispose();
            }
        });

        jp.add(jlb);
        jp.add(jtf);
        jp.add(jlabel);
        jp.add(jbn);
        jd.setLocationRelativeTo(jf);
        jd.setContentPane(jp);
        jd.setVisible(true);
    }


}
