#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <map>
#include <string>
#include <utility>

using std::pair;
using position = pair<int, int>;
using grid = std::array<std::array<position, 8>, 8>;

std::vector<position> adjacent(position x, bool discovered[8][8])
{
  std::vector<position> ret;
  pair<int, int> temp[8] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1},
                             {-1, 1}, {-1, -1}, {1, 1}, {1, -1} };
  for (auto t : temp) {
    position p = std::make_pair(x.first + t.first, x.second + t.second);
    if (!discovered[p.first][p.second] &&
        p.first >= 0 && p.second >= 0  &&
        p.first <  8 && p.second <  8)
      ret.push_back(p);
  }

  return ret;
}

grid bfs(position s, position t)
{
  grid parent;
  bool discovered[8][8] {};
  parent[s.first][s.second] = std::make_pair(-1, -1);
  discovered[s.first][s.second] = true;

  std::queue<position> q{};
  q.push(s);

  bool finished{};
  while (!q.empty() && !finished) {
    position cur = q.front();
    q.pop();
    for (position n : adjacent(cur, discovered)) {
      // n indexes are the vertex storing the vertex point of the parent
      parent[n.first][n.second] = cur;
      if (cur == t) {
        finished = true;
        break;
      }
      q.push(n);
      discovered[n.first][n.second] = true;
    }
  }

  return parent;
}

std::map<pair<int, int>, std::string> make_move_map()
{
  std::map<pair<int, int>, std::string> m;
  m[{-1,  1}] = "LU";
  m[{ 0,  1}] = "U";
  m[{ 1,  1}] = "RU";
  m[{-1,  0}] = "L";
  m[{ 1,  0}] = "R";
  m[{-1, -1}] = "LD";
  m[{ 0, -1}] = "D";
  m[{ 1, -1}] = "RD";
  return m;
}

void print_parent_grid(grid g)
{
  std::cout << "\n------------------------------------------------\n";
  for (int j = 7; j >= 0; j--) {
    for (int i = 0; i < 8; i++) {
      std::cout.width(2);
      std::cout << g[i][j].first << " ";
      std::cout.width(2);
      std::cout << g[i][j].second << "|";
    }
    std::cout << "\n------------------------------------------------\n";
  }
  std::cout << std::endl;
}

std::vector<std::string> sp(position s, position t)
{
  std::vector<std::string> ret;

  auto move_map{make_move_map()};
  position end = std::make_pair(-1, -1);

  grid parent = bfs(s, t);
  print_parent_grid(parent);
  for (position prev = t, cur = parent[prev.first][prev.second];
       cur != end;
       prev = cur, cur = parent[prev.first][prev.second]) {
    std::string move = move_map[{prev.first - cur.first,
                                 prev.second - cur.second}];
    ret.push_back(move);
  }

  return ret;
}

position pos_to_pair(std::string pos)
{
  int hor =  pos[0] - 'a';
  int ver = (pos[1] - '0') - 1;
  return std::make_pair(hor, ver);
}

int main()
{
  std::string start, end;
  std::getline(std::cin, start);
  std::getline(std::cin, end);

  std::vector<std::string> sol = sp(pos_to_pair(start), pos_to_pair(end));
  std::cout << sol.size();
  for (auto step : sol)
    std::cout << "\n" << step;
}
