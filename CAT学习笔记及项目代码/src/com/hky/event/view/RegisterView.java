package com.hky.event.view;

import com.hky.event.dao.Register;

import javax.swing.*;
import javax.swing.border.Border;
import javax.swing.border.TitledBorder;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class RegisterView {
    public RegisterView(){
        JFrame jf = new JFrame("注册");
        jf.setSize(500, 500);
        jf.setResizable(false);
        jf.setDefaultCloseOperation(jf.DISPOSE_ON_CLOSE);

        JPanel jp = new JPanel(new GridLayout(5, 1));
        JLabel jlb1 = new JLabel("昵称");
        JLabel jlb2 = new JLabel("账号");
        JLabel jlb3 = new JLabel("密码");
        JLabel jlb4 = new JLabel("再次确认密码");
        JTextField jtf1 = new JTextField(20);
        JTextField jtf2 = new JTextField(20);
        JPasswordField jpf1 = new JPasswordField(20);
        JPasswordField jpf2 = new JPasswordField(20);

        jp.setSize(400, 700);
        jlb1.setFont(new Font("楷体", Font.BOLD, 22));
        jlb2.setFont(new Font("楷体", Font.BOLD, 22));
        jlb3.setFont(new Font("楷体", Font.BOLD, 22));
        jlb4.setFont(new Font("楷体", Font.BOLD, 22));
        jtf1.setFont(new Font("宋体", Font.BOLD, 22));
        jtf1.setHorizontalAlignment(SwingConstants.CENTER);
        jtf2.setFont(new Font("宋体", Font.BOLD, 22));
        jtf2.setHorizontalAlignment(SwingConstants.CENTER);
        jpf1.setFont(new Font("宋体", Font.BOLD, 22));
        jpf1.setEchoChar('*');
        jpf1.setHorizontalAlignment(SwingConstants.CENTER);
        jpf2.setFont(new Font("宋体", Font.BOLD, 22));
        jpf2.setEchoChar('*');
        jpf2.setHorizontalAlignment(SwingConstants.CENTER);

        JPanel jp1 = createPanel("昵称");
        JPanel jp2 = createPanel("账号");
        JPanel jp3 = createPanel("密码");
        JPanel jp4 = createPanel("确认密码");
        JButton jbn = new JButton("注册");
        jbn.setSize(30, 10);

        jp1.add(jlb1);
        jp1.add(jtf1);
        jp2.add(jlb2);
        jp2.add(jtf2);
        jp3.add(jlb3);
        jp3.add(jpf1);
        jp4.add(jlb4);
        jp4.add(jpf2);

        jp.add(jp1);
        jp.add(jp2);
        jp.add(jp3);
        jp.add(jp4);
        jp.add(jbn);

        jbn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                boolean result =  new Register().register(jtf2.getText(), jpf1.getPassword(), jtf1.getText());
                if(true == result){
                    JOptionPane.showMessageDialog(jf, "注册成功",
                            "注册结果", JOptionPane.INFORMATION_MESSAGE);
                }
                else{
                    JOptionPane.showMessageDialog(jf, "用户已存在，注册失败",
                            "注册结果", JOptionPane.INFORMATION_MESSAGE);
                }
            }
        });

        jf.setContentPane(jp);
        jf.setLocationRelativeTo(null);
        jf.setVisible(true);
    }

    public static JPanel createPanel(String str){
        JPanel jp = new JPanel();

        Border border = BorderFactory.createLineBorder(Color.BLUE);
        jp.setBorder(BorderFactory.createTitledBorder(border, str, TitledBorder.CENTER,
                TitledBorder.TOP, new Font("行书", Font.PLAIN, 15), Color.GRAY));

        return jp;
    }
}
