#include "leetcode.h"

class Solution {
public:
  int maxScore(vector<int> &cardPoints, int k) {
    int ans = 0, n = cardPoints.size();
    for (int i = n - k; i < n; i++)
      ans += cardPoints[i];
    for (int i = 0, s = ans; i < k; i++) {
      s -= cardPoints[n - k + i];
      s += cardPoints[i];
      ans = max(ans, s);
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
  int k = 3;
  cout << obj.maxScore(cardPoints, k);
}
