#include "leetcode.h"

class Solution {
public:
  int maximumBags(vector<int> &capacity, vector<int> &rocks,
                  int additionalRocks) {
    vector<int> count;
    int n = rocks.size(), ans;
    for (int i = 0; i < n; ++i)
      count.push_back(capacity[i] - rocks[i]);
    sort(count.begin(), count.end());
    for (ans = 0; ans < n && additionalRocks >= count[ans]; ++ans)
      additionalRocks -= count[ans];
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> capacity = {2, 3, 4, 5}, rocks = {1, 2, 4, 4};
  cout << obj.maximumBags(capacity, rocks, 2);
}
