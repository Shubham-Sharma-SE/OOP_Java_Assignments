
import javax.swing.JOptionPane;

public class Popup {

    public static void main(String[] args) {

        String name = JOptionPane.showInputDialog("Enter Your Name");
        JOptionPane.showMessageDialog(null, "Hello" + name);
        int age = Integer.parseInt(JOptionPane.showInputDialog("Enter Your age"));
        JOptionPane.showMessageDialog(null, "Your age is" + age);
        double height = Double.parseDouble(JOptionPane.showInputDialog("Enter Your height"));
        JOptionPane.showMessageDialog(null, "Your height is" + height + "cm");

    }
}
