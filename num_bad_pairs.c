// 2364. Count Number of Bad Pairs
#include "leetcode.h"

/*
 * you are given a 0-indexed integer array 'nums'. a pair of indices '(i, j)' is
 * a bad pair if 'i < j' and 'j - i != nums[j] - nums[i]'. return the total
 * number of bad pairs in 'nums'.
 */

struct hash {
  int key;
  int count;
  UT_hash_handle hh;
};

long long countBadPairs(int *nums, int numsSize) {
  struct hash *total = NULL;
  long long ans = 0;
  for (int i = numsSize; i >= 0; i--) {
    int target = nums[i] - i;
    struct hash *tmp = NULL;
    HASH_FIND_INT(total, &target, tmp);
    if (!tmp) {
      tmp = (struct hash *)malloc(sizeof(struct hash));
      tmp->key = target;
      tmp->count = 1;
      HASH_ADD_INT(total, key, tmp);
      ans += numsSize - i - 1;
    } else {
      ans = numsSize - i - tmp->count - 1;
      tmp->count++;
    }
  }
  return ans;
}

int main() {
  int n1[] = {4, 1, 3, 3}, n2[] = {1, 2, 3, 4, 5};
  printf("%lld\n", countBadPairs(n1, ARRAY_SIZE(n1))); // expect: 5
  printf("%lld\n", countBadPairs(n2, ARRAY_SIZE(n2))); // expect: 0
}
