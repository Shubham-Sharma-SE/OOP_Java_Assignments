package com.vit.manager;

import com.vit.employee.PerEmployee;

public class Manager extends PerEmployee {

    public Manager(int id, String name, double salary, String dept) {
        super(id, name, salary, dept);
    }

    @Override
    public void display() {
        System.out.println("Manager Id: " + id);
        System.out.println("Manager Name: " + name);
        System.out.println("Manager Salary: " + salary);
        System.out.println("Manager Department: " + dept);
    }
}
