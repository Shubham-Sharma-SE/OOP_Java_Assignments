class vehicle {
    int speed;
    String fuelType;

    vehicle(int speed, String fuelType) {
        this.speed = speed;
        this.fuelType = fuelType;
    }

    String Type() {
        return "Vehicle";
    }

    void display() {
        System.out.println("Type: " + Type());
        System.out.println("Speed: " + speed + " km/h");
        System.out.println("Fuel Type: " + fuelType);
    }
}

class car extends vehicle {
    int seatingCapacity;
    int numberOfDoors;

    car(int speed, String fuelType, int seatingCapacity, int numberOfDoors) {
        super(speed, fuelType);
        this.seatingCapacity = seatingCapacity;
        this.numberOfDoors = numberOfDoors;
    }

    String Type1() {
        return "Maruti";
    }

    void displayCar() {
        System.out.println("Brand: " + Type1());
        System.out.println("Speed: " + speed + " km/h");
        System.out.println("Fuel Type: " + fuelType);
        System.out.println("Seating Capacity: " + seatingCapacity);
        System.out.println("Number of Doors: " + numberOfDoors);
    }
}

class bikes extends vehicle {
    int engineCapacity;
    boolean hasGear;

    bikes(int speed, String fuelType, int engineCapacity, boolean hasGear) {
        super(speed, fuelType);
        this.engineCapacity = engineCapacity;
        this.hasGear = hasGear;
    }

    String Type2() {
        return "Honda";
    }

    void displayBike() {
        System.out.println("Brand: " + Type2());
        System.out.println("Speed: " + speed + " km/h");
        System.out.println("Fuel Type: " + fuelType);
        System.out.println("Engine: " + engineCapacity + " cc");
        System.out.println("Has Gear: " + hasGear);
    }
}

class electric_vehicle extends vehicle {
    int batteryCapacity;
    int range;

    electric_vehicle(int speed, String fuelType, int batteryCapacity, int range) {
        super(speed, fuelType);
        this.batteryCapacity = batteryCapacity;
        this.range = range;
    }

    String Type3() {
        return "Tesla";
    }

    void displayEV() {
        System.out.println("Brand: " + Type3());
        System.out.println("Speed: " + speed + " km/h");
        System.out.println("Fuel Type: " + fuelType);
        System.out.println("Battery: " + batteryCapacity + " kWh");
        System.out.println("Range: " + range + " km");
    }
}

public class InheritanceConcept {

    public static void main(String[] args) {

        vehicle v = new vehicle(60, "Generic");
        car c = new car(180, "Petrol", 5, 4);
        bikes b = new bikes(120, "Petrol", 150, true);
        electric_vehicle e = new electric_vehicle(200, "Electric", 75, 500);

        System.out.println("=== Vehicle ===");
        v.display();

        System.out.println("\n=== Car ===");
        c.displayCar();

        System.out.println("\n=== Bike ===");
        b.displayBike();

        System.out.println("\n=== Electric Vehicle ===");
        e.displayEV();
    }
}