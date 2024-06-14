// 1630. Arithmetic Subarrays
#include "leetcode.h"

/*
 * a sequence of numbers is called arithmetic if it consists of at least two
 * elements and the difference between every two consecutive elements is the
 * same. more formally, a sequence 's' is arithmetic if and only if 's[i + 1] -
 * s[i] == s[1] - s[0]' for all valid 'i'. you are given an array of 'n'
 * integers 'nums' and two arrays of 'm' integers each 'l' and 'r' respectively
 * representingthe 'm' range queries where the i'th query isthe range '[l[i],
 * r[i]]'. all the arrays are 0-indexed. return a list of boolean elements 'ans'
 * where 'ans[i]' is true if the subarray 'nums[l[i]], nums[l[i] + 1], ...,
 * nums[r[i]]' can be rearrange to form an arithmetic sequence and false
 * otherwise
 */

int cmp(const void *a, const void *b) {
  return *(const int *)a - *(const int *)b;
}

bool check(int *nums, int start, int size) {
  int *arr = (int *)malloc(size * sizeof(int));
  memcpy(arr, nums + start, size * sizeof(int));
  qsort(arr, size, sizeof(int), cmp);
  int res = arr[1] - arr[0];
  for (int i = 1; i < size; i++)
    if (arr[i] - arr[i - 1] != res) {
      free(arr);
      return false;
    }
  free(arr);
  return true;
}

bool *checkArithmeticSubarrays(int *nums, int nums_size, int *l, int l_size,
                               int *r, int r_size, int *return_size) {
  *return_size = l_size;
  bool *ans = (bool *)malloc((*return_size) * sizeof(bool));
  for (int i = 0; i < (*return_size); i++) {
    int start = l[i], size = r[i] - l[i] + 1;
    ans[i] = check(nums, start, size);
  }
  return ans;
}

int main() {
  int n1[] = {4, 6, 5, 9, 3, 7},
      n2[] = {-12, -9, -3, -12, -6, 15, 20, -25, -20, -15, -10};
  int l1[] = {0, 0, 2}, r1[] = {2, 3, 5}, l2[] = {0, 1, 6, 4, 8, 7},
      r2[] = {4, 4, 9, 7, 9, 10};
  int rs1[] = {}, rs2[] = {};
  bool *cas1 = checkArithmeticSubarrays(n1, ARRAY_SIZE(n1), l1, ARRAY_SIZE(l1),
                                        r1, ARRAY_SIZE(r1), rs1);
  bool *cas2 = checkArithmeticSubarrays(n2, ARRAY_SIZE(n2), l2, ARRAY_SIZE(l2),
                                        r2, ARRAY_SIZE(r2), rs2);
  for (int i = 0; i < 3; i++)
    printf("%d", cas1[i]); // expect: 1 0 1
  printf("\n");
  for (int i = 0; i < 6; i++)
    printf("%d", cas2[i]); // expect: 0 1 0 0 1 1
  printf("\n");
}
