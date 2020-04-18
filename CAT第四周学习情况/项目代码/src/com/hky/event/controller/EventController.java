package com.hky.event.controller;

import com.hky.event.entity.Event;
import com.hky.event.entity.User;
import com.hky.event.service.EventService;
import com.hky.event.service.impl.EventServiceimpl;

import java.util.ArrayList;

public class EventController {
    private EventService eventService = new EventServiceimpl();

    public ArrayList<String> showEvent(){
        return eventService.showEvent();
    }

    public ArrayList<Event> searchEvent(String blue, String red){
        return eventService.searchEvent(blue, red);
    }

    public String buyTickets(int eID, User user, String pattern, double price){
        return eventService.buyTickets(eID, user, pattern, price);
    }

    public boolean deleteEvent(String eID){
        return eventService.deleteEvent(eID);
    }

    public boolean addEvent(String date, String blue, String red, String price){
        return eventService.addEvent(date, blue, red, price);
    }

    public boolean updateEvent(String eID, String change, String name){
        return eventService.updateEvent(eID, change, name);
    }
}
