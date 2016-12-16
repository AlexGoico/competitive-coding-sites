import java.util.Scanner;
import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class Football {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);

    String input = in.nextLine();

    int zeroes = 0,
        ones   = 0;
    for (int i = 0; i < input.length(); i++) {
      char c = input.charAt(i);

      if (zeroes == 7 || ones == 7) {
        break;
      }

      if (c == '0') {
        ones = 0;
        zeroes++;
      }
      else if (c == '1') {
        zeroes = 0;
        ones++;
      }
    }

    if (zeroes == 7 || ones == 7) {
      System.out.println("YES");
    }
    else {
      System.out.println("NO");
    }
  }
}
