// 1569. Number of Ways to Reorder Array to Get Same BST
#include "leetcode.h"

/*
 * given an array 'nums' that represents a permutation of integers from '1 to
 * n'. we are going to construct a binary search tree (BST) by inserting the
 * elements of 'nums' in order into an initially empty BST. find the number of
 * different ways to reorder 'nums' so that the constructed BST is identical to
 * that formed from the original array 'nums'. for example given 'nums =
 * [2,1,3]', we will have 2 as the root, 1 as a left child, and three as a right
 * child. the array [2,3,1] also yields the same BST, but '[3,2,1]' yields a
 * different BST. return the number of ways to reorder 'nums' such that the BST
 * formed is identical to the original BST formed from 'nums'. since the answer
 * may be large, return it modulo 10^9+7
 */

static long long mod = 1e9 + 7;

long long **pascal_triangle(int n) {
  long long **res = (long long **)malloc(n * sizeof(long long *));
  for (int i = 0; i < n; i++) {
    res[i] = (long long *)malloc((i + 1) * sizeof(long long));
    for (int j = 0; j <= i; j++) {
      if (j != 0 && j != i) {
        res[i][j] = (res[i - 1][j - 1] % mod) + (res[i - 1][j] % mod);
        continue;
      }
      res[i][j] = 1ULL;
    }
  }
  return res;
}

long long helper(int *nums, int n, long long **triangle) {
  if (n < 3)
    return 1;
  int *left = (int *)malloc(n * sizeof(int)), left_idx = 0;
  int *right = (int *)malloc(n * sizeof(int)), right_idx = 0;
  for (int i = 0; i < n; i++) {
    if (nums[i] < nums[0])
      left[left_idx++] = nums[i];
    else if (nums[i] > nums[0])
      right[right_idx++] = nums[i];
  }
  long long pos_perm = triangle[n - 1][left_idx] % mod;
  long long left_perm = helper(left, left_idx, triangle) % mod;
  long long right_perm = helper(right, right_idx, triangle) % mod;
  long long left_right = (left_perm * right_perm) % mod;
  return (left_right * pos_perm) % mod;
}

int numOfWays(int *nums, int numsSize) {
  long long **triangle = pascal_triangle(numsSize);
  long long ways = helper(nums, numsSize, triangle);
  for (int i = 0; i < numsSize; i++)
    free(triangle[i]);
  free(triangle);
  return ways - 1;
}

int main() {
  int n1[] = {2, 1, 3};
  int n2[] = {3, 4, 5, 1, 2};
  int n3[] = {1, 2, 3};
  int r1 = numOfWays(n1, ARRAY_SIZE(n1));
  int r2 = numOfWays(n2, ARRAY_SIZE(n2));
  int r3 = numOfWays(n3, ARRAY_SIZE(n3));
  printf("%d\n", r1);
  assert(r1 == 1);
  printf("%d\n", r2);
  assert(r2 == 5);
  printf("%d\n", r3);
  assert(r3 == 0);
}
