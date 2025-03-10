// 1493. Longest Subarray of 1's After Deleting One Element
#include "leetcode.h"

/*
 * given a binary array 'nums', you should delete one element from it. return
 * the size of the longest non-empty subarray containing only 1's in the
 * resulting array. return 0 if there is no such subarray.
 */

class Solution {
public:
  int longestSubarray(vector<int> &nums) {
    int ans = 0;
    for (int i = 0, j = 0, skip = 0; i < nums.size(); ++i) {
      skip += !nums[i];
      if (skip > 1)
        skip -= !nums[j++];
      ans = max(ans, i - j);
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> n1 = {1, 1, 0, 1}, n2 = {0, 1, 1, 1, 0, 1, 1, 0, 1},
              n3 = {1, 1, 1};
  printf("%d\n", obj.longestSubarray(n1)); // expect: 3
  printf("%d\n", obj.longestSubarray(n2)); // expect: 5
  printf("%d\n", obj.longestSubarray(n3)); // expect: 2
}
