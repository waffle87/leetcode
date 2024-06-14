#include "leetcode.h"

class Solution {
public:
  int removeStones(vvd(int) & stones) {
    int n = stones.size(), c = 0;
    unordered_map<int, vector<int>> rows, cols;
    for (int i = 0; i < n; ++i) {
      rows[stones[i][0]].push_back(i);
      cols[stones[i][1]].push_back(i);
    }
    unordered_set<int> seen;
    function<int(int)> dfs;
    dfs = [&](int i) -> int {
      if (seen.count(i))
        return 0;
      seen.insert(i);
      int j = stones[i][0], k = stones[i][1];
      for (auto r : rows[j])
        dfs(r);
      for (auto c : cols[k])
        dfs(c);
      return 1;
    };
    for (int i = 0; i < n; ++i)
      c += dfs(i);
    return n - c;
  }
};

int main() {
  Solution obj;
  vvd(int) stones = {{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};
  cout << obj.removeStones(stones);
}
