class Order {

    int orderId;
    String orderedFoods;
    String status;

    Order() {
        status = "Ordered";
    }

    Order(int orderId, String orderedFoods) {
        this.orderId = orderId;
        this.orderedFoods = orderedFoods;
        status = "Ordered";
    }

    void displayOrderDetails() {
        System.out.println("Order ID: " + orderId);
        System.out.println("Ordered Foods: " + orderedFoods);
        System.out.println("Status: " + status);
    }
}

public class Tester {
    public static void main(String[] args) {

        Order o1 = new Order();
        System.out.println("Order 1:");
        System.out.println("Status: " + o1.status);

        Order o2 = new Order(1001, "Pizza, Burger");
        System.out.println("Order 2:");
        o2.displayOrderDetails();
    }
}