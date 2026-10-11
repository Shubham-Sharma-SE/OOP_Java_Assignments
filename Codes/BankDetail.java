class Bank {
String employeeName;
int employeeId;
double employeeSalary;
    Bank() {

      employeeName = "Default Name";
      employeeId = 0;
      employeeSalary = 0.0;

    }

    Bank(String name, int id, double salary) {
        employeeName = name;
        employeeId = id;
        employeeSalary = salary;

    }
    void display() {
        System.out.println("Employee Name: " + employeeName);
        System.out.println("Employee ID: " + employeeId);
        System.out.println("Employee Salary: " + employeeSalary);
    }

}

public class BankDetail {

    public static void main(String[] args) {
        Bank bb = new Bank();
        System.out.println("====================================");
        System.out.println("this is the default constructor");
        bb.display();
        System.out.println("====================================");
        System.out.println("this is the parameterized constructor");
        Bank bb1 = new Bank("John Doe", 12345, 50000.0);
        bb1.display();
        System.out.println("====================================");

    }
}
