package com.hky.event.view;

import com.hky.event.controller.EventController;
import com.hky.event.controller.UserController;
import com.hky.event.entity.User;

import javax.swing.*;
import javax.swing.border.Border;
import javax.swing.border.TitledBorder;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ManagerView {

    private EventController eventController = new EventController();
    private UserController userController = new UserController();
    public User user;

    public ManagerView(User user){
        this.user = user;
        JFrame jf = new JFrame("管理员界面");
        jf.setDefaultCloseOperation(jf.EXIT_ON_CLOSE);
        jf.setSize(1500, 800);
        jf.setResizable(false);

        JTabbedPane jtp = new JTabbedPane();
        JPanel jp = new UserMainView(user).createPanel();

        jtp.addTab("主页", jp);
        jtp.addTab("赛事管理", createPanel1());
        jtp.addTab("订票信息管理", createPanel2());
        jtp.addTab("用户余额", createPanel3());
        jtp.setTabPlacement(JTabbedPane.LEFT);
        jtp.setTabLayoutPolicy(JTabbedPane.SCROLL_TAB_LAYOUT);// 滚动条
        jtp.setFont(new Font("宋体", Font.BOLD, 22));
        jtp.setSelectedIndex(0);


        jf.setContentPane(jtp);
        jf.setLocationRelativeTo(null);
        jf.setVisible(true);
    }
    public JPanel createPanel1(){
        JPanel jp = new JPanel(new GridLayout(3, 1));
        JPanel jp1 = createPanel11();
        JPanel jp2 = createPanel12();
        JPanel jp3 = new JPanel();
        Border border = BorderFactory.createEmptyBorder(70, 30, 70, 30);
        jp3.setBorder(BorderFactory.createTitledBorder(border, "删除赛事", TitledBorder.CENTER,
                TitledBorder.TOP, new Font("楷体", Font.BOLD, 30), Color.BLUE));

        JLabel jlb = new JLabel("请输入要删除的赛事的编号");
        jlb.setFont(new Font("仿宋", Font.BOLD, 23));
        jlb.setHorizontalAlignment(SwingConstants.CENTER);
        JTextField jtf = new JTextField(12);
        jtf.setFont(new Font("仿宋", Font.BOLD, 23));
        jtf.setHorizontalAlignment(SwingConstants.CENTER);
        JButton jbn = new JButton("删除");
        jbn.setFont(new Font("仿宋", Font.BOLD, 23));
        jbn.setPreferredSize(new Dimension(100, 40));

        jbn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                boolean result = eventController.deleteEvent(jtf.getText());
                if(result == true)
                    JOptionPane.showMessageDialog(jp2, "删除成功", "操作结果",
                            JOptionPane.INFORMATION_MESSAGE);
                else
                    JOptionPane.showMessageDialog(jp2, "删除失败", "操作结果",
                            JOptionPane.ERROR_MESSAGE);
            }
        });

        jp3.add(jlb);
        jp3.add(jtf);
        jp3.add(jbn);

        jp.add(jp1);
        jp.add(jp2);
        jp.add(jp3);
        return jp;
    }
    public JPanel createPanel11(){
        JPanel jp1 = new JPanel(new GridLayout(2, 5));
        Border border = BorderFactory.createEmptyBorder(70, 30, 70, 30);
        jp1.setBorder(BorderFactory.createTitledBorder(border, "增添新赛事", TitledBorder.CENTER,
                TitledBorder.TOP, new Font("楷体", Font.BOLD, 30), Color.BLUE));

        JLabel jlb11 = new JLabel("时间");
        jlb11.setFont(new Font("仿宋", Font.BOLD, 21));
        jlb11.setHorizontalAlignment(SwingConstants.CENTER);
        JLabel jlb12 = new JLabel("主场队");
        jlb12.setFont(new Font("仿宋", Font.BOLD, 21));
        jlb12.setHorizontalAlignment(SwingConstants.CENTER);
        JLabel jlb13 = new JLabel("客场队");
        jlb13.setFont(new Font("仿宋", Font.BOLD, 21));
        jlb13.setHorizontalAlignment(SwingConstants.CENTER);
        JLabel jlb14 = new JLabel("票价");
        jlb14.setFont(new Font("仿宋", Font.BOLD, 21));
        jlb14.setHorizontalAlignment(SwingConstants.CENTER);
        JLabel jlb15 = new JLabel("增添赛事");
        jlb15.setFont(new Font("黑体", Font.BOLD, 25));
        jlb15.setHorizontalAlignment(SwingConstants.CENTER);
        JButton jbn11 = new JButton("确认");
        jbn11.setFont(new Font("仿宋", Font.BOLD, 21));
        JTextField jtf11 = new JTextField();
        jtf11.setFont(new Font("仿宋", Font.BOLD, 21));
        jtf11.setHorizontalAlignment(SwingConstants.CENTER);
        JTextField jtf12 = new JTextField();
        jtf12.setFont(new Font("仿宋", Font.BOLD, 21));
        jtf12.setHorizontalAlignment(SwingConstants.CENTER);
        JTextField jtf13 = new JTextField();
        jtf13.setFont(new Font("仿宋", Font.BOLD, 21));
        jtf13.setHorizontalAlignment(SwingConstants.CENTER);
        JTextField jtf14 = new JTextField();
        jtf14.setFont(new Font("仿宋", Font.BOLD, 21));
        jtf14.setHorizontalAlignment(SwingConstants.CENTER);

        jbn11.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                boolean result = eventController.addEvent(jtf11.getText(), jtf12.getText(),
                        jtf13.getText(), jtf14.getText());
                if(result == true)
                    JOptionPane.showMessageDialog(jp1, "添加成功", "操作结果",
                            JOptionPane.INFORMATION_MESSAGE);
                else
                    JOptionPane.showMessageDialog(jp1, "添加失败", "操作结果",
                            JOptionPane.ERROR_MESSAGE);
            }
        });

        jp1.add(jlb11);
        jp1.add(jlb12);
        jp1.add(jlb13);
        jp1.add(jlb14);
        jp1.add(jlb15);
        jp1.add(jtf11);
        jp1.add(jtf12);
        jp1.add(jtf13);
        jp1.add(jtf14);
        jp1.add(jbn11);

        return jp1;

    }
    public JPanel createPanel12(){
        JPanel jp2 = new JPanel(new GridLayout(3, 5));
        Border border = BorderFactory.createEmptyBorder(33, 10, 33, 10);
        jp2.setBorder(BorderFactory.createTitledBorder(border, "修改赛事信息", TitledBorder.CENTER,
                TitledBorder.TOP, new Font("楷体", Font.BOLD, 30), Color.BLUE));

        JLabel jlb21 = new JLabel("时间");
        jlb21.setFont(new Font("仿宋", Font.BOLD, 21));
        jlb21.setHorizontalAlignment(SwingConstants.CENTER);
        JLabel jlb22 = new JLabel("主场队");
        jlb22.setFont(new Font("仿宋", Font.BOLD, 21));
        jlb22.setHorizontalAlignment(SwingConstants.CENTER);
        JLabel jlb23 = new JLabel("客场队");
        jlb23.setFont(new Font("仿宋", Font.BOLD, 21));
        jlb23.setHorizontalAlignment(SwingConstants.CENTER);
        JLabel jlb24 = new JLabel("票价");
        jlb24.setFont(new Font("仿宋", Font.BOLD, 21));
        jlb24.setHorizontalAlignment(SwingConstants.CENTER);
        JLabel jlb25 = new JLabel("要更改的赛事的编号");
        jlb25.setFont(new Font("仿宋", Font.BOLD, 21));
        jlb25.setHorizontalAlignment(SwingConstants.CENTER);

        JTextField jtf21 = new JTextField();
        jtf21.setFont(new Font("仿宋", Font.BOLD, 21));
        jtf21.setHorizontalAlignment(SwingConstants.CENTER);
        JTextField jtf22 = new JTextField();
        jtf22.setFont(new Font("仿宋", Font.BOLD, 21));
        jtf22.setHorizontalAlignment(SwingConstants.CENTER);
        JTextField jtf23 = new JTextField();
        jtf23.setFont(new Font("仿宋", Font.BOLD, 21));
        jtf23.setHorizontalAlignment(SwingConstants.CENTER);
        JTextField jtf24 = new JTextField();
        jtf24.setFont(new Font("仿宋", Font.BOLD, 21));
        jtf24.setHorizontalAlignment(SwingConstants.CENTER);
        JTextField jtf25 = new JTextField();
        jtf25.setFont(new Font("仿宋", Font.BOLD, 21));
        jtf25.setHorizontalAlignment(SwingConstants.CENTER);

        JButton jbn21 = new JButton("修改时间");
        jbn21.setFont(new Font("仿宋", Font.BOLD, 21));
        JButton jbn22 = new JButton("修改主场队");
        jbn22.setFont(new Font("仿宋", Font.BOLD, 21));
        JButton jbn23 = new JButton("修改客场队");
        jbn23.setFont(new Font("仿宋", Font.BOLD, 21));
        JButton jbn24 = new JButton("修改票价");
        jbn24.setFont(new Font("仿宋", Font.BOLD, 21));

        ActionListener al = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e){
                Object ob = e.getSource();
                String eID = jtf25.getText();
                String name = null;
                String change = null;

                if(ob == jbn21){
                    name = "eDate";
                    change = jtf21.getText();
                }else if(ob == jbn22){
                    name = "blue";
                    change = jtf22.getText();
                }else if(ob == jbn23){
                    name = "red";
                    change = jtf23.getText();
                }else{
                    name = "price";
                    change = jtf24.getText();
                }

                boolean result = eventController.updateEvent(eID, change, name);
                if(result == true)
                    JOptionPane.showMessageDialog(jp2, "修改成功", "操作结果",
                            JOptionPane.INFORMATION_MESSAGE);
                else
                    JOptionPane.showMessageDialog(jp2, "修改失败", "操作结果",
                            JOptionPane.ERROR_MESSAGE);

            }
        };
        jbn21.addActionListener(al);
        jbn22.addActionListener(al);
        jbn23.addActionListener(al);
        jbn24.addActionListener(al);

        jp2.add(jlb25);
        jp2.add(jlb21);
        jp2.add(jlb22);
        jp2.add(jlb23);
        jp2.add(jlb24);
        jp2.add(jtf25);
        jp2.add(jtf21);
        jp2.add(jtf22);
        jp2.add(jtf23);
        jp2.add(jtf24);
        jp2.add(Box.createHorizontalStrut(80));
        jp2.add(jbn21);
        jp2.add(jbn22);
        jp2.add(jbn23);
        jp2.add(jbn24);

        return jp2;
    }

    public JPanel createPanel2(){
        JPanel jp = new JPanel();

        return jp;
    }
    public JPanel createPanel3(){
        JPanel jp = new JPanel();

        return jp;
    }
}
