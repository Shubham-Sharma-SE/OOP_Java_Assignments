package institute;

public class Student {
    private int rollNumber;
    private String name;
    private String email;
    private Course enrolledCourse;

    public Student(int rollNumber, String name, String email) {
        this.rollNumber = rollNumber;
        this.name = name;
        this.email = email;
    }

    public int getRollNumber() {
        return rollNumber;
    }

    public String getName() {
        return name;
    }

    public String getEmail() {
        return email;
    }

    public Course getEnrolledCourse() {
        return enrolledCourse;
    }

    public void enrollInCourse(Course course) {
        this.enrolledCourse = course;
        course.addStudent(this);
    }

    @Override
    public String toString() {
        String courseName = (enrolledCourse != null) ? enrolledCourse.getCourseName() : "Not enrolled";
        return "Student{" +
                "rollNumber=" + rollNumber +
                ", name='" + name + '\'' +
                ", email='" + email + '\'' +
                ", course='" + courseName + '\'' +
                '}';
    }
}
