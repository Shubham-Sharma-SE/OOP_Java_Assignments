import institute.Student;
import institute.Teacher;
import institute.Course;
import institute.Department;

public class Main {
    public static void main(String[] args) {
        Department cse = new Department("D01", "Computer Science", "Dr. A. Sharma");

        Course dbms = new Course("CS201", "Database Management Systems", 4);
        cse.addCourse(dbms);

        Teacher teacher = new Teacher(101, "Prof. R. Kulkarni", "Associate Professor");
        teacher.assignCourse(dbms);

        Student s1 = new Student(1, "Shubham", "shubham@example.com");
        Student s2 = new Student(2, "Aisha", "aisha@example.com");
        s1.enrollInCourse(dbms);
        s2.enrollInCourse(dbms);

        System.out.println(cse);
        System.out.println(dbms);
        System.out.println(teacher);
        System.out.println(s1);
        System.out.println(s2);
    }
}
