// 1695. Maximum Erasure Value
#include "leetcode.h"

/*
 * you are given an array of posiive integers 'nums' and want to erase a
 * subarray containing unique elements. the score you get by erasing the
 * subarray is equal to the sum of its elements. return the maximum score you
 * can get by erasing exactly one subarray. an array 'b' is called to be a
 * subarray of 'a' if it forms a contiguous subsequence of 'a' that is if it is
 * equal to 'a[l], a[l + 1], ..., a[r]' for some '(l, r)'
 */

static u_char vis[1250];

bool test(int a) { return vis[a >> 3] & (1 << (a & 7)) ? true : false; }

void set(int a) { vis[a >> 3] |= 1 << (a & 7); }

void reset(int a) { vis[a >> 3] &= ~(1 << (a & 7)); }

int maximumUniqueSubarray(int *nums, int numsSize) {
  int ans = 0, sum = 0;
  memset(vis, 0, sizeof(vis));
  for (int i = 0, j = 0; i < numsSize; i++) {
    while (test(nums[i] - 1)) {
      sum -= nums[j];
      reset(nums[j++] - 1);
    }
    sum += nums[i];
    set(nums[i] - 1);
    ans = fmax(ans, sum);
  }
  return ans;
}

int main() {
  int n1[] = {4, 2, 4, 5, 6}, n2[] = {5, 2, 1, 2, 5, 2, 1, 2, 5};
  printf("%d\n", maximumUniqueSubarray(n1, ARRAY_SIZE(n1))); // expect: 17
  printf("%d\n", maximumUniqueSubarray(n2, ARRAY_SIZE(n2))); // expect: 8
}
