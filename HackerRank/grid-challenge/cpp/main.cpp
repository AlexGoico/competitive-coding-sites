#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define ALL(x) x.begin(), x.end()

bool valid_grid(std::vector<std::string> arr) {
  std::sort(ALL(arr[0]));
  for (int i = 1; i < arr.size(); i++) {
    std::sort(ALL(arr[i]));
    if (arr[i-1] > arr[i])
      return false;
  }

  return true;
}

int main() {
  int t, n;
  std::cin >> t;
    
  while (t--) {
    std::cin >> n;
    std::cin.ignore(1, '\n');

    std::vector<std::string> arr;
    arr.resize(n);
    for (auto& row : arr) {
      row.resize(n);
      std::getline(std::cin, row);
    }
      
    std::cout << (valid_grid(arr) ? "YES" : "NO") << std::endl;
  }
}
