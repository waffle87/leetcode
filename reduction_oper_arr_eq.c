// 1887. Reduction Operations to Make the Array Elements Equal
#include "leetcode.h"

/*
 * given an integer array 'nums', your goal is to make all elements in 'nums'
 * equal. to complete one operation, follow the steps find the largest value in
 * 'nums'. let its index be 'i' and its value be 'largest'. if there are
 * multiple elements with the largest value, pick the smallest. find the next
 * largest value in 'nums' strictly smaller than largest. let its value be
 * next_largest. reduce 'nums[i]' to next_largest. return the number of
 * operations to make all the elements in 'nums' equal
 */

int cmp(const void *a, const void *b) { return *(int *)b - *(int *)a; }

int reductionOperations(int *nums, int nums_size) {
  int n = nums_size, ans = 0, cnt = 1, k = 0;
  qsort(nums, n, sizeof(int), cmp);
  for (int i = 1; i < n; i++) {
    if (nums[i] == nums[i - 1])
      cnt++;
    else {
      k += cnt;
      ans += k;
      cnt = 1;
    }
  }
  return ans;
}

int main() {
  int n1[] = {5, 1, 3}, n2[] = {1, 1, 1}, n3[] = {1, 1, 2, 2, 3};
  printf("%d\n", reductionOperations(n1, ARRAY_SIZE(n1))); // expect: 3
  printf("%d\n", reductionOperations(n2, ARRAY_SIZE(n2))); // expect: 0
  printf("%d\n", reductionOperations(n3, ARRAY_SIZE(n3))); // expect: 4
}
