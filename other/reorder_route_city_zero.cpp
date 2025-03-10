// 1466. Reorder Routes to Make All Paths Lead to the City Zero
#include "leetcode.h"

/*
 * there are 'n' cities numbered from 0 to 'n - 1' and 'n - 1'
 * roads such that there is only one way to travel between two
 * different cities (this network forms a tree). last year, the
 * ministry of transport decided to orient the roads in one
 * direction because they are too narrow.
 * roads are represented by 'connections' where 'connections[i] = [ai, bi]'
 * represents a road from city 'ai' to city 'bi'.
 * this year, there will be a big event in the capital (city 0),
 * and many people will want to travel to the city. task consists
 * reorienting some roads such that each city can visit city 0.
 * return minimum number of edges changed.
 */

class Solution {
public:
  int minReorder(int n, vvd & connections) {
    vvd ans(n);
    for (auto &c : connections) {
      ans[c[0]].push_back(c[1]);
      ans[c[1]].push_back(-c[0]);
    }
    return dfs(ans, vector<bool>(n) = {}, 0);
  }

private:
  int dfs(vvd & res, vector<bool> visited, int from) {
    auto change = 0;
    visited[from] = true;
    for (auto to : res[from])
      if (!visited[abs(to)])
        change += dfs(res, visited, abs(to)) + (to > 0);
    return change;
  }
};

int main() {
  Solution obj;
  vvd connections1 = {{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}};
  vvd connections2 = {{1, 0}, {1, 2}, {3, 2}, {3, 4}};
  vvd connections3 = {{1, 0}, {2, 0}};
  cout << obj.minReorder(6, connections1) << endl; // expect: 3
  cout << obj.minReorder(5, connections2) << endl; // expect: 2
  cout << obj.minReorder(3, connections3) << endl; // expect: 0
}
