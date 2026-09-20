class Bill {

    double findPrice(int itemId) {

        if (itemId == 1001) {
            return 25;
        }
        else if (itemId == 1002) {
            return 20;
        }

        return 0;
    }

    double findPrice(String brandName, String itemType, int size) {

        if (brandName.equals("Puma") &&
            itemType.equals("T-shirt") &&
            (size == 34 || size == 36)) {

            return 25;
        }

        if (brandName.equals("Puma") &&
            itemType.equals("skirt") &&
            size == 38) {

            return 20;
        }

        return 0;
    }
}

public class Tester2{

    public static void main(String[] args) {

        Bill b = new Bill();

        System.out.println(b.findPrice(1001));

        System.out.println(
            b.findPrice("Puma", "T-shirt", 34)
        );

        System.out.println(
            b.findPrice("Puma", "skirt", 38)
        );

        System.out.println(
            b.findPrice(9999)
        );
    }
}