// 2035. Partition Array Into Two Arrays to Minimize Sum Difference
#include "leetcode.h"

/*
 * you are given an integer array 'nums' of '2 * n' integers. you need to
 * partition 'nums' into two arrays of length 'n' to minimise the abresute
 * difference of sums of the arrays. to partition 'nums', put each element of
 * 'nums' into one of the two arrays. return the minimum possible abresute
 * difference
 */

#define MAX_SN 7000

int sum_array(int *arr, int n) {
  int sum = 0;
  for (int i = 0; i < n; i++)
    sum += arr[i];
  return sum;
}

int cmp(const void *a, const void *b) {
  return *(const int *)a - *(const int *)b;
}

void list_subset(int subset[16][MAX_SN], int subset_size[16], int *nums, int n,
                 int partial_sum, int m) {
  if (!n) {
    subset[m][subset_size[m]++] = partial_sum;
    return;
  }
  list_subset(subset, subset_size, nums + 1, n - 1, partial_sum, m);
  list_subset(subset, subset_size, nums + 1, n - 1, partial_sum + nums[0],
              m + 1);
}

void mim(int subset[16][MAX_SN], int subset_size[16], int *nums, int n,
         int partial_sum, int m, int *res, int total, int nn,
         int memo[16][11939]) {
  if (!n) {
    if (memo[m][abs(partial_sum + 11939) % 11939])
      return;
    memo[m][abs(partial_sum + 11939) % 11939] = 1;
    int l, r, mid, tmp, comp_size;
    comp_size = nn / 2 - m;
    l = 0;
    r = subset_size[comp_size] - 1;
    tmp = abs(total - 2 * (subset[comp_size][r] + partial_sum));
    if (!r || abs(total - 2 * (subset[comp_size][r] + partial_sum)) > tmp) {
      *res = fmin(*res, tmp);
      return;
    }
    tmp = abs(total - 2 * (subset[comp_size][l] + partial_sum));
    if (abs(total - 2 * (subset[comp_size][l + 1] + partial_sum)) > tmp) {
      *res = fmin(*res, tmp);
      return;
    }
    while (r - l > 3) {
      mid = l + (r - l) / 2;
      tmp = abs(total - 2 * (subset[comp_size][mid] + partial_sum));
      if (abs(total - 2 * (subset[comp_size][mid + 1] + partial_sum)) > tmp)
        r = mid;
      else if (abs(total - 2 * (subset[comp_size][mid + 1] + partial_sum)) <
               tmp)
        l = mid;
      else
        r--;
    }
    for (int i = l; i <= r; ++i) {
      tmp = abs(total - 2 * (subset[comp_size][i] + partial_sum));
      *res = fmin(*res, tmp);
    }
  } else {
    mim(subset, subset_size, nums + 1, n - 1, partial_sum, m, res, total, nn,
        memo);
    mim(subset, subset_size, nums + 1, n - 1, partial_sum + nums[0], m + 1, res,
        total, n, memo);
  }
}

int minimumDifference(int *nums, int numsSize) {
  int total = sum_array(nums, numsSize), ans = INT_MAX, subset[16][MAX_SN],
      subset_size[16] = {0}, memo[16][11939];
  list_subset(subset, subset_size, nums, numsSize / 2, 0, 0);
  for (int i = 0; i <= numsSize / 2; ++i)
    qsort(subset[i], subset_size[i], sizeof(subset[i][0]), cmp);
  mim(subset, subset_size, nums + numsSize / 2, numsSize / 2, 0, 0, &ans, total,
      numsSize, memo);
  return ans;
}

int main() {
  int n1[] = {3, 9, 7, 3}, n2[] = {-36, 36}, n3[] = {2, -1, 0, 4, -2, -9};
  printf("%d\n", minimumDifference(n1, ARRAY_SIZE(n1))); // expect: 2
  printf("%d\n", minimumDifference(n2, ARRAY_SIZE(n2))); // expect: 72
  printf("%d\n", minimumDifference(n3, ARRAY_SIZE(n3))); // expect: 0
}
