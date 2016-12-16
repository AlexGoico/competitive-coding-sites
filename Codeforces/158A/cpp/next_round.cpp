#include <iostream>
#include <vector>

int main()
{
  std::vector<int> v;
  int n, k;

  std::cin >> n >> k;

  v.resize(n);

  for (int i = 0; i < n; i++)
    std::cin >> v[i];

  int winners = 0;
  for (int i = 0; i < n && v[i] > 0 && v[i] >= v[k-1]; i++)
    winners++;

  std::cout << winners;
}
