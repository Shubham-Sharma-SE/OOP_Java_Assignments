class Restaurant {
    String restaurantName;
    long restaurantContact;
    String restaurantAddress;
    float rating;

    void displayRestaurantDetails() {
        System.out.println("Restaurant Details");
        System.out.println("Restaurant Name: " + restaurantName);
        System.out.println("Restaurant Contact: " + restaurantContact);
        System.out.println("Restaurant Address: " + restaurantAddress);
        System.out.println("Restaurant Rating: " + rating);
    }
}

public class Tester {
    public static void main(String[] args) {

        Restaurant r = new Restaurant();

        r.restaurantName = "Domino's";
        r.restaurantContact = 9988567647L;
        r.restaurantAddress = "Pune";
        r.rating = 4.5f;

        r.displayRestaurantDetails();
    }
}
