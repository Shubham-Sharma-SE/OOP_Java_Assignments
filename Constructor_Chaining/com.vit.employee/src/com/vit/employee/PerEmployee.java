package com.vit.employee;

public class PerEmployee extends Employee {

    protected double salary;
    protected String dept;

    public PerEmployee(int id, String name, double salary, String dept) {
        super(id, name);
        this.salary = salary;
        this.dept = dept;
        System.out.println("This Is Per Employee Class");
    }

    @Override
    public void display() {
        super.display();
        System.out.println("Employee Salary: " + salary);
        System.out.println("Employee Department: " + dept);
    }
}
