#include "leetcode.h"

class Solution {
public:
  int minTime(int n, vvd & edges, vector<bool> &hasApple) {
    unordered_map<int, int> um;
    int ans = 0;
    sort(edges.begin(), edges.end());
    for (auto const &e : edges) {
      if (um.count(e[1]) > 0)
        um[e[0]] = e[1];
      else
        um[e[1]] = e[0];
    }
    for (int i = 0; i < hasApple.size(); ++i) {
      if (!hasApple[i])
        continue;
      int parent = i;
      while (parent != 0 && um[parent] >= 0) {
        auto tmp = um[parent];
        um[parent] = -1;
        parent = tmp;
        ans += 2;
      }
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vvd edges = {{0, 1}, {0, 2}, {1, 4}, {1, 5}, {2, 3}, {2, 6}};
  vector<bool> hasApple1 = {false, false, true, false, true, true, false},
               hasApple2 = {false, false, true, false, false, true, false},
               hasApple3 = {false, false, false, false, false, false, false};
  cout << obj.minTime(7, edges, hasApple1) << endl; // expect: 8
  cout << obj.minTime(7, edges, hasApple2) << endl; // expect: 6
  cout << obj.minTime(7, edges, hasApple3) << endl; // expect: 0
}
