// 947. Most Stones Removed with Same Row or Column
#include "leetcode.h"

/*
 * on a 2d plane, we place 'n' stones at some integer coordinate points. each
 * coordinate point may have at most one stone. a stone can be removed if it
 * shares either the same row or the same column as another stone that has not
 * been removed. given an array 'stones' of length 'n' where 'stones[i] = [x_i,
 * y_i]' represents the location of the i'th stone, return the largest possible
 * number of stones that can be removed
 */

class Solution {
public:
  int removeStones(vector<vector<int>> &stones) {
    int n = stones.size(), c = 0;
    unordered_map<int, vector<int>> rows, cols;
    for (int i = 0; i < n; ++i) {
      rows[stones[i][0]].push_back(i);
      cols[stones[i][1]].push_back(i);
    }
    unordered_set<int> seen;
    function<int> dfs;
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
  vvd s1 = {{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}},
           s2 = {{0, 1}, {0, 2}, {1, 1}, {2, 0}, {2, 2}};
  printf("%d\n", obj.removeStones(s1)); // expect: 5
  printf("%d\n", obj.removeStones(s2)); // expect: 3
}
