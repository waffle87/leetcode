#include "leetcode.h"

class Solution {
public:
  int candy(vector<int> &ratings) {
    if (ratings.size() <= 1)
      return ratings.size();
    int ans = 0, up = 0, down = 0, oldSign = 0;
    for (int i = 1; i < ratings.size(); i++) {
      int newSign = ratings[i] > ratings[i - 1]   ? 1
                    : ratings[i] < ratings[i - 1] ? -1
                                                  : 0;
      if ((oldSign > 0 && newSign == 0) || (oldSign < 0 && newSign >= 0)) {
        ans += helper(up) + helper(down) + max(up, down);
        up = 0;
        down = 0;
      }
      if (newSign > 0)
        up++;
      if (newSign < 0)
        down++;
      if (newSign == 0)
        ans++;
      oldSign = newSign;
    }
    ans += ramp(up) + ramp(down) + max(up, down) + 1;
  }

private:
  int helper(int n) { return (n * (n + 1)) / 2; }
};

int main() {
  Solution obj;
  vector<int> ratings = {};
  cout << obj.candy(ratings);
}
