package com.hky.event.dao.impl;

import com.hky.event.dao.EventDao;
import com.hky.event.entity.Event;
import com.hky.event.util.DBUtil;
import com.hky.event.view.UserMainView;

import java.sql.*;
import java.util.ArrayList;

public class EventDaoimpl implements EventDao {
    public ArrayList<Event> searchEvent(String blue, String red){
        Connection conn = null;
        PreparedStatement ps = null;
        ResultSet rs = null;
        String sql = null;
        ArrayList<Event> events = new ArrayList<>();

        if(blue.isEmpty() && red.isEmpty())
            return null;
        try{
            conn = DBUtil.getConnection();

            sql = "select * from EventInfo where blue like ? and red like ?";
            ps = conn.prepareStatement(sql);
            ps.setString(1, "%"+blue+"%");
            ps.setString(2, "%"+red+"%");
            rs = ps.executeQuery();

            while(rs.next()){
                Event event = new Event();
                event.setID(rs.getInt(1));
                event.setDate(rs.getString(2));
                event.setBlue(rs.getString(3));
                event.setRed(rs.getString(4));
                event.setPrice(rs.getDouble(5));

                events.add(event);
            }

        }catch(Exception e){
            e.printStackTrace();
        }finally{
            DBUtil.close(conn, ps, rs);
        }
        return events;
    }

    public ArrayList<String> showEvent(){
        Connection conn = null;
        Statement stmt = null;
        ResultSet rs = null;
        ArrayList<String> al = new ArrayList<String>();

        try{
            conn = DBUtil.getConnection();
            String sql = "select * from EventInfo order by eDate desc";
            stmt = conn.createStatement();
            rs = stmt.executeQuery(sql);

            while(rs.next()){
                al.add(rs.getString(1));
                al.add(rs.getString(2));
                al.add(rs.getString(3));
                al.add(rs.getString(4));
            }
        }catch(SQLException e){
            e.printStackTrace();
        }finally{
            DBUtil.close(conn, stmt, rs);
        }
        return al;
    }

    public String searchTicket(int uID, int eID){

        Connection conn = null;
        Statement stmt = null;
        ResultSet rs = null;
        String pattern = null;
        try{
            conn = DBUtil.getConnection();
            stmt = conn.createStatement();
            String sql = "select * from transaction where uID = '"+uID+"' and eID = '"+eID+"'";
            rs = stmt.executeQuery(sql);
            if(rs.next()){
                pattern = rs.getString(4);
                System.out.println(pattern);
            }
        }catch(SQLException e){
            e.printStackTrace();
        }finally {
            DBUtil.close(conn, stmt, rs);
        }
        return pattern;
    }

    public boolean buyTickets(String sql1, String sql2){
        boolean reservationSuccess = false;
        Connection conn = null;
        Statement stmt = null;
        ResultSet rs = null;
        try{
            conn = DBUtil.getConnection();
            stmt = conn.createStatement();

            int count = stmt.executeUpdate(sql1);
            count += stmt.executeUpdate(sql2);
            if(2 == count){
                reservationSuccess = true;
            }
        }catch(SQLException e){
            e.printStackTrace();
        }finally {
            DBUtil.close(conn, stmt, rs);
        }
        return reservationSuccess;
    }

    public boolean deleteEvent(String eID){
        boolean deleteSuccess = false;
        Connection conn = null;
        PreparedStatement ps = null;
        ResultSet rs = null;
        String sql = null;

        try{
            conn = DBUtil.getConnection();
            sql = "delete from EventInfo where eID = ?";
            ps = conn.prepareStatement(sql);
            ps.setString(1, eID);

            int count = ps.executeUpdate();
            if(count == 1)
                deleteSuccess = true;

        }catch(SQLException e){
            e.printStackTrace();
        }finally {
            DBUtil.close(conn, ps, rs);
        }
        return deleteSuccess;
    }

    public boolean addEvent(String date, String blue, String red, String price) {
        boolean insertSuccess = false;
        Connection conn = null;
        PreparedStatement ps = null;
        ResultSet rs = null;
        System.out.println(date + "," + blue + "," + red + "," + price);

        try {
            conn = DBUtil.getConnection();
            String sql = "insert into EventInfo(eDate, blue, red, price) value(?, ?, ?, ?)";
            ps = conn.prepareStatement(sql);
            ps.setString(1, date);
            ps.setString(2, blue);
            ps.setString(3, red);
            ps.setString(4, price);

            int count = ps.executeUpdate();
            if (count == 1)
                insertSuccess = true;

        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            DBUtil.close(conn, ps, rs);
        }
        return insertSuccess;
    }

    public boolean updateEvent(String eID, String change, String name){
        boolean updateSuccess = false;
        Connection conn = null;
        PreparedStatement ps = null;
        ResultSet rs = null;
        String sql = null;

        try{
            conn = DBUtil.getConnection();

            if(name == "eDate")
                sql = "update EventInfo set eDate = ? where eID = ?";
            else if(name == "blue")
                sql = "update EventInfo set blue = ? where eID = ?";
            else if(name == "red")
                sql = "update EventInfo set red = ? where eID = ?";
            else
                sql = "update EventInfo set price = ? where eID = ?";
            ps = conn.prepareStatement(sql);
            ps.setString(1, change);
            ps.setString(2, eID);

            int count = ps.executeUpdate();
            if(count == 1)
                updateSuccess = true;

        }catch(SQLException e){
            e.printStackTrace();
        }finally {
            DBUtil.close(conn, ps, rs);
        }
        return updateSuccess;
    }
}
