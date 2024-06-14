// 2134. Minimum Swaps to Group All 1's Together II
#include "leetcode.h"

/*
 * a swap is defined as taking two distinct position in an array and swapping
 * the values in them. a circular array is defined as an array where we consider
 * the first element and the last element to adjacent. given a binary circular
 * array 'nums', return the minimum number of swaps required to group all 1's
 * preent in the array together at any location.
 */

class Solution {
public:
  int minSwaps(vector<int> &nums) {
    int n = nums.size(), k = 0;
    for (int i = 0; i < n; i++)
      k += (nums[i] == 1);
    nums.insert(nums.end(), nums.begin(), nums.end());
    int ans = n, i = 0, j = 0, l = 0;
    while (j < 2 * n) {
      l += (nums[j] == 1);
      if (j - i + 1 == k) {
        ans = min(ans, k - l);
        l -= (nums[i] == 1);
        i++;
      }
      j++;
    }
    return ans == n ? 0 : ans;
  }
};

int main() {
  Solution obj;
  vector<int> n1 = {0, 1, 0, 1, 1, 0, 0}, n2 = {0, 1, 1, 1, 0, 0, 1, 1, 0},
              n3 = {1, 1, 0, 0, 1};
  printf("%d\n", obj.minSwaps(n1)); // expect: 1
  printf("%d\n", obj.minSwaps(n2)); // expect: 2
  printf("%d\n", obj.minSwaps(n3)); // expect: 0
}
