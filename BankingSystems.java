//Impementing Interface Concept

import java.util.Scanner;

interface UPI {

    void upibanking(double amount);
}

interface CreditCard {

    void creditcardb(double amount);
}

interface NetBanking {

    void netbanking(double amount);
}

class BankingSystem implements UPI, CreditCard, NetBanking {

    public void upibanking(double amount) {
        System.out.println("The Amount Credited is: " + amount);
    }

    public void creditcardb(double amount) {
        System.out.println("The Amount Credited is: " + amount);
    }

    public void netbanking(double amount) {
        System.out.println("The Amount Credited is: " + amount);
    }
}

public class BankingSystems {

    public static void main(String[] args) {

        BankingSystem bs = new BankingSystem();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the amount to be credited: ");
        double amount = sc.nextDouble();
        System.out.println("====The Payment Options====");
        bs.upibanking(amount);
        bs.creditcardb(amount);
        bs.netbanking(amount);

    }
}
