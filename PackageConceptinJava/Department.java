package institute;

import java.util.ArrayList;
import java.util.List;

public class Department {
    private String departmentId;
    private String departmentName;
    private String headOfDepartment;
    private List<Course> courses;

    public Department(String departmentId, String departmentName, String headOfDepartment) {
        this.departmentId = departmentId;
        this.departmentName = departmentName;
        this.headOfDepartment = headOfDepartment;
        this.courses = new ArrayList<>();
    }

    public String getDepartmentId() {
        return departmentId;
    }

    public String getDepartmentName() {
        return departmentName;
    }

    public String getHeadOfDepartment() {
        return headOfDepartment;
    }

    public List<Course> getCourses() {
        return courses;
    }

    public void addCourse(Course course) {
        courses.add(course);
        course.setDepartment(this);
    }

    @Override
    public String toString() {
        return "Department{" +
                "departmentId='" + departmentId + '\'' +
                ", departmentName='" + departmentName + '\'' +
                ", headOfDepartment='" + headOfDepartment + '\'' +
                ", totalCourses=" + courses.size() +
                '}';
    }
}
