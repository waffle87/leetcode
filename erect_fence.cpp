#include "leetcode.h"

class Solution {
public:
  using tree = vector<int>;
  vector<tree> outerTrees(vector<tree> &trees) {
    auto cross = [](tree &a, tree &b, tree &c) -> int {
      return (c[1] - a[1]) * (a[0] - b[0]) - (a[1] - b[1]) * (c[0] - a[0]);
    };
    sort(trees.begin(), trees.end());
    deque<tree> dv;
    for (tree t : trees) {
      while (dv.size() >= 2 &&
             cross(dv[dv.size() - 1], dv[dv.size() - 2], t) < 0)
        dv.pop_back();
      dv.push_back(t);
      while (dv.size() >= 2 && cross(dv[0], dv[1], t) > 0)
        dv.pop_front();
      dv.push_front(t);
    }
    set<tree> unique(dv.begin(), dv.end());
    return vector<tree>(unique.begin(), unique.end());
  }
};

int main() {
  Solution obj;
  vvd trees = {{1, 1}, {2, 2}, {2, 0}, {2, 4}, {3, 3}, {4, 2}};
}
