# swing

## JFrame

***用法大致与Frame差不多***

**import java.awt.Color;**

**import java.awt.Container;**

**import java.swing.*;**

*新增 ：*

```java
JFrame f = new JFrame("...");
f.setResizable(false);//设置窗体是否可以改变大小，默认是true
f.getx();
f.gety();
f.setBounds(  ,  ,  ,  );
f.setLocationRelativeTo(null);//设置其中的组件居中，要先设置大小
/*	点关闭建键的效果
  EXIT_ON_CLOSE 停止程序
  DO_NOTHING_ON_CLOSE 无任何操作
  DISPOSE_ON_CLOSE释放窗体资源
*/
f.setDefaultCloseOperation(JFrame.HIDE_ON_CLOSE) //隐藏窗体，但不关闭
//获取窗体容器
Container c = f.getContentPane();
//对容器进行操作
c.setBackground(Color.WHITE);//或其他颜色
JLabel l = new JLabel("文本内容");//标签
c.add(l);//添加
c.remove(l);//删除
c.validate();//验证容器的组件，刷新的效果
c.setContenPane(c);//重新载入容器

//开发过程中的写法
public class Demo extends JFrame{  //继承了JFrame，其方法都可随便用
    public Demo(){
        setResizable(false);
        setTitle("...")//设置标题
        //getx();
        //gety();
        setDefaultCloseOperation(JFrame.HIDE_ON_CLOSE) 
        Container c = getContentPane();
        c.setBackground(Color.WHITE);
        JLabel l = new JLabel("文本内容");
        c.add(l);//添加
        c.remove(l);//删除
        c.validate();//验证容器的组件，刷新的效果
        c.setContenPane(l);//重新载入容器
    }
    public static void main(String[] args){
        new Demo();
    }
}
```

## JDialog

***话不多说上程序***

```java
import java.awt.Container;
import java.swing.*;

public class Demo extends JDialog{
    public Demo(JFrame f){
        super(f, "对话框标题", true);//boolean是否阻塞对话框
        Container c = getContentPane() ;
        c.add(new JLabel("内容"));
       
        //setVisible(true);
        setBounds(100,100,100,100);
    }
    public static void main(String[] args){
        JFrame f = new JFrame("fu");
        f.setBounds(50,50,300,300);
        f.setVisible(true);  
        Container c = getContentPane() ;
        JButton btn = new JButton("弹出对话框");
        c.add(btn);
        c.setLayout(new FloatLayout());//设置布局
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        btn.addActionListener(new ActionListener(){
            
            @Override
            public void actionPerformed(ActionEvent e){
                Demo d = new Demo(f);
                d.setVisible(true);//放到这里可使得对话框在窗体中
            }
        })
    }
}
```

## JLable

***话不多说上程序***

```java
public class Demo extends JFrame{  //继承了JFrame，其方法都可随便用
    public Demo(){
        setResizable(false);
        setTitle("...")//设置标题
        setBounds(100, 100, 300, 300);
        setDefaultCloseOperation(EXIT_ON_CLOSE) 
        Container c = getContentPane();
        c.setBackground(Color.WHITE);
        
        JLabel l = new JLabel("文本内容");
        l.setText("标签")
        System.out.println(l.getText());
        l.setFront(new Font("楷体", Font.BOLD, 15));//字体类型，样式（加粗/斜											体），字体大小。（加粗是PLAIN）
        l.setForeground(Color.RED);
        c.add(l);//添加
        l.setHorizontalTextPosition(SwingConstants.CENTER);//设置文本位置
        l.setVerticalTextPosition(SwingConstants.BOTTOM);
        //设置图片位置（猜测的还未试验）
        l.setHorizontalIconPosition(SwingConstants.CENTER);
        l.setVerticalIconPosition(SwingConstants.BOTTOM);
        
        //getx();//获取x坐标
        //gety();
    }
    public static void main(String[] args){
      new Demo();
    }
}

```

***添加图片***

```java
public class Demo extends JFrame{  //继承了JFrame，其方法都可随便用
    public Demo(){
        setResizable(false);
        setTitle("...")//设置标题
        setBounds(100, 100, 300, 300);
        setDefaultCloseOperation(EXIT_ON_CLOSE) 
        Container c = getContentPane();
        
        JLabel l = new JLabel();
        
        //第一种方法
        //URL url = Demo.class.getResource("java.png")//获取图片URL路径
        //Icon icon = new ImageIcon(url);
        //l.setIcon(icon);
        //URL是路径，上面url的使用表示获取Demo.class这个类的路径，然后在该路径里寻找			java.png这张图片
        
        //第二种方法
        Icon icon = new ImageIcon("src//java.png");//默认会到项目的路径下寻找图														片，所以从src开始就可以
        l.setIcon(icon);
        
        //l.setSize(20, 20);//设置标签的大小无法改变图片的大小
       
        c.add(l);//添加
    }
    public static void main(String[] args){
      new Demo();
    }
}
```

### JButton

```java
public class TestJButton{
    public static void main(String[] args){
        JFrame j = new JFrame();
        j.setSize(600, 600);
        j.setLocationRelativeTo(null);
        j.setDefaultCloseOperation(j.EXIT_ON_CLOSE);
        
        JPanel panel = new JPanel();
        JBUtton bn = new JButton();
        bn.setIcon(new ImageIcon("路径"));//路径从src开始
        bn.setPressedIcon(new ImageIcon("路径"));
        bn.setBorderPainted(false);//取消边框，以免影响图片显示
        bn.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                Object obj = e.getSource();
                if(obj == bn)
                    System.out.println(hh);
            }
        })
        j.setVisble(true);
    }
}
```

## JRadioButton

```java
public class TestSwing_1 {
    public static void main(String[] args) {
        //省略了JFrame的一些定义
        JPanel jp = new JPanel();
        jf.setContentPane(jp);

        JRadioButton rBoy = new JRadioButton("Boy");
        JRadioButton rGirl = new JRadioButton("Girl");

        rBoy.setSelected(true);//设置提前被选中
        //rBoy.setEnabled(false);//设置不能被选中
        System.out.println(rBoy.isSelected());//输出是否被选中
        jp.add(rBoy);
        jp.add(rGirl);
        rBoy.addChangeListener(new ChangeListener(){//设置监听
            @Override
            public void stateChanged(ChangeEvent e){
                JRadioButton jbn = (JRadioButton)e.getSource();
                System.out.println(jbn.isSelected());
            }
        });
        ButtonGroup bg = new ButtonGroup();//设置按钮组，组中的按钮不能被同时选中
        bg.add(rBoy);
        bg.add(rGirl);


        jf.setVisible(true);
    }
}
```

## JCheckBox

```java
public class TestCheckBox {
    public static void main(String[] args) {
        JPanel jp = new JPanel();
        jf.setContentPane(jp);
        jp.setLayout(new GridLayout());

        JCheckBox jbox1 = new JCheckBox("吃饭");
        JCheckBox jbox2 = new JCheckBox("睡觉");
        JCheckBox jbox3 = new JCheckBox("打豆豆");
        jbox1.setIconTextGap(60);//设置框和文本的间隙

        ChangeListener cl = new ChangeListener(){ //查看鼠标是否有在选项上的监听
            @Override
            public void stateChanged(ChangeEvent e){
                JCheckBox jbox =  (JCheckBox)e.getSource();
                System.out.println(jbox.getText());
            }
        };
//        jbox1.addChangeListener(cl);
//        jbox2.addChangeListener(cl);
//        jbox3.addChangeListener(cl);

        ActionListener al = new ActionListener(){  //查看鼠标是否有点到的监听
            @Override
            public void actionPerformed(ActionEvent e){
                JCheckBox jbox = (JCheckBox)e.getSource();
                System.out.println("你点我" + jbox.getText() + "啦");
            }
        };

        jbox1.addActionListener(al);
        jbox2.addActionListener(al);
        jbox3.addActionListener(al);

        jp.add(jbox1);
        jp.add(jbox2);
        jp.add(jbox3);

        jf.setVisible(true);
    }
}
```

## JToggleButton

```java
public class TestJToggleButton {
    public static void main(String[] args) 
        JPanel jp = new JPanel(null);
        JToggleButton tbn = new JToggleButton("显示");
        tbn.setBounds(170, 80, 100, 50);

        JLabel lb = new JLabel();
        lb.setText("试一下");
        lb.setIcon(new ImageIcon("Source\\s.png"));//当前路径系统默认从工程文件的														地址开始
        lb.setHorizontalTextPosition(SwingConstants.CENTER);
        lb.setVerticalTextPosition(SwingConstants.BOTTOM);
        lb.setBounds(150, 150, 300, 300);
        lb.setVisible(false);//先隐藏，等按按钮就打开


        ChangeListener cl = new ChangeListener(){ //查看鼠标是否有在选项上的监听
            @Override
            public void stateChanged(ChangeEvent e){
                JToggleButton tbn =  (JToggleButton)e.getSource();
                if(tbn.isSelected()) {	//判断按钮是否选中
                    lb.setVisible(true);
                    tbn.setText("隐藏");
                }
                else{
                    lb.setVisible(false);
                    tbn.setText("显示");
                }
            }
        };
        tbn.addChangeListener(cl);


        jp.add(tbn);
        jp.add(lb);

        jf.setContentPane(jp);
        jf.setVisible(true);
    }
}
```

## JTextField

```java
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class TestJTextField {
    public static void main(String[] args) {

        JPanel jp = new JPanel(null);//这里null，下面组件要手动设置位置和大小
        JLabel lb = new JLabel("你查啥");
        lb.setFont(new Font("楷体", Font.PLAIN, 15));
        lb.setBounds(30, 30, 100, 30);
        JTextField tf = new JTextField();
        tf.setFont(new Font("楷体", Font.PLAIN, 15));
        tf.setBounds(150, 30, 200, 50);
        JButton bn = new JButton("查吧");
        bn.setBounds(370, 30, 100, 40);
        ActionListener cl = new ActionListener(){ //查看鼠标是否有在选项上的监听
            @Override
            public void actionPerformed(ActionEvent e){ //处理点击事件
                    System.out.println(tf.getText());
            }
        };
        bn.addActionListener(cl);
        jp.add(lb);
        jp.add(tf);
        jp.add(bn);

        jf.setContentPane(jp);
        jf.setVisible(true);
    }
}
```

## JPasswordField

```java
        JPasswordField pf = new JPasswordField(10);
        pf.setFont(new Font("楷体", Font.PLAIN, 18));
        pf.setEchoChar('*');
        pf.setHorizontalAlignment(SwingConstants.CENTER);
        pf.setForeground(Color.BLUE);
        pf.setFont(new Font("圆体", Font.PLAIN, 20 ));

        JButton bn = new JButton("登录");
        ActionListener cl = new ActionListener(){ //查看鼠标是否有在选项上的监听
            @Override
            public void actionPerformed(ActionEvent e){
                char[] p = pf.getPassword();
                String pwd = new String(p);
                System.out.println("输入的密码为：" + pwd);
            }
        };
        bn.addActionListener(cl);
```

## JTextArea

```java
public class TestJTextArea {
    public static void main(String[] args) {
        JPanel jp = new JPanel(new BorderLayout());//可直接在此设置布局管理器

        JTextArea ta = new JTextArea(8,15);//行数和窗口的大小会限制按钮的大小
        ta.setPreferredSize(new Dimension(300, 600));//优先尺寸，还没弄懂
        ta.setLineWrap(true);//自动换行

        jp.add(new JScrollPane(ta), BorderLayout.NORTH);

        JButton bn = new JButton("测试");
        bn.setSize(300, 30);
        ActionListener cl = new ActionListener(){ //查看鼠标是否有在选项上的监听
            @Override
            public void actionPerformed(ActionEvent e){
                System.out.println(ta.getText());//输出文本内容
            }
        };
        bn.addActionListener(cl);

        jp.add(bn, BorderLayout.SOUTH);
        jp.add(new JScrollPane(ta), BorderLayout.NORTH);//添加组件时设置摆放位置
        jp.add(bn);

        jf.setContentPane(jp);
        jf.setVisible(true);
    }
}
```

## JComboBox

```java
public class TestComboBox {
    public static void main(String[] args) {

        JLabel lb = new JLabel("省份");

        String[] citys = new String[]{"湖南", "广东", "黑龙江", "云南", "新疆", "北京"}; //新建数组存放要放在滚动选框里的选项
        JComboBox cbb = new JComboBox(citys);

        cbb.addItemListener(new ItemListener(){ //新事件，好好记一记
            @Override
            public void itemStateChanged(ItemEvent e) {
                if (e.getStateChange() == ItemEvent.SELECTED)
                    System.out.println("选中了" + cbb.getSelectedIndex() + cbb.getSelectedItem());
            }
        });


        jp.add(lb);
        jp.add(cbb);

        jf.setContentPane(jp);
        jf.setVisible(true);
    }
}
```

## JScrollPanel

```java
public class TestJScrollPanel {
    public static void main(String[] args) {
        JTextArea jta = new JTextArea();
        jta.setFont(new Font("楷体", Font.BOLD, 18));
        jta.setForeground(Color.BLUE);
        JScrollPane jsp = new JScrollPane(jta,//将文本框加到面板中并设置需要的滚动条
                ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS,//水平滚动条
                ScrollPaneConstants.HORIZONTAL_SCROLLBAR_AS_NEEDED//垂直滚动条
                //ScrollPaneConstants.HORIZONTAL_SCROLLBAR_NEVER
                );

        jf.setContentPane(jsp);
        jf.setVisible(true);
    }
}
```

## JTabbedPane

```java
public class TestJTabbedPane {
    public static void main(String[] args) {
        JTabbedPane jtp = new JTabbedPane();

        jtp.addTab("查询赛事", createPanel("赛事"));//用方法来创建面板
        jtp.addTab("购票", createPanel("票"));
        jtp.addTab("充值", createPanel("充值界面"));
        jtp.setTabPlacement(JTabbedPane.LEFT); //设置选项卡的位置 
        jtp.setTabLayoutPolicy(JTabbedPane.SCROLL_TAB_LAYOUT);// 滚动条
        jtp.setTabLayoutPolicy(JTabbedPane.WRAP_TAB_LAYOUT);// 换行包起来
        jtp.setFont(new Font("宋体", Font.BOLD, 18));//设置选项卡的字的形式
        jtp.setSelectedIndex(0);//设置默认选项


        jtp.addChangeListener(new ChangeListener(){	//添加事件，切换选项卡的操作
            @Override
            public void stateChanged(ChangeEvent e){
                System.out.println(jtp.getSelectedIndex());
            }
        });

        jf.setContentPane(jtp);
        jf.setVisible(true);
    }
    public static JPanel createPanel(String str){//设置不同的面板
        JPanel jp = new JPanel();
        JTextArea jta = new JTextArea();
        jta.setFont(new Font("宋体", Font.BOLD, 18));
        jta.setLineWrap(true);
        jta.setSize(new Dimension(500, 500));
        jta.setForeground(Color.BLUE);
        jp.add(jta);
        return jp;

    }
}
```

## JDialog

```java
JOptionPane.showMassageDialog(jf, "消息内容", "标题", 消息类型);
//Input框第二种
Object[] selectionValues = Object[]{"..", "..", ".."};
Object content = JOptionPane.showInputDialog(if,
                                           "框的标题"，
                                           "选项的标题",
                                           JOption.PLAIN_MASSAGE,
                                           null，//未知何意
                                           selectionValues,//选项列标内容
                                           selectionValues[0]);//初始值
System.out.println("选项为" + content);
//showOptionDialog
Object[] selectionValues = Object[]{"..", "..", ".."};
int optionSelected = JOptionPane.showOptionDialog(if,
                                           "提示信息",
                                           "框的标题",
                                           JOptionPane.YES_NO_CANCEL_OPTION,
                                           JOptionPane.ERROR_MASSAGE
                                           null，//未知何意
                                           selectionValues,//选项列标内容
                                           selectionValues[0]);//初始值
System.out.println("选项为" + optionSelected);
/*
   	 弹窗类型				     消息类型
 showMassageDialog		JOptionPane.WARNING_MASSAGE
 						JOptionPane.INFORMATION_MASSAGE
 showConfirmDialog		JOptionPane.YES_NO_OPTION    //准确来说是选项形式
 						JOptionPane.YES_OPTION
 						JOptionPane.YES_NO_CANCEL_OPTION
 showInputDialog		不用消息类型，直接 if  ， 文本框标题  ， 文本框初始值
 						JOptionPane.PLAIN_MASSAGE
 
*/
/*
    结果的接收（int类型） 弹窗的返回值
    YES_OPTION      0
    NO_OPTION       1
    CANCEL_OPTION   2
    OK_OPTION       0
    CLOSE_OPTION   -1
*/
```



## 布局管理系统

``` java
//设置方式
Container c = f.getContentPane();
c.setLayout()//可填null, new FlowLayout(), 
```

#### null

```java
//这时组件是按我们填入的坐标和尺寸大小摆放
//组件不随窗口的大小改变
Button bn = new Button();
c.add(bn);
bn.setBounds(10, 30, 50, 50);//坐标相对于容器的左上角,不设置看不到组件
```

### FlowLayout

```java
//组件会随窗口的大小改变摆放位置，当窗口过小组件也会显示不全
new FlowLayout();//不输入内容默认居中，间距也默认
new FlowLayout(FlowLayout.RIGHT)//可让其靠左或靠右
new FLowLayout(FlowLayout.RIGHT, 20, 20);//设置其水平、垂直间距
    
```

###  BoderLayout(默认的)

```java
//组件会随着窗口的大小改变大小，且同一位置的组件会相互覆盖
c.add(bn, BorderLayout.CENTER);//还有EAST,WEST,NORTH,SOUTH
```

### GridLayout

```java
//组件会随着窗口的大小改变大小,始终保持行数列数（特定组件个数不够或过多的情况下，它会自动优化布局，优先扩大行数）
new GridLayout(行数,列数,水平间距 ,垂直间距 );
new GridLayout(行数, 列数);
```

### GridBagLayout

```java
GridBagConstraints g = new GridBagConstrains();
g.gridx = 1;//坐标
g.gridy = 3;
g.gridwidth = 2;//占用的横向网格数
g.gridheight = 2;//占用的纵向网格数
g.fill = GidBagConstraints.HORIZONtal//默认不设置是none
//HORIZONTAL水平填充
//VERTICAL垂直填充
//BOTH全填充
g.anchor = GidBagConstraints.CENTER;//还可以写任意方位（EAST，WEST等）
								    //表示组件在其所占用网格中的位置
g.insets = new Insets(5, 5, 5, 5);//分别为与上边、下边、左边、右边组件的距离
								  //与上边属性不同Insets是一个类
g.ipadx = 10//拉大组件
g.ipady = -10;//缩小组件
g.weightx = 10;//最大宽高，在窗体被拉大的时候能占据的最大宽高
g.weighty = 10;
c.add(new JButton("按钮")， g);
```

### Box

```java
Box hBox = Box.createHorizontalBox();//水平箱子，相当于一行，其中放组件无间隔
hBox.add(new JButton);
hBox.add(new JButton);
hBox.add(new JButton);
Box vBox = Box.createVerticalBox();//垂直箱子，相当于一列，其中放组件无间隔
vBox.add(Box.createVerticalGlue);//添加一个不可见的水平组件 
vBox.add(Box.createVerticalStrut(高度));//固定高度的不可见组件，还有固定宽度的		   									 createHorizontalStrut(宽度)
createRigidArea(new Dimension(宽， 高));//添加固定宽高的不可见组件
```



