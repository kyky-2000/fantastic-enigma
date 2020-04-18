package com.hky.event.service.impl;

import com.hky.event.dao.EventDao;
import com.hky.event.dao.impl.EventDaoimpl;
import com.hky.event.entity.Event;
import com.hky.event.entity.User;
import com.hky.event.service.EventService;

import java.util.ArrayList;

public class EventServiceimpl implements EventService {

    private EventDao eventDao = new EventDaoimpl();

    public ArrayList<String> showEvent(){
        return eventDao.showEvent();
    }

    public ArrayList<Event> searchEvent(String blue, String red){
        return eventDao.searchEvent(blue, red);
    }

    public String buyTickets(int eID, User user, String pattern, double price){

        if(pattern.equals("预订") && user.getBalance()<price*0.4)
            return "余额不足";
        else if(pattern.equals("购买") && user.getBalance()<price)
            return "余额不足";

        String str = eventDao.searchTicket(user.getID(), eID);
        String sql1 = null;
        String sql2 = null;

        if(str.equals("预订") && pattern.equals("购买")) {
            sql1 = "update transaction set pattern = '购买' where eID = '" + eID + "'";
            sql2 = "update user set balance = balance - "+price+"*0.6 where uID = '"+user.getID()+"'";
            user.setBalance(user.getBalance() - price*0.6);
        }
        else if(str == null) {
            sql1 = "insert into transaction(uID, eID, pattern)  value('" + user.getID() + "', '" + eID + "', '" + pattern + "')";
            if (pattern == "预订") {
                sql2 = "update user set balance = balance - " + price + "*0.4 where uID = '" + user.getID() + "'";
                user.setBalance(user.getBalance() - price * 0.4);
            } else{
                sql2 = "update user set balance = balance - " + price + " where uID = '" + user.getID() + "'";
                user.setBalance(user.getBalance() - price);
            }
        }
        if(eventDao.buyTickets(sql1, sql2) == true)
            return pattern+"成功";
        else
            return pattern+"失败";
    }

    public boolean deleteEvent(String eID){
        return eventDao.deleteEvent(eID);
    }

    public boolean addEvent(String date, String blue, String red, String price){
        return eventDao.addEvent(date, blue, red, price);
    }

    public boolean updateEvent(String eID, String change, String name){
        return eventDao.updateEvent(eID, change, name);
    }
}
