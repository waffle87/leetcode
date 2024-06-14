#include "leetcode.h"

class Solution {
public:
  int furthestBuilding(vector<int> &heights, int bricks, int ladders) {
    int n = heights.size() - 1;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
      int diff = heights[i + 1] - heights[i];
      if (diff > 0) {
        if (ladders)
          pq.push(-diff), ladders--;
        else if (!pq.empty() && diff > -pq.top()) {
          pq.push(-diff);
          bricks += pq.top();
          pq.pop();
        } else
          bricks -= diff;
        if (bricks < 0)
          return i;
      }
    }
    return n;
  }
};

int main() {
  Solution obj;
  vector<int> heights = {4, 2, 7, 6, 9, 14, 12};
  int bricks = 5, ladders = 1;
  cout << obj.furthestBuilding(heights, bricks, ladders);
}
