#include <iostream>

int main()
{
  int m, n, a,
      temp = 0,
      result = 0;

  std::ios::sync_with_stdio(false);
  std::cin >> m >> n >> a;

  if (m >= a || n >= a) {
    result += m / a;
    if (m % a) result++;

    temp += n / a;
    if (n % a) temp++;

    result *= temp;
  }
  else
    result = 1;

  std::cout << result;
}
