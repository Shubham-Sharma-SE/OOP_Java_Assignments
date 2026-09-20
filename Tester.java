class Participant {
    // Static variable shared across all objects
    private static int counter;

    // Instance variables
    private String registrationId;
    private String name;
    private long contactNumber;
    private String branch;

    // Static block to initialize static variable counter
    static {
        counter = 1001;
    }

    // Parameterized constructor
    public Participant(String name, long contactNumber, String branch) {
        this.name = name;
        this.contactNumber = contactNumber;
        this.branch = branch;
        this.registrationId = "D" + counter++;
    }

    // Getters and Setters
    public static int getCounter() {
        return counter;
    }

    public static void setCounter(int counter) {
        Participant.counter = counter;
    }

    public String getRegistrationId() {
        return registrationId;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public long getContactNumber() {
        return contactNumber;
    }

    public void setContactNumber(long contactNumber) {
        this.contactNumber = contactNumber;
    }

    public String getBranch() {
        return branch;
    }

    public void setBranch(String branch) {
        this.branch = branch;
    }
}

public class Tester {
    public static void main(String[] args) {
        Participant participant1 = new Participant("Rohit", 1234567889L, "Computer");
        Participant participant2 = new Participant("Sayli", 1988612300L, "Mechanical");

        System.out.println("Hi " + participant1.getName() + "! Your registration id is " + participant1.getRegistrationId());
        System.out.println("Hi " + participant2.getName() + "! Your registration id is " + participant2.getRegistrationId());
    }
}




