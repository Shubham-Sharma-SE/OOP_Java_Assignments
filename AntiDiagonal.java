import java.util.*;

public class AntiDiagonal {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter size: ");
        int n = sc.nextInt();

        int[][] a = new int[n][n];

        System.out.println("Enter matrix:");

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = sc.nextInt();
            }
        }

        for (int k = 0; k < 2 * n - 1; k++) {

            System.out.print("[");

            for (int i = 0; i < n; i++) {

                int j = k - i;

                if (j >= 0 && j < n) {
                    System.out.print(a[i][j]);

                    if (i + 1 < n && k - (i + 1) >= 0 &&
                        k - (i + 1) < n) {
                        System.out.print(", ");
                    }
                }
            }

            System.out.println("]");
        }
    }
}