package com.hky.event.dao;

import com.hky.event.entity.Event;
import com.hky.event.util.DBUtil;

import java.sql.*;
import java.util.ArrayList;

public interface EventDao {
    /**
     *
     * @param blue
     * @param red
     * @return
     */
    ArrayList<Event> searchEvent(String blue, String red);

    /**
     *
     * @return
     */
    ArrayList<String> showEvent();

    /**
     *
     * @param uID
     * @param eID
     * @return
     */
    String searchTicket(int uID, int eID);

    /**
     *
     * @param sql1
     * @param sql2
     * @return
     */
    boolean buyTickets(String sql1, String sql2);

    /**
     *
     * @param eID
     * @return
     */
    boolean deleteEvent(String eID);

    /**
     *
     * @param date
     * @param blue
     * @param red
     * @param price
     * @return
     */
    boolean addEvent(String date, String blue, String red, String price);

    /**
     *
     * @param eID
     * @param change
     * @param name
     * @return
     */
    boolean updateEvent(String eID, String change, String name);
}
