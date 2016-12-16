import java.util.Scanner;

public class PetyaStrings {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);

    String input1 = in.nextLine();
    String input2 = in.nextLine();

    int result = 0;
    for (int i = 0; i < Math.min(input1.length(), input2.length()); i++) {
      char c1 = Character.toLowerCase(input1.charAt(i));
      char c2 = Character.toLowerCase(input2.charAt(i));

      if (c1 < c2) {
        result = -1;
        break;
      }
      else if (c1 > c2) {
        result = 1;
        break;
      }
    }

    System.out.println(result);
  }
}
