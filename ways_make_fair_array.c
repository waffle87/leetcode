// 1664. Ways to Make a Fair Array
#include "leetcode.h"

/*
 * you are given an integer array 'nums'. you can choose exactly one index and
 * remove the element. notice that the index of the elements may change after
 * the removal. for example, if 'nums = [6,1,7,4,1]' choosing to remove index 1
 * results in 'nums = [6,7,4,1]'. an array is fair is the sum of the odd indexed
 * values equals the sume of the even indexed values. return the number of
 * indices that you could choose such that after the removal, 'nums' is fair.
 */

int waysToMakeFair(int *nums, int nums_size) {
  int n = nums_size, ans = 0;
  int *pre_sum = (int *)malloc((n + 4) * sizeof(int));
  int *suf_sum = (int *)malloc((n + 4) * sizeof(int));
  pre_sum[0] = 0, pre_sum[1] = 0, pre_sum[n + 2] = 0, pre_sum[n + 3] = 0;
  suf_sum[0] = 0, suf_sum[1] = 0, suf_sum[n + 2] = 0, suf_sum[n + 3] = 0;
  for (int i = 2; i < n + 2; i++)
    pre_sum[i] = pre_sum[i - 2] + nums[i - 2];
  for (int i = n + 1; i > 1; i--)
    suf_sum[i] = suf_sum[i + 2] + nums[i - 2];
  for (int i = 2; i <= n + 1; i++)
    if (pre_sum[i - 2] + suf_sum[i + 1] == pre_sum[i - 1] + suf_sum[i + 2])
      ans++;
  free(pre_sum), free(suf_sum);
  return ans;
}

int main() {
  int n1[] = {2, 1, 6, 4}, n2[] = {1, 1, 1}, n3[] = {1, 2, 3};
  printf("%d\n", waysToMakeFair(n1, ARRAY_SIZE(n1))); // expect: 1
  printf("%d\n", waysToMakeFair(n2, ARRAY_SIZE(n2))); // expect: 3
  printf("%d\n", waysToMakeFair(n3, ARRAY_SIZE(n3))); // expect: 0
}
