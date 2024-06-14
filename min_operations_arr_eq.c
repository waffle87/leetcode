// 2602. Minimum Operations to Make All Array Elements Equal
#include "leetcode.h"

/*
 * given an array 'nums' consisting of positive integers. you are also given an
 * integer array 'queries' of size 'm'. for the i'th query, you want to make all
 * of the elements of 'nums' equal to 'queries[i]'. you can perform the
 * following operation on the array any number of times: increase or decrease an
 * element of the array by 1. return an array 'ans' of size 'm' where 'ans[i]'
 * is the minimum number of operations to make all elements of 'nums' equal to
 * 'queries[i]'. note that after each query the array is reset to its original
 * state
 */

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

long long *minOperations(int *nums, int numsSize, int *queries, int queriesSize,
                         int *returnSize) {
  long long *prefix_sum = (long long *)calloc(numsSize + 1, sizeof(long long));
  long long *ans = (long long *)calloc(queriesSize, sizeof(long long));
  qsort(nums, numsSize, sizeof(int), cmp);
  for (int i = 1; i <= numsSize; i++)
    prefix_sum[i] = prefix_sum[i - 1] + nums[i - 1];
  for (int i = 0; i < queriesSize; i++) {
    if (queries[i] < nums[0])
      ans[i] = prefix_sum[numsSize] - (long long)queries[i] * numsSize;
    else if (queries[i] > nums[numsSize - 1])
      ans[i] = (long long)queries[i] * numsSize - prefix_sum[numsSize];
    else {
      int l = 0, r = numsSize - 1, m;
      while (l < r) {
        m = l + ((r - l) >> 1);
        if (nums[m] < queries[i])
          l = m + 1;
        else
          r = m;
      }
      ans[i] = (long long)queries[i] * (2 * l - numsSize) +
               prefix_sum[numsSize] - 2 * prefix_sum[l];
    }
  }
  *returnSize = queriesSize;
  return ans;
}

int main() {
  int n1[] = {3, 1, 6, 8}, q1[] = {1, 5};
  int n2[] = {2, 9, 6, 3}, q2[] = {10};
  int rcs1[] = {}, rcs2[] = {};
  long long *mo1 = minOperations(n1, ARRAY_SIZE(n1), q1, ARRAY_SIZE(q1), rcs1);
  long long *mo2 = minOperations(n2, ARRAY_SIZE(n2), q2, ARRAY_SIZE(q2), rcs2);
  for (int i = 0; i < 2; i++)
    printf("%lld ", mo1[i]); // expect: 14 10
  printf("\n");
  for (int i = 0; i < 1; i++)
    printf("%lld ", mo2[i]); // expect: 20
  printf("\n");
}
