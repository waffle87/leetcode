#include "leetcode.h"

class Solution {
public:
  int earliestFullBloom(vector<int> &plantTime, vector<int> &growTime) {
    int n = plantTime.size();
    vector<pair<int, int>> times(n);
    for (int i = 0; i < n; i++) {
      times[i].first = -growTime[i];
      times[i].second = plantTime[i];
    }
    sort(times.begin(), times.end());
    int total = 0, curr = 0;
    for (int i = 0; i < n; i++) {
      total = max(total, curr + times[i].second - times[i].first);
      curr += times[i].second;
    }
    return total;
  }
};

int main() {
  Solution obj;
  vector<int> plantTime = {1, 4, 3}, growTime = {2, 3, 1};
  cout << obj.earliestFullBloom(plantTime, growTime);
}
