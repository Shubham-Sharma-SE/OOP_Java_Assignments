import java.util.Scanner;

class Shape
{
    Scanner sc = new Scanner(System.in);

    void getInputs()
    {
        System.out.println("Enter shape inputs:");
    }

    void setArea(double side)
    {
        System.out.println("Area of Square = " + (side * side));
    }

    void setArea(double radius, int type)
    {
        System.out.println("Area of Circle = " + (Math.PI * radius * radius));
    }

    void setArea(double base, double height)
    {
        System.out.println("Area of Triangle = " + (0.5 * base * height));
    }
}

class Triangle extends Shape
{
    double base, height;

    void getInputs()
    {
        System.out.print("Enter base: ");
        base = sc.nextDouble();

        System.out.print("Enter height: ");
        height = sc.nextDouble();
    }

    void calculateArea()
    {
        setArea(base, height);
    }
}

class Square extends Shape
{
    double side;

    void getInputs()
    {
        System.out.print("Enter side: ");
        side = sc.nextDouble();
    }

    void calculateArea()
    {
        setArea(side);
    }
}

class Circle extends Shape
{
    double radius;

    void getInputs()
    {
        System.out.print("Enter radius: ");
        radius = sc.nextDouble();
    }

    void calculateArea()
    {
        setArea(radius, 1);
    }
}

public class Area
{
    public static void main(String args[])
    {
        Triangle t = new Triangle();
        Square s = new Square();
        Circle c = new Circle();

        System.out.println("TRIANGLE");
        t.getInputs();
        t.calculateArea();

        System.out.println("\nSQUARE");
        s.getInputs();
        s.calculateArea();

        System.out.println("\nCIRCLE");
        c.getInputs();
        c.calculateArea();
    }
}
