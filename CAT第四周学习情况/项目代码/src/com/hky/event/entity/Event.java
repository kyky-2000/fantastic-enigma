package com.hky.event.entity;

public class Event {
    private int eID;
    private String date;
    private String blue;
    private String red;
    private double price;

    public int getID(){
        return eID;
    }

    public void setID(int eID){
        this.eID = eID;
    }

    public String getDate(){
        return date;
    }

    public void setDate(String date){
        this.date = date;
    }

    public String getBlue(){
        return blue;
    }

    public void setBlue(String blue){
        this.blue = blue;
    }

    public String getRed(){
        return red;
    }

    public void setRed(String red){
        this.red = red;
    }

    public double getPrice(){
        return price;
    }

    public void setPrice(double price){
        this.price = price;
    }

}
