//difference between largest and smallest term in a array
import java.util.*;

public class Difference {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter array length: ");
        int n = sc.nextInt();

        int[] a = new int[n];

        System.out.println("Enter elements:");

        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        int largest = a[0];
        int smallest = a[0];

        for (int i = 1; i < n; i++) {

            if (a[i] > largest) {
                largest = a[i];
            }

            if (a[i] < smallest) {
                smallest = a[i];
            }
        }

        int difference = largest - smallest;

        System.out.println("Difference = " + difference);
    }
}