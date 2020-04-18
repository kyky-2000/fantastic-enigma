package com.hky.event.view;

import com.hky.event.controller.EventController;
import com.hky.event.controller.UserController;
import com.hky.event.entity.User;
import com.hky.event.entity.Event;

import javax.swing.*;
import javax.swing.border.Border;
import javax.swing.border.TitledBorder;
import javax.swing.table.DefaultTableCellRenderer;
import javax.swing.table.DefaultTableModel;
import javax.swing.table.TableColumn;
import javax.swing.table.TableModel;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.Vector;

public class UserMainView {

    private UserController userController = new UserController();
    private EventController eventController = new EventController();
    public User user;

    public UserMainView(User user){
        this.user = user;
        JFrame  jf = new JFrame("英雄联盟赛事购票系统");
        jf.setDefaultCloseOperation(jf.EXIT_ON_CLOSE);
        jf.setSize(1200, 800);
        jf.setResizable(false);

        JTabbedPane jtp = new JTabbedPane();
        JPanel jp = createPanel3();

        jtp.addTab("主页", createPanel());
        jtp.addTab("查询赛事", createPanel1());
        jtp.addTab("个人中心", createPanel2());
        jtp.addTab("充值", jp);
        jtp.setTabPlacement(JTabbedPane.LEFT);
        jtp.setTabLayoutPolicy(JTabbedPane.SCROLL_TAB_LAYOUT);// 滚动条
        jtp.setFont(new Font("宋体", Font.BOLD, 25));
        jtp.setSelectedIndex(0);

        jf.setContentPane(jtp);
        jf.setLocationRelativeTo(null);
        jf.setVisible(true);
    }

    public JPanel createPanel(){
        ArrayList<String> al = null;
        JPanel jp = new JPanel(new BorderLayout());

        JLabel jlb = new JLabel("赛事信息总览");
        jlb.setPreferredSize(new Dimension(400, 50));
        jlb.setFont(new Font("黑体", Font.BOLD, 40));
        jlb.setHorizontalAlignment(SwingConstants.CENTER);

        JTextArea jta = new JTextArea();
        jta.setFont(new Font("仿宋", Font.BOLD, 30));
        jta.setEditable(false);

        JScrollPane jsp = new JScrollPane(jta,
                ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS,
                ScrollPaneConstants.HORIZONTAL_SCROLLBAR_AS_NEEDED
        );

        al = eventController.showEvent();
        int len = al.size();

        for(int i=1; i<len-3; i+=4){
            jta.append("\r\n");
            for(int j=0; j<7; j++){
                jta.append("  ");
            }
            jta.append(al.get(i) + " : " + al.get(i+1) + "  VS  " +  al.get(i+2) + "\r\n");
        }

        jp.add(jlb, BorderLayout.NORTH);
        jp.add(jsp, BorderLayout.CENTER);

        return jp;
    }

    public JPanel createPanel1(){
        JPanel jp = new JPanel(new BorderLayout());
        JPanel jp1 = new JPanel(new GridLayout(2, 3));
        JPanel jp2 = new JPanel();

        JLabel jlb = new JLabel("请输入交战双方");
        jlb.setPreferredSize(new Dimension(200, 30));
        jlb.setFont(new Font("仿宋", Font.BOLD, 23));
        jlb.setHorizontalAlignment(SwingConstants.CENTER);

        JLabel jlb1 = new JLabel("主场");
        jlb1.setPreferredSize(new Dimension(60, 30));
        jlb1.setFont(new Font("仿宋", Font.BOLD, 21));
        jlb1.setHorizontalAlignment(SwingConstants.CENTER);
        JLabel jlb2 = new JLabel("客场");
        jlb2.setPreferredSize(new Dimension(60, 30));
        jlb2.setFont(new Font("仿宋", Font.BOLD, 21));
        jlb2.setHorizontalAlignment(SwingConstants.CENTER);

        JTextField jtf1 = new JTextField("");
        jtf1.setPreferredSize(new Dimension(100, 30));
        jtf1.setFont(new Font("仿宋", Font.BOLD, 21));
        jtf1.setHorizontalAlignment(SwingConstants.CENTER);
        JTextField jtf2 = new JTextField("");
        jtf2.setPreferredSize(new Dimension(100, 30));
        jtf2.setFont(new Font("仿宋", Font.BOLD, 21));
        jtf2.setHorizontalAlignment(SwingConstants.CENTER);

        JButton jbn = new JButton("查询");
        jbn.setFont(new Font("仿宋", Font.BOLD, 21));
        jbn.setPreferredSize(new Dimension(100, 30));

        DefaultTableModel tableModel = new DefaultTableModel();
        JTable jtable = new JTable(tableModel);
        JScrollPane jsp = new JScrollPane(jtable);
        DefaultTableCellRenderer r = new DefaultTableCellRenderer();
        r.setHorizontalAlignment(JLabel.CENTER);
        jtable.setDefaultRenderer(Object.class,r);

        jtable.setFillsViewportHeight(true);
        jtable.setRowSelectionAllowed(true);
        jtable.setRowHeight(30);
        jtable.setFont(new Font("仿宋", Font.BOLD, 21));

        tableModel.addColumn("赛事编号");
        tableModel.addColumn("时间");
        tableModel.addColumn("主场队");
        tableModel.addColumn("客场队");
        tableModel.addColumn("票价");

        TableColumn firsetColumn = jtable.getColumnModel().getColumn(1);
        firsetColumn.setPreferredWidth(150);
//        firsetColumn.setMaxWidth(30);
//        firsetColumn.setMinWidth(30);

        JButton jbn1 = new JButton("预订");
        jbn1.setFont(new Font("仿宋", Font.BOLD, 21));
        jbn1.setPreferredSize(new Dimension(100, 30));

        JButton jbn2 = new JButton("购买");
        jbn2.setFont(new Font("仿宋", Font.BOLD, 21));
        jbn2.setPreferredSize(new Dimension(100, 30));


        jbn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                tableModel.setRowCount(0);
                ArrayList<Event> events = null;
                events = eventController.searchEvent(jtf1.getText(), jtf2.getText());
                int len = events.size();
                if (len == 0) {
                    JOptionPane.showMessageDialog(jsp, "查无数据", "查询结果",
                            JOptionPane.INFORMATION_MESSAGE);
                    return;
                }

                for (int i = 0; i < len; i++) {
                    Vector<Object> rowdata = new Vector<>();
                    rowdata.add(events.get(i).getID());
                    rowdata.add(events.get(i).getDate());
                    rowdata.add(events.get(i).getBlue());
                    rowdata.add(events.get(i).getRed());
                    rowdata.add(events.get(i).getPrice());
                    tableModel.addRow(rowdata);
                }

            }
        });
        ActionListener actionListener = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String pattern = null;
                if(e.getSource() == jbn1){
                    pattern = "预订";
                }else{
                    pattern = "购买";
                }

                if(jtable.getSelectedColumn() == -1){
                    JOptionPane.showMessageDialog(jsp, "您未选中", "操作结果",
                            JOptionPane.ERROR_MESSAGE);
                    return;
                }

                int i = (Integer) tableModel.getValueAt(jtable.getSelectedRow(), 0);
                double d = (Double)tableModel.getValueAt(jtable.getSelectedRow(), 4);


                String result = eventController.buyTickets(i, user, pattern, d);
                if(result.equals("余额不足"))
                    JOptionPane.showMessageDialog(jp2, "余额不足，请及时充值", "操作结果",
                            JOptionPane.ERROR_MESSAGE);
                else if(result.equals(pattern+"成功"))
                    JOptionPane.showMessageDialog(jp2, pattern+"成功", "操作结果",
                            JOptionPane.INFORMATION_MESSAGE);
                else
                    JOptionPane.showMessageDialog(jp2, pattern+"失败", "操作结果",
                            JOptionPane.ERROR_MESSAGE);
            }
        };
        jbn1.addActionListener(actionListener);
        jbn2.addActionListener(actionListener);

        jp.add(jp1, BorderLayout.NORTH);
        jp.add(jsp, BorderLayout.CENTER);
        jp.add(jp2, BorderLayout.SOUTH);
        jp1.add(jlb1);
        jp1.add(jlb2);
        jp1.add(jlb);
        jp1.add(jtf1);
        jp1.add(jtf2);
        jp1.add(jbn);
        jp2.add(jbn1);
        jp2.add(jbn2);
        return jp;
    }

    public JPanel createPanel2(){
        JPanel jp = new JPanel(new GridLayout(3,1));
        JPanel jp1 = new JPanel(new GridLayout(2, 3));
        Border border = BorderFactory.createEmptyBorder(90, 70, 90, 130);
        jp1.setBorder(BorderFactory.createTitledBorder(border, "用户名", TitledBorder.LEFT, TitledBorder.TOP,
                new Font("宋体", Font.BOLD, 23), Color.BLACK));
        JLabel jlb1 = new JLabel("当前用户名：");
        jlb1.setFont(new Font("仿宋", Font.BOLD, 23));
        jlb1.setHorizontalAlignment(SwingConstants.CENTER);
        JTextField jtf4 = new JTextField(user.getName());
        jtf4.setFont(new Font("仿宋", Font.BOLD, 23));
        jtf4.setHorizontalAlignment(SwingConstants.CENTER);
        jtf4.setEditable(false);
        JLabel jlb3 = new JLabel("是否更改用户名");
        jlb3.setFont(new Font("仿宋", Font.BOLD, 23));
        jlb3.setHorizontalAlignment(SwingConstants.CENTER);
        JTextField jtf1 = new JTextField(12);
        jtf1.setFont(new Font("仿宋", Font.BOLD, 23));
        jtf1.setHorizontalAlignment(SwingConstants.CENTER);
        JButton jbn1 = new JButton("修改");
        jbn1.setFont(new Font("仿宋", Font.BOLD, 23));
        jbn1.setPreferredSize(new Dimension(80, 30));

        JPanel jp2 = new JPanel();
        jp2.setBorder(BorderFactory.createTitledBorder(border, "密码", TitledBorder.LEFT, TitledBorder.TOP,
                new Font("宋体", Font.BOLD, 23), Color.BLACK));
        JLabel jlb4 = new JLabel("修改密码：");
        jlb4.setFont(new Font("仿宋", Font.BOLD, 23));
        jlb4.setPreferredSize(new Dimension(250, 40));
        jlb4.setHorizontalAlignment(SwingConstants.CENTER);
        JButton jbn2 = new JButton("修改");
        jbn2.setFont(new Font("仿宋", Font.BOLD, 23));
        jbn2.setPreferredSize(new Dimension(110, 40));
        JPasswordField jpf = new JPasswordField();
        jpf.setFont(new Font("仿宋", Font.BOLD, 23));
        jpf.setEchoChar('*');
        jpf.setHorizontalAlignment(SwingConstants.CENTER);
        jpf.setPreferredSize(new Dimension(250, 40));

        JPanel jp3 = new JPanel();
        jp3.setBorder(BorderFactory.createEmptyBorder(150, 200, 150, 200));
        JScrollPane jsp = new JScrollPane(jp3, ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS,
                ScrollPaneConstants.HORIZONTAL_SCROLLBAR_AS_NEEDED);


        jbn1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(jtf1.getText().isEmpty()){
                    JOptionPane.showMessageDialog(jp3, "输入框不能为空",
                            "修改结果", JOptionPane.ERROR_MESSAGE);
                }else{
                    if(userController.reviseData(jtf1.getText(), "name"))
                        JOptionPane.showMessageDialog(jp1, "修改成功",
                                "修改结果", JOptionPane.INFORMATION_MESSAGE);
                    else
                        JOptionPane.showMessageDialog(jp3, "修改失败",
                                "修改结果", JOptionPane.ERROR_MESSAGE);
                }
            }
        });
        jbn2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String pwd = new String(jpf.getPassword());
                if(pwd.isEmpty()){
                    JOptionPane.showMessageDialog(jp3, "输入框不能为空",
                            "修改结果", JOptionPane.ERROR_MESSAGE);
                }else{
                    if(userController.reviseData(pwd, "loginPwd")) {
                        JOptionPane.showMessageDialog(jp3, "修改成功",
                                "修改结果", JOptionPane.INFORMATION_MESSAGE);
                    }
                    else
                        JOptionPane.showMessageDialog(jp3, "修改失败",
                                "修改结果", JOptionPane.ERROR_MESSAGE);
                }
            }
        });

        jp1.add(jlb1);
        jp1.add(jtf4);
        jp1.add(Box.createHorizontalStrut(100));
        jp1.add(jlb3);
        jp1.add(jtf1);
        jp1.add(jbn1);


        jp2.add(jlb4);
        jp2.add(jpf);
        jp2.add(jbn2);

        jp.add(jp1);
        jp.add(jp2);
        jp.add(jp3);
        return jp;
    }
    public JPanel createPanel3(){
        JPanel jp = new JPanel(new GridLayout(8, 1));
        jp.setBorder(BorderFactory.createEmptyBorder(90, 300, 150, 300));
        JLabel jlb = new JLabel("您当前的余额为");
        jlb.setFont(new Font("仿宋", Font.BOLD, 23));
        jlb.setPreferredSize(new Dimension(250, 40));
        jlb.setHorizontalAlignment(SwingConstants.CENTER);
        JTextField jtf = new JTextField(12);
        jtf.setFont(new Font("仿宋", Font.BOLD, 23));
        jtf.setHorizontalAlignment(SwingConstants.CENTER);
        jtf.setText(user.getBalance()+"");
        jtf.setEditable(false);
        JLabel jlb1 = new JLabel("您当前的余额低于100，为避免影响使用，请及时充值");
        jlb1.setFont(new Font("仿宋", Font.BOLD, 21));
        jlb1.setForeground(Color.red);
        jlb1.setPreferredSize(new Dimension(550, 40));
        jlb1.setHorizontalAlignment(SwingConstants.CENTER);
        JButton jbn = new JButton("充值");
        jbn.setFont(new Font("仿宋", Font.BOLD, 23));
        jbn.setPreferredSize(new Dimension(110, 40));

        Integer[] integer = new Integer[]{100, 200, 500, 1000};
        jbn.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                Integer it = (Integer)JOptionPane.showInputDialog(jp, "请选择要充值的数额：", "充值",
                        JOptionPane.PLAIN_MESSAGE, null, integer, integer[0]);
                int amount = it.intValue();
                if(userController.investment(user, amount)){
                    JOptionPane.showMessageDialog(jp, "充值成功",
                            "修改结果", JOptionPane.INFORMATION_MESSAGE);
                }
                else
                    JOptionPane.showMessageDialog(jp, "充值失败",
                            "修改结果", JOptionPane.ERROR_MESSAGE);
            }
        });

        jp.add(jlb);
        jp.add(jtf);
        if(user.getBalance()<100)
            jp.add(jlb1);
        jp.add(jbn);
        return jp;
    }

}
