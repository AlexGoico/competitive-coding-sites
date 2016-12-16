import java.util.Scanner;
import java.util.List;
import java.util.stream.Collectors;

public class HelpfulMath {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);

    String line = in.nextLine();

    List<Integer> l =
      line.chars()
      .map(c -> (char) c)
      .filter(c -> c != '+')
      .map(c -> Character.getNumericValue(c))
      .sorted()
      .collect(Collectors.toList);

    String delim = "";
    for (Integer i : al) {
      System.out.print(delim + i);
      delim = "+";
    }
  }
}

