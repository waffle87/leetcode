// 2913. Subarrays Distinct Element Sum of Squares 1
#include "leetcode.h"

/*
 * you are given a 0-indexed integer array 'nums'. the distinct count of a
 * subarray of 'nums' is defined as: let 'nums[i .. j]' be a subarray of 'nums'
 * consisting of all the indices fom 'i' to 'j' such that '0 <= i <= j <
 * nums.length'. then the number of distinct values in 'nums[i .. j]' is called
 * the distinct count of 'nums[i .. j]'. return the sum of the squares of
 * distinct counts of all subarrays of 'nums'.
 */

int sumCounts(int *nums, int numsSize) {
  int ans = 0;
  for (int i = 0; i < numsSize; ++i) {
    int hash[101] = {};
    for (int j = i; j < numsSize; ++j) {
      hash[nums[j]]++;
      int cnt = 0;
      for (int k = 0; k < 101; ++k)
        if (hash[k])
          cnt++;
      ans += pow(cnt, 2);
    }
  }
  return ans;
}

int main() {
  int n1[] = {1, 2, 1};
  int n2[] = {1, 1};
  int r1 = sumCounts(n1, ARRAY_SIZE(n1));
  int r2 = sumCounts(n2, ARRAY_SIZE(n2));
  printf("%d\n", r1);
  assert(r1 == 15);
  printf("%d\n", r2);
  assert(r2 == 3);
}
