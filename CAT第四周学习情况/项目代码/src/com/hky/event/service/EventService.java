package com.hky.event.service;

import com.hky.event.entity.Event;
import com.hky.event.entity.User;

import java.util.ArrayList;

public interface EventService {

    /**
     *
     * @return
     */
    ArrayList<String> showEvent();

    /**
     *
     * @param blue
     * @param red
     * @return
     */
    ArrayList<Event> searchEvent(String blue, String red);

    /**
     *
     * @param eID
     * @param user
     * @param pattern
     * @param price
     * @return
     */
    String buyTickets(int eID, User user, String pattern, double price);

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
