// 2945. Find Maximum Non-decreasing Array Length
#include "leetcode.h"

/*
 * you are given a 0-indexed integer array 'nums'. you can perform any number of
 * operations, where each operation involves selecting a subarray of the array
 * and replacing it with the sum of its elements. for example, if the given
 * array is '[1, 3, 5, 6]' and you select '[3, 5]', the array will convert to
 * '[1, 8, 6]'. return the maximum length of a non-decreasing array that can be
 * made after applying the aforementioned operations. a subarray is a contiguous
 * non-empty sequence of elements within an array
 */

struct node {
  int px;
  int rx;
  int ml;
};

int findMaximumLength(int *nums, int numsSize) {
  struct node *dp = (struct node *)malloc((numsSize + 1) * sizeof(int));
  int dpl = 1, px = 0;
  memset(&dp[0], 0, sizeof(struct node));
  for (int i = 1, j = 0; i <= numsSize; ++i) {
    px += nums[i - 1];
    if (j >= dpl)
      j = dpl - 1;
    while (j + 1 < dpl) {
      if (!(px >= dp[j + 1].rx + dp[j + 1].px))
        break;
      ++j;
    }
    int ml = dp[j].ml + 1, rx = px - dp[j].px;
    while (1) {
      if (rx + px >= dp[dpl - 1].rx + dp[dpl - 1].px)
        break;
      --dpl;
    }
    dp[dpl].px = px;
    dp[dpl].rx = rx;
    dp[dpl].ml = ml;
  }
  int ans = dp[dpl - 1].ml;
  free(dp);
  return ans;
}

int main() {
  int n1[] = {5, 2, 2}, n2[] = {1, 2, 3, 4}, n3[] = {4, 3, 2, 6};
  printf("%d\n", findMaximumLength(n1, ARRAY_SIZE(n1))); // expect: 1
  printf("%d\n", findMaximumLength(n2, ARRAY_SIZE(n2))); // expect: 4
  printf("%d\n", findMaximumLength(n3, ARRAY_SIZE(n3))); // expect: 3
}
