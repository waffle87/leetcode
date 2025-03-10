#include "leetcode.h"

class Solution {
public:
  bool canVisitAllRooms(vvd & rooms) {
    stack<int> dfs;
    dfs.push(0);
    unordered_set<int> seen = {0};
    while (!dfs.empty()) {
      int i = dfs.top();
      dfs.pop();
      for (int j : rooms[i]) {
        if (seen.count(j) == 0) {
          dfs.push(j);
          seen.insert(j);
          if (rooms.size() == seen.size())
            return true;
        }
      }
    }
    return rooms.size() == seen.size();
  }
};

int main() {
  Solution obj;
  vvd rooms = {{1}, {2}, {3}, {}};
  if (obj.canVisitAllRooms(rooms))
    cout << "true";
  else
    cout << "false";
}
