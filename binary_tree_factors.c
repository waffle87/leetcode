// 823. Binary Trees With Factors
#include "leetcode.h"

/*
 * given an array of unique integers 'arr' where each integer 'arr[i]' is
 * strictly greater than 1. we make a binary tree using these integers and each
 * number may be used for any number of times. each non-leaf node's value should
 * be equal to the product of the values of its children. return the number of
 * binary trees we can make. the answer may be too large to fit in a signed 32
 * bit integer, so return the answer modulo 10e9+7
 */

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int numFactoredBinaryTrees(int *arr, int arr_size) {
  int ans = 0, mod = 1e9 + 7;
  qsort(arr, arr_size, sizeof(int), cmp);
  long dp[arr_size];
  for (int i = 0; i < arr_size; i++)
    dp[i] = 1;
  for (int i = 0; i < arr_size; i++) {
    int left = 0, right = i - 1;
    while (left <= right) {
      if ((long)arr[left] * arr[right] > arr[i])
        right--;
      else if ((long)arr[left] * arr[right] < arr[i])
        left++;
      else {
        if (left == right)
          dp[i] += (dp[left] * dp[right]);
        else
          dp[i] += 2 * (dp[left] * dp[right]);
        left++;
        right--;
      }
    }
    ans = ((ans % mod) + dp[i]) % mod;
  }
  return ans;
}

int main() {
  int a1[] = {2, 4}, a2[] = {2, 4, 5, 10};
  printf("%d\n", numFactoredBinaryTrees(a1, ARRAY_SIZE(a1))); // expect: 3
  printf("%d\n", numFactoredBinaryTrees(a2, ARRAY_SIZE(a2))); // expect: 7
}
