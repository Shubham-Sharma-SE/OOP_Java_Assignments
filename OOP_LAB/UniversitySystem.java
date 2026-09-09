
class University {

    String UniversityName;

    public void setUniversityName(String UniversityName) {
        this.UniversityName = UniversityName;

    }

    public void displayUniversity() {

        System.out.println("Maintain 75% Attendance");
        System.out.println("University Name: "+UniversityName);
    }

}

class Student extends University {

    final String Studentname = "Shubham";

    public Student(String UniversityName) {
        super.setUniversityName(UniversityName);
    }

    public void displayStudent() {
        System.out.println("The Student Name: " + Studentname);
        
    }
}

public class UniversitySystem {

    public static void main(String[] args) {

        Student s = new Student("XYZ University");
        s.displayStudent();
        s.displayUniversity();
    }
}

