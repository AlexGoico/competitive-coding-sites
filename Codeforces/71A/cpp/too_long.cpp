#include <iostream>
#include <vector>
#include <string>

int main()
{
  int n;
  
  std::ios::sync_with_stdio(false);
  std::cin >> n;
  std::cin.get();

  std::string strs[n];
  for (int i = 0; i < n; i++)
    std::getline(std::cin, strs[i]);

  for (auto str : strs)
    if (str.size() > 10)
      std::cout << str[0] << str.substr(1, str.size() - 2).size()
                << str[str.size() - 1] << std::endl;
    else
      std::cout << str << std::endl;
}
