<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>login</title>

    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <style type="text/css">
        h1{text-align:center;}
        h4{text-align:right;color:red;}
        body{background:url(image/3.jpg)}
    </style>
    <script type="text/javascript" src="js/jquery.min.js"></script>
</head>
<body>

    <form action="/servletTest/loginServlet" method="post">
        <table>
            <tr>
                <td>用户名</td>
                <td><input type="text" name="username"></td>
            </tr>
            <tr>
                <td>密码</td>
                <td><input type="password" name="password"></td>
            </tr>
            <tr>
                <td><input type="submit" value="登录"></td>
                <a href="register.jsp" target="_blank">注册</a>
            </tr>
        </table>


    </form>


    <div><%=request.getAttribute("error") == null ? "" : request.getAttribute("error")%></div>

</body>
</html>
