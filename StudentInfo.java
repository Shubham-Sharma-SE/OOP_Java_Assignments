import java.util.Scanner;
class Student{

  private int rollno;
  private String name;
  private String classname;
  private char div;
  void Accept(Scanner sc){
    System.out.print("Enter Roll No: ");
    this.rollno = sc.nextInt();
    sc.nextLine(); 
    System.out.print("Enter Name: ");
    this.name = sc.nextLine();
    System.out.print("Enter Class Name: ");
    this.classname = sc.nextLine();
    System.out.print("Enter Division: ");
    this.div = sc.next().charAt(0);
  }
  void display(Scanner sc){
    
     System.out.println("Roll No: " + this.rollno);
     System.out.println("Name: " + this.name);      
     System.out.println("Class Name: " + this.classname);
     System.out.println("Division: " + this.div);

  }

  }

public class StudentInfo {  
public static void main(String[] args) {
Scanner sc =new Scanner(System.in);
System.out.print("Enter number of students: ");
int totalStudents = sc.nextInt();
Student[] students = new Student[totalStudents];

for(int i = 0; i < totalStudents; i++){
    students[i] = new Student();
    System.out.println("Enter details for student " + (i+1) + ":");
    students[i].Accept(sc);}

for(Student student : students){
    System.out.println("\nStudent Details:");
    student.display(sc);
}
   }
}