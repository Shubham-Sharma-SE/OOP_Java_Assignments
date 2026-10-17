package com.vit.edu;

import java.util.Scanner;

class InsufficientBalanceException extends Exception {
    public InsufficientBalanceException(String msg) {
        super(msg);
    }
}

class Account {
    private double balance;

    public Account(double balance) {
        this.balance = balance;
    }

    public void withdraw(double amount) throws InsufficientBalanceException {
        if (amount <= 0) {
            throw new IllegalArgumentException("Invalid Input!");
        }
        if (amount > balance) {
            throw new InsufficientBalanceException("Insufficient Balance!");
        }
        balance -= amount;

        System.out.println("Bank Withdraw System: ");
        System.out.println("The amount deducted is: " + amount);
    }

    public void display() {
        System.out.println("Your Balance is: " + balance);
    }
}

public class Account_System {
    public static void main(String[] args) {
        Account aa = new Account(10000);
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter amount to withdraw: ");
        
        try {
            double amount = sc.nextDouble();
            aa.withdraw(amount);
            aa.display();
        } catch (InsufficientBalanceException | IllegalArgumentException e) {
            System.out.println("Error: " + e.getMessage());
        } catch (Exception e) {
            System.out.println("An unexpected error occurred: " + e.getMessage());
        } finally {
            System.out.println("Account System Completed");
            sc.close();
        }
    }
}