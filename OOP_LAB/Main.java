import java.util.Scanner;

public class Main {

    static class StudentResult {
        private int rollNo;
        private String name;
        private int marks;
        private char grade;

        public void setRollNo(int rollNo) {
            this.rollNo = rollNo;
        }

        public void setName(String name) {
            this.name = name;
        }

        public void setMarks(int marks) {
            this.marks = marks;
            calculateGrade();
        }

        public int getRollNo() {
            return rollNo;
        }

        public String getName() {
            return name;
        }

        public int getMarks() {
            return marks;
        }

        public char getGrade() {
            return grade;
        }

        private void calculateGrade() {
            if (marks >= 90) {
                grade = 'O';
            } else if (marks >= 80) {
                grade = 'A';
            } else if (marks >= 70) {
                grade = 'B';
            } else if (marks >= 50) {
                grade = 'C';
            } else {
                grade = 'F';
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        StudentResult sr = new StudentResult();

        System.out.print("Enter the Name of the Student: ");
        sr.setName(sc.nextLine());

        System.out.print("Enter the marks of the student: ");
        sr.setMarks(sc.nextInt());

        System.out.print("Enter the Roll No of the student: ");
        sr.setRollNo(sc.nextInt());

        System.out.println("\n--- Student Result ---");
        System.out.println("The Name of the Student is: " + sr.getName());
        System.out.println("Roll No: " + sr.getRollNo());
        System.out.println("Marks: " + sr.getMarks());
        System.out.println("Grade: " + sr.getGrade());

        sc.close();
    }
}
