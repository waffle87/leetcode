#include "leetcode.h"

class Solution {
public:
  int maxDistance(vector<int> &position, int m) {
    sort(position.begin(), position.end());
    int ans = 1, i = 999999999;
    while (ans < i) {
      int mid = (ans + i) / 2 + 1;
      if (check(position, m, mid))
        ans = mid;
      else
        i = mid - 1;
    }
    return ans;
  }

private:
  int check(vector<int> &position, int m, int force) {
    int pos = position[0];
    for (auto i = 1; i < position.size() && m > 1; ++i)
      if (position[i] - pos >= force) {
        --m;
        pos = position[i];
      }
    return m < 2;
  }
};

int main() {
  Solution obj;
  vector<int> position = {1, 2, 3, 4, 7};
  int m = 3;
  cout << obj.maxDistance(position, m);
}
