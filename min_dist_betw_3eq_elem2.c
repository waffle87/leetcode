// 3741. Minimum Distance Between Three Equal Elements II
#include "leetcode.h"

/*
 * you are given an integer array 'nums'. a tuple '(i, j, k)' of 3 distinct
 * indices is good if 'nums[i] == nums[j] == nums[k]'. the distance of a good
 * tuple is 'abs(i - j) + abs(j - k) + abs(k - i)' where 'abs(x)' is the
 * absolute value of 'x'. return an integer denoting the minimum possible
 * distance of a good tuple. if no good tuples exist, return -1.
 */

struct h_elem {
  int key;
  int val;
  UT_hash_handle hh;
};

int minimumDistance(int *nums, int numsSize) {
  int ans = INT_MAX;
  int *next = (int *)malloc(numsSize * sizeof(int));
  memset(next, -1, numsSize * sizeof(int));
  struct h_elem *map = NULL, *tmp;
  for (int i = numsSize - 1; i >= 0; i--) {
    HASH_FIND_INT(map, &nums[i], tmp);
    if (tmp)
      next[i] = tmp->val;
    else {
      tmp = (struct h_elem *)malloc(sizeof(struct h_elem));
      tmp->key = nums[i];
      tmp->val = -1;
      HASH_ADD_INT(map, key, tmp);
    }
    tmp->val = i;
  }
  for (int i = 0; i < numsSize; i++) {
    int second = next[i];
    if (second != -1) {
      int third = next[second];
      if (third != -1)
        ans = third - i;
    }
  }
  return ans == INT_MAX ? -1 : ans * 2;
}

int main() {
  int n1[] = {1, 2, 1, 1, 3}, n2[] = {1, 1, 2, 3, 2, 1, 2}, n3[] = {1};
  int r1 = minimumDistance(n1, ARRAY_SIZE(n1));
  int r2 = minimumDistance(n2, ARRAY_SIZE(n2));
  int r3 = minimumDistance(n3, ARRAY_SIZE(n3));
  printf("%d\n", r1);
  assert(r1 == 6);
  printf("%d\n", r2);
  assert(r2 == 8);
  printf("%d\n", r3);
  assert(r3 == -1);
}
