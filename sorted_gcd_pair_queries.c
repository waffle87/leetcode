// 3312. Sorted GCD Pair Queries
#include "leetcode.h"

/*
 * you are given an integer array 'nums' of length 'n' and an integer array
 * 'queries'. let 'gcd_pairs' denote an array obtained by calculating the gcd of
 * all possible '(nums[i], nums[j])' where '0 <= i < j < n' and then sorting
 * these values in ascending order. for each query 'queries[i]', you need to
 * find the element at index 'queries[i]' in 'gcd_pairs'. return an integer
 * array 'answer' where 'answer[i]' is the value at 'gcd_pairs[queries[i]]' for
 * each query.
 */

int lower_bound(long long *arr, int n, long long target) {
  int left = 0, right = n;
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] < target)
      left = mid + 1;
    else
      right = mid;
  }
  return left;
}

int *gcdValues(int *nums, int numsSize, long long *queries, int queriesSize,
               int *returnSize) {
  int max_val = 0;
  for (int i = 0; i < numsSize; i++)
    max_val = fmax(max_val, nums[i]);
  int *freq = (int *)calloc(max_val + 1, sizeof(int));
  for (int i = 0; i < numsSize; i++)
    freq[nums[i]]++;
  long long *cnt = (long long *)calloc(max_val + 1, sizeof(long long));
  for (int gcd_val = max_val; gcd_val >= 1; gcd_val--) {
    long long total = 0;
    for (int mult = gcd_val; mult <= max_val; mult += gcd_val)
      total += freq[mult];
    long long pairs = total * (total - 1) / 2;
    for (int mult = 2 * gcd_val; mult <= max_val; mult += gcd_val)
      pairs -= cnt[mult];
    cnt[gcd_val] = pairs;
  }
  long long *prefix = (long long *)malloc(max_val * sizeof(long long)), sum = 0;
  int *vals = (int *)malloc(max_val * sizeof(int)), n = 0;
  for (int gcd_val = 1; gcd_val <= max_val; gcd_val++)
    if (cnt[gcd_val] > 0) {
      sum += cnt[gcd_val];
      prefix[n] = sum;
      vals[n] = gcd_val;
      n++;
    }
  int *ans = (int *)malloc(queriesSize * sizeof(int));
  *returnSize = queriesSize;
  for (int i = 0; i < queriesSize; i++) {
    int idx = lower_bound(prefix, n, queries[i] + 1);
    ans[i] = vals[idx];
  }
  free(freq);
  free(cnt);
  free(prefix);
  free(vals);
  return ans;
}

int main() {
  int n1[] = {2, 3, 4}, r1[] = {1, 2, 2}, rs1;
  int n2[] = {4, 4, 2, 1}, r2[] = {4, 2, 1, 1}, rs2;
  int n3[] = {2, 2}, r3[] = {2, 2}, rs3;
  long long q1[] = {0, 2, 2}, q2[] = {5, 3, 1, 0}, q3[] = {0, 0};
  int *gcdv1 = gcdValues(n1, ARRAY_SIZE(n1), q1, ARRAY_SIZE(q1), &rs1);
  int *gcdv2 = gcdValues(n2, ARRAY_SIZE(n2), q2, ARRAY_SIZE(q2), &rs2);
  int *gcdv3 = gcdValues(n3, ARRAY_SIZE(n3), q3, ARRAY_SIZE(q3), &rs3);
  for (int i = 0; i < rs1; i++) {
    printf("%d ", gcdv1[i]);
    assert(gcdv1[i] == r1[i]);
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    printf("%d ", gcdv2[i]);
    assert(gcdv2[i] == r2[i]);
  }
  printf("\n");
  for (int i = 0; i < rs3; i++) {
    printf("%d ", gcdv3[i]);
    assert(gcdv3[i] == r3[i]);
  }
  printf("\n");
  free(gcdv1);
  free(gcdv2);
  free(gcdv3);
}
