package com.vit.main;

import com.vit.manager.Manager;

public class Main {
    public static void main(String[] args) {
        Manager m = new Manager(101, "Name", 75000.0, "IT");
        m.display();
    }
}
