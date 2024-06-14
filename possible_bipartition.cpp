#include "leetcode.h"

class Solution {
public:
  bool possibleBipartition(int n, vvd(int) & dislikes) {
    enum color { green = -1, uncolored, blue };
    if (n == 1 || dislikes.size() == 0)
      return true;
    unordered_map<int, vector<int>> dislikeTable;
    unordered_map<int, int> colorTable;
    function<bool(int, int)> helper;
    helper = [&](int personID, int color) -> bool {
      colorTable[personID] = color;
      for (const int &other : dislikeTable[personID]) {
        if (colorTable[other] == color)
          return false;
        if (colorTable[other] == uncolored && (!helper(other, -color)))
          return false;
      }
      return true;
    };
    for (const auto &relation : dislikes) {
      int p1 = relation[0], p2 = relation[1];
      dislikeTable[p1].emplace_back(p2);
      dislikeTable[p2].emplace_back(p1);
    }
    for (int i = 1; i <= n; i++)
      if (colorTable[i] == uncolored && (!helper(i, blue)))
        return false;
    return true;
  }
};

int main() {
  Solution obj;
  vvd(int) dislikes1 = {{1, 2}, {1, 3}, {2, 4}},
           dislikes2 = {{1, 2}, {1, 3}, {2, 3}},
           dislikes3 = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {1, 5}};
  testBool(obj.possibleBipartition(4, dislikes1));
  // true: [2,3] [1,4]
  testBool(obj.possibleBipartition(3, dislikes2));
  // false
  testBool(obj.possibleBipartition(5, dislikes3));
  // false
}
