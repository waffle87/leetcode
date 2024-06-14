// 2659. Make Array Empty
#include "leetcode.h"

/*
 * given an integer array 'nums' containing distinct numbers and you can perform
 * the following operations until the array is emtpy. if the first element has
 * the smallest value, remove it. otherwise, put the first element at the end of
 * the array. return an integer denoting the number of operations it takes to
 * make 'nums' empty.
 */

typedef struct {
  int val;
  int idx;
} pair;

int cmp(const void *a, const void *b) {
  return ((pair *)a)->val - ((pair *)b)->val;
}

long long countOperationsToEmptyArray(int *nums, int numsSize) {
  pair p[numsSize];
  for (int i = 0; i < numsSize; i++) {
    p[i].val = nums[i];
    p[i].idx = i;
  }
  qsort(p, numsSize, sizeof(pair), cmp);
  long long ans = numsSize;
  for (int i = 1; i < numsSize; i++)
    if (p[i].idx < p[i - 1].idx)
      ans += numsSize - i;
  return ans;
}

int main() {
  int n1[] = {3, 4, -1}, n2[] = {1, 2, 4, 3}, n3[] = {1, 2, 3};
  printf("%lld\n", countOperationsToEmptyArray(n1, ARRAY_SIZE(n1))); // expect:
                                                                     // 5
  printf("%lld\n", countOperationsToEmptyArray(n2, ARRAY_SIZE(n2))); // expect:
                                                                     // 5
  printf("%lld\n", countOperationsToEmptyArray(n3, ARRAY_SIZE(n3))); // expect:
                                                                     // 3
}
