##### 导入包 import  java.awt.*;

# 窗口

## Frame（顶级容器，可独立显示）

#### 默认布局管理系统为 GridLayout()

Frame f= new Frame("窗口名");    定义对象

**方法：**

f.add(); 

f.setLayout();  布局管理系统

f.setColor();   颜色   可填Color.*  或  new Color(*, *, *);

f.setSize(*, *);   尺码

f.setBounds(*, *, *, *);   尺码位置一起

f.setLocation(*, *);   位置

f.pack();   包裹好其他组件

f.visible(true/false);   （不）可见

## Panel(容器，但不可独立显示)

#### 默认布局管理系统为 BorderLayout()

定义方法和可调用的方法基本同上



# 事务管理系统

## FlowLayout()

定义  new  FlowLayout()

组件像水流一样一个一个排

添加方法   容器.add(组件)

## BorderLayout()

定义  new BorderLayout()

东西南北中的布局

添加方法   容器.add(组件，位置);   位置示范 ：BorderLayout.WEST  或  "West"

## GridLayout()

定义  new GridLayout(*, *)  填入行数列数

按行列排

添加方法  容器.add(组件)



# 事件

##### 导入包  import java.awt.event.*;

#### 事件的监听与处理

##### 实例

```java
class MyMonitor extends WindowAdapter implements ActionListener{
    @Override
    public void actionPerformed(ActionEvent e){
       	         //处理点击这事件的方法
    }
    @Override
    public void windowClosing(WindowEvent e){
        System.exit(-1);    //处理窗口的方法，表示可关闭窗口
    }
}
public class *{

	public static void main(String[]  args){
		
		Frame f = new Frame();
		Button bn = new Button(aa);

		bn.addActionListener(new MyMonitor());    //事件对象注册事件监听器
		f.addWindowListener(new MyMonitor());
	}

}
```

#### 三个文本框相加

***重要知识点（变量的类使用）***

*第一种情况*

```java
public class TestTextField{
    
    public static TextField tf1, tf2, tf3;
    
    public static void main(String[] args){
        
        Button bn = new Button("=");
        tf1 = new TextField(30);
        tf2 = new TextField(30);
        tf3 = new TextField(30);
        
        bn.addActionListener(new MyMonitor());
 	}
class MyMonitor implements ActionListener{
    @Override     //重写函数的标志
    public void actionPerformed(ActionEvent e){

        int n1 = Integer.parseInt(TestTextField.tf1.getText());
        int n2 = Integer.parseInt(TestTextField.tf2.getText());
        int n3 = n1 + n2;
        Integer it = new Integer(n3);

        TestTextField.tf3.setText(it.toString());
    }
}
```

*第二种情况（用this调用对象）*

```java
public class TestTextField{
    
    public static void main(String[] args){
        new Tf().Launch();  
 	}

class Tf{
    public TextField t1, t2, t3;
    
    public void Launch(){
        Button bn = new Button("=");
        tf1 = new TextField(30);
        tf2 = new TextField(30);
        tf3 = new TextField(30);
        
        bn.addActionListener(new MyMonitor(this));
    }
}

class MyMonitor extends WindowAdapter implements ActionListener{
    private Tf tf;
  	
    public MyMonitor(Tf tf){
    	this.tf = tf;    
    }
    @Override
    public void actionPerformed(ActionEvent e){
        int n1 = Integer.parseInt(tf.t1.getText());
        int n2 = Integer.parseInt(tf.t2.getText());
        int n3 = n1 + n2;
        Integer it = new Integer(n3);

        tf.t3.setText(it.toString());
    }
}
```

*第三种方法（内部类）*

```java
public class TestTextField{
    
    public static void main(String[] args){
        new Tf().Launch();  
 	}

class Tf{
    public TextField t1, t2, t3;
    
    public void Launch(){
        Button bn = new Button("=");
        tf1 = new TextField(30);
        tf2 = new TextField(30);
        tf3 = new TextField(30);
        
        bn.addActionListener(new MyMonitor());
    }
    class MyMonitor extends WindowAdapter implements ActionListener{
        @Override
        public void actionPerformed(ActionEvent e){
            int n1 = Integer.parseInt(t1.getText());
            int n2 = Integer.parseInt(t2.getText());
            int n3 = n1 + n2;
            Integer it = new Integer(n3);

            t3.setText(it.toString());
        }
    }
}

   
```



##### 小插曲（整型数据如何转化成字符型）

*方法一*

``` java
int i = 345;
String str = i + '';
```

*方法二*

```java
int i = 345；
Integer it = new Integer(i);
String str = it.toString();
```

*方法三*

```java
int i = 345;
String str = Integer.toString(i);
```

*方法四*

```java
int i = 345;
String str = String.valueOf(i);
```

