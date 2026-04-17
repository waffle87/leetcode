// 3761. Minimum Absolute Distance Between Mirror Pairs
#include "leetcode.h"

/*
 * you are given an integer array 'nums'. a mirror pair is a pair of indices
 * '(i, j)' such that '0 <= i < j < nums.length' and 'reverse(nums[i]) ==
 * nums[j]'. return the minimum absolute distance between the indices of any
 * mirror pair. the absolute distance between indices is 'i' and 'j' is 'abs(i -
 * j)'. if no mirror pairs exists, return -1.
 */

struct hash_item {
  int key;
  int val;
  UT_hash_handle hh;
};

struct hash_item *hash_find_item(struct hash_item **obj, int key) {
  struct hash_item *pEntry = NULL;
  HASH_FIND_INT(*obj, &key, pEntry);
  return pEntry;
}

bool hash_add_item(struct hash_item **obj, int key, int val) {
  if (hash_find_item(obj, key)) {
    return false;
  }
  struct hash_item *pEntry =
      (struct hash_item *)malloc(sizeof(struct hash_item));
  pEntry->key = key;
  pEntry->val = val;
  HASH_ADD_INT(*obj, key, pEntry);
  return true;
}

bool hash_set_item(struct hash_item **obj, int key, int val) {
  struct hash_item *pEntry = hash_find_item(obj, key);
  if (!pEntry) {
    hash_add_item(obj, key, val);
  } else {
    pEntry->val = val;
  }
  return true;
}

int hash_get_item(struct hash_item **obj, int key, int defaultVal) {
  struct hash_item *pEntry = hash_find_item(obj, key);
  if (!pEntry) {
    return defaultVal;
  }
  return pEntry->val;
}

void hash_free(struct hash_item **obj) {
  struct hash_item *curr = NULL, *tmp = NULL;
  HASH_ITER(hh, *obj, curr, tmp) {
    HASH_DEL(*obj, curr);
    free(curr);
  }
}

int reverse(int x) {
  int y = 0;
  while (x > 0) {
    y = y * 10 + x % 10;
    x /= 10;
  }
  return y;
}

int minMirrorPairDistance(int *nums, int numsSize) {
  struct hash_item *prev = NULL;
  int ans = numsSize + 1;
  for (int i = 0; i < numsSize; i++) {
    int x = nums[i];
    int prevIndex = hash_get_item(&prev, x, -1);
    if (prevIndex != -1) {
      int distance = i - prevIndex;
      if (distance < ans)
        ans = distance;
    }
    hash_set_item(&prev, reverse(x), i);
  }
  hash_free(&prev);
  return ans == numsSize + 1 ? -1 : ans;
}

int main() {
  int n1[] = {12, 21, 45, 33, 54}, n2[] = {120, 21}, n3[] = {21, 120};
  int r1 = minMirrorPairDistance(n1, ARRAY_SIZE(n1));
  int r2 = minMirrorPairDistance(n2, ARRAY_SIZE(n2));
  int r3 = minMirrorPairDistance(n3, ARRAY_SIZE(n3));
  printf("%d\n", r1);
  assert(r1 == 1);
  printf("%d\n", r2);
  assert(r2 == 1);
  printf("%d\n", r3);
  assert(r3 == -1);
}
