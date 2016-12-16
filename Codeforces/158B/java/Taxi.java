import java.util.Scanner;
import java.util.HashMap;

public class Taxi {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    HashMap<Integer, Integer> freqMap = new HashMap<>();
    freqMap.put(1, 0);
    freqMap.put(2, 0);
    freqMap.put(3, 0);
    freqMap.put(4, 0);

    int n = in.nextInt();
    for (int i = 0; i < n; i++) {
      int cur = in.nextInt();

      freqMap.replace(cur, freqMap.get(cur) + 1);
    }

    // The differences of accumulated 3's and 1's equals the sum
    // of 3's and 1's that can be joined in one trip. The leftovers
    // cannot be joined with any other numbers.
    int differences = Math.abs(freqMap.get(3) - freqMap.get(1));
    int leftovers = Math.max(freqMap.get(3), freqMap.get(1)) - differences;
    int twoPairs = freqMap.get(2) / 2;
    int twoLeftovers = freqMap.get(2) % 2;
    int totalTrips = 
      freqMap.get(4) + twoPairs + twoLeftovers + differences + leftovers;

    System.out.println(totalTrips);
  }
}
