class Student {
    private String name;
    private int rollNo;
    private String course;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getRollNo() {
        return rollNo;
    }

    public void setRollNo(int rollNo) {
        this.rollNo = rollNo;
    }

    public String getCourse() {
        return course;
    }

    public void setCourse(String course) {
        this.course = course;
    }

    // 1. Fully-parameterized constructor
    Student(String name, int rollNo, String course) {
        this.name = name;
        this.rollNo = rollNo;
        this.course = course;
    }

    // 2. Chained constructor: provides default course
    Student(String name, int rollNo) {
        this(name, rollNo, "Computer Engineering"); // Calls constructor 1
    }

    // 3. Default constructor: provides all default values
    Student() {
        this("Unknown", 0); // Calls constructor 2
    }
}
public class conschain {
    public static void main(String[] args) {
        Student student1 = new Student("Shubham", 30, "Computer Science");
        Student student2 = new Student("Aditya", 102);
        Student student3 = new Student();

        System.out.println("Student 1: Name = " + student1.getName() + ", Roll No = " + student1.getRollNo() + ", Course = " + student1.getCourse());
        System.out.println("Student 2: Name = " + student2.getName() + ", Roll No = " + student2.getRollNo() + ", Course = " + student2.getCourse());
        System.out.println("Student 3: Name = " + student3.getName() + ", Roll No = " + student3.getRollNo() + ", Course = " + student3.getCourse());
    }
}