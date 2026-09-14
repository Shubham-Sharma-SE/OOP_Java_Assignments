package institute;

import java.util.ArrayList;
import java.util.List;

public class Teacher {
    private int employeeId;
    private String name;
    private String designation;
    private List<Course> coursesTaught;

    public Teacher(int employeeId, String name, String designation) {
        this.employeeId = employeeId;
        this.name = name;
        this.designation = designation;
        this.coursesTaught = new ArrayList<>();
    }

    public int getEmployeeId() {
        return employeeId;
    }

    public String getName() {
        return name;
    }

    public String getDesignation() {
        return designation;
    }

    public List<Course> getCoursesTaught() {
        return coursesTaught;
    }

    public void assignCourse(Course course) {
        coursesTaught.add(course);
        course.setTeacher(this);
    }

    @Override
    public String toString() {
        return "Teacher{" +
                "employeeId=" + employeeId +
                ", name='" + name + '\'' +
                ", designation='" + designation + '\'' +
                ", coursesTaught=" + coursesTaught.size() +
                '}';
    }
}
