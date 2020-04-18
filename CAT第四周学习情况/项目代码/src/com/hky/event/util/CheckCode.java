package com.hky.event.util;

import javax.swing.*;
import java.awt.*;
import java.util.Random;

public class CheckCode extends JFrame {
    private static Random random = new Random();
    private int width = 53;//验证码宽度
    private int height = 25;//验证码高度
    private int font_size = 20;//验证码颜色
    private int x = 5;//验证码所在窗体X坐标
    private int y = 11;//验证码所在窗体Y坐标
    private int jam = 5;//干扰元素 建议使用 4~7 之间的数字
    private String code = "";//保存验证码
    public String session = "";

//    public CheckCode() {//初始化窗体信息
//        super("验证码");
//        setVisible(true);
//        setBounds((Toolkit.getDefaultToolkit().getScreenSize().width - 300) / 2, (Toolkit.getDefaultToolkit().getScreenSize().height - 300) / 2, 300, 200);
//        setDefaultCloseOperation(EXIT_ON_CLOSE);
//        addMouseListener(new MouseAdapter() {
//            public void mouseClicked(MouseEvent e) {
//                repaint();
//            }
//        });
//
//
//    }

    public Color getRandomColor() {//获得随机颜色
        int R = random.nextInt(255), G = random.nextInt(255), B = random.nextInt(255);
        return new Color(R, G, B);
    }

    public String getRandomString() {//获得验证码
        int num = random.nextInt(9);
        code = num + "";
        return num + "";
    }

    public void checkCode(Graphics g) {// 绘画验证码
        drawBorder(g);
        drawCode(g);
        drawJam(g);
    }

    public void drawBorder(Graphics g) {//绘画边框和背景
        Color gc = g.getColor();
        g.setColor(Color.WHITE);
        g.fillRect(x, y, width, height);
        g.setColor(Color.BLACK);
        g.drawRect(x, y, width, height);
        g.setColor(gc);
    }

    public void drawCode(Graphics g) {//绘画验证码内容
        Color gc = g.getColor();
        for (int i = 0; i < 4; i++) {
            String ss = getRandomString();
            g.setColor(getRandomColor());
            g.setFont(new Font("宋体", Font.BOLD, font_size));
            g.drawString(ss, x + 5 + (i * 12), y + font_size);
            session = session + ss;
        }
        g.setColor(gc);
    }

    public void drawJam(Graphics g) {//绘画干扰元素
        Color gc = g.getColor();
        for (int i = 0; i < jam; i++) {
            g.setColor(getRandomColor());
            g.drawLine(x + random.nextInt(width), y + random.nextInt(height), x + random.nextInt(width), y + random.nextInt(height));
        }
        g.setColor(gc);
    }

//    public void paint(Graphics g) {
//        Color c = g.getColor();
//        g.drawString("输入密码错误多次，请进行验证后重试", 35, 50);
//        checkCode(g);
//        g.setColor(c);
//    }

//    public static void main(String[] args) {
//        new CheckCode();
//
//    }
}

