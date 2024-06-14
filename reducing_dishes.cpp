// 1402. Reducing Dishes
#include "leetcode.h"

/*
 * a chef has collected data on the 'satisfaction' level of his 'n' dishes. chef
 * can cook any dish in 1 unit of time. like-time coefficient of a dish is
 * defined as the time taken to cook that dish including previous dishes
 * multiplied by its satisfaction level - eg. 'time[i] * satisfaction[i]'.
 * return maximum sum of like-time coefficient that the chef can obtain after
 * dishes preparation. dishes can be prepared in any order and the chef can
 * discard some dishes to get this maximum value.
 */

class Solution {
public:
  int maxSatisfaction(vector<int> &satisfaction) {
    sort(satisfaction.begin(), satisfaction.end(), greater<int>());
    int n = satisfaction.size(), pre_sum = 0, ans = 0;
    for (int i = 0; i < n; i++) {
      pre_sum += satisfaction[i];
      if (pre_sum < 0)
        break;
      ans += pre_sum;
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> s1 = {-1, -8, 0, 5, -9};
  vector<int> s2 = {4, 3, 2};
  vector<int> s3 = {-1, -4, -5};
  printf("%d\n", obj.maxSatisfaction(s1)); // expect: 14
  printf("%d\n", obj.maxSatisfaction(s2)); // expect: 20
  printf("%d\n", obj.maxSatisfaction(s3)); // expect: 0
}
