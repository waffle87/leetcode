// 3551. Minimum Swaps to Sort by Digit Sum
#include "leetcode.h"

/*
 * you are given an array 'nums' of distinct positive integers. you need to sort
 * the array in increasing order based on the sum of the digits of each number.
 * if two numbers have the same digit sum, the smaller number appears first in
 * the sorted order. return the minimum number of swaps required to rearrange
 * 'nums' into this sorted order. a swap is defined as exchanging the values at
 * two distinct positions in the array.
 */

struct elem {
  int digit_sum;
  int val;
  int orig_idx;
};

int cmp(const void *a, const void *b) {
  struct elem *aa = (struct elem *)a;
  struct elem *bb = (struct elem *)b;
  if (aa->digit_sum != bb->digit_sum)
    return aa->digit_sum - bb->digit_sum;
  return aa->val - bb->val;
}

int minSwaps(int *nums, int numsSize) {
  int n = numsSize;
  struct elem *elements = (struct elem *)malloc(n * sizeof(struct elem));
  for (int i = 0; i < n; i++) {
    int x = nums[i], sum = 0;
    while (x > 0) {
      sum += x % 10;
      x /= 10;
    }
    elements[i].digit_sum = sum;
    elements[i].val = nums[i];
    elements[i].orig_idx = i;
  }
  qsort(elements, n, sizeof(struct elem), cmp);
  int *target = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
    target[elements[i].orig_idx] = i;
  bool *vis = (bool *)calloc(n, sizeof(bool));
  int cycles = 0;
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      cycles++;
      int j = i;
      while (!vis[j]) {
        vis[j] = true;
        j = target[j];
      }
    }
  }
  free(elements);
  free(target);
  free(vis);
  return n - cycles;
}

int main() {
  int n1[] = {37, 100};
  int n2[] = {22, 14, 33, 7};
  int n3[] = {18, 43, 34, 16};
  int r1 = minSwaps(n1, ARRAY_SIZE(n1));
  int r2 = minSwaps(n2, ARRAY_SIZE(n2));
  int r3 = minSwaps(n3, ARRAY_SIZE(n3));
  printf("%d\n", r1);
  assert(r1 == 1);
  printf("%d\n", r2);
  assert(r2 == 0);
  printf("%d\n", r3);
  assert(r3 == 2);
}
