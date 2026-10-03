package com.vit.employee;

public class Employee {

    protected int id;
    protected String name;

    public Employee() {
        this(0, "");
    }

    public Employee(int id, String name) {
        this.id = id;
        this.name = name;
        System.out.println("This Is Employee Class");
    }

    public void display() {
        System.out.println("Employee Id: " + id);
        System.out.println("Employee Name: " + name);
    }
}
