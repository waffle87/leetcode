// 220. Contains Duplicate III
#include "leetcode.h"

/*
 * given an integer array 'nums' and two integers 'index_diff'
 * and 'value_diff'. find a pai of indices '(i, j)' such that:
 * i != j
 * abs(i - j) <= index_diff
 * abs(num[i] - num[j]) <= value_diff
 * return true if such pair exists or false otherwise
 */

class Solution {
public:
  bool containsNearbyAlmostDuplicate(vector<int> &nums, int index_diff,
                                     int value_diff) {
    int n = nums.size();
    if (n == 0 || index_diff < 0 || value_diff < 0)
      return false;
    unordered_map<int, int> buckets;
    for (int i = 0; i < n; i++) {
      int b = nums[i] / ((long)value_diff + 1);
      if (nums[i] < 0)
        --b;
      if (buckets.find(b) != buckets.end())
        return true;
      else {
        buckets[b] = nums[i];
        if (buckets.find(b - 1) != buckets.end() &&
            (long)nums[i] - buckets[b - 1] <= value_diff)
          return true;
        if (buckets.find(b + 1) != buckets.end() &&
            (long)buckets[b + 1] - nums[i] <= value_diff)
          return true;
        if (buckets.size() > index_diff) {
          int remove = nums[i - index_diff] / ((long)value_diff + 1);
          if (nums[i - index_diff] < 0)
            --remove;
          buckets.erase(remove);
        }
      }
    }
    return false;
  }
};

int main() {
  Solution obj;
  vector<int> n1 = {1, 2, 3, 1}, n2 = {1, 5, 9, 1, 5, 9};
  printf("%d\n", obj.containsNearbyAlmostDuplicate(n1, 3, 0)); // expect: 1
  printf("%d\n", obj.containsNearbyAlmostDuplicate(n2, 2, 3)); // expect: 0
}
