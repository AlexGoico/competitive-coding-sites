#include <iostream>
#include <string>

int main()
{
  std::string ans{"NO"};
  int w;

  std::cin >> w;

  for (int i = 1; i < w; i++)
    if (i % 2 == 0 && (w-i) % 2 == 0) {
      ans = "YES";
      break;
    }

  std::cout << ans;
}
