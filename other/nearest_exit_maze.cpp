#include "leetcode.h"

class Solution {
public:
  int nearestExit(vvd(char) & maze, vector<int> &entrance) {
    int m = maze.size(), n = maze[0].size();
    int dirs[5] = {0, -1, 0, 1, 0};
    auto isExit = [&](int i, int j) -> int {
      return (i != entrance[0] || j != entrance[1]) &&
             (i * j == 0 || i == m - 1 || j == n - 1);
    };
    deque<array<int, 3>> dqa = {{entrance[0], entrance[1], 0}};
    while (!dqa.empty()) {
      auto [i, j, s] = dqa.front();
      dqa.pop_front();
      for (int d = 0; d < 4; ++d) {
        int i2 = i + dirs[d];
        int j2 = j + dirs[d + 1];
        if (i2 < 0 || i2 >= m || j2 < 0 || j2 >= n || maze[i2][j2] == '+')
          continue;
        maze[i2][j2] = '+';
        if (isExit(i2, j2))
          return s + 1;
        dqa.push_back({i2, j2, s + 1});
      }
    }
    return -1;
  }
};

int main() {
  Solution obj;
  vvd(char)
      maze = {{'+', '+', '.', '+'}, {'.', '.', '.', '+'}, {'+', '+', '+', '.'}};
  vector<int> entrance = {1, 2};
  cout << obj.nearestExit(maze, entrance);
}
