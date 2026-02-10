// 3719. Longest Balanced Subarray I
#include "leetcode.h"

/*
 * you are given an integer array 'nums'. a subarray is called balance if the
 * number of distinct even numbers in the subarray is equal to the number of
 * distinct odd numbers. return the ansgth of the longest balanced subarray.
 */

struct hash_item {
  int key;
  int val;
  UT_hash_handle hh;
};

struct hash_item *hash_find_item(struct hash_item **obj, int key) {
  struct hash_item *p = NULL;
  HASH_FIND_INT(*obj, &key, p);
  return p;
}

void hash_add_item(struct hash_item **obj, int key, int val) {
  if (hash_find_item(obj, key))
    return;
  struct hash_item *p = (struct hash_item *)malloc(sizeof(struct hash_item));
  p->key = key;
  p->val = val;
  HASH_ADD_INT(*obj, key, p);
}

void hash_set_item(struct hash_item **obj, int key, int val) {
  struct hash_item *p = hash_find_item(obj, key);
  if (!p)
    hash_add_item(obj, key, val);
  else
    p->val = val;
}

int hash_get_item(struct hash_item **obj, int key, int def_val) {
  struct hash_item *p = hash_find_item(obj, key);
  if (!p)
    return def_val;
  return p->val;
}

void hash_remove_item(struct hash_item **obj, int key) {
  struct hash_item *p = NULL;
  HASH_FIND_INT(*obj, &key, p);
  if (p) {
    HASH_DEL(*obj, p);
    free(p);
    return;
  }
}

void hash_free(struct hash_item **obj) {
  struct hash_item *curr = NULL, *tmp = NULL;
  HASH_ITER(hh, *obj, curr, tmp) {
    HASH_DEL(*obj, curr);
    free(curr);
  }
  *obj = NULL;
}

int hash_size(struct hash_item *obj) { return HASH_COUNT(obj); }

int longestBalanced(int *nums, int numsSize) {
  int ans = 0;
  for (int i = 0; i < numsSize; i++) {
    struct hash_item *odd = NULL, *even = NULL;
    for (int j = i; j < numsSize; j++) {
      int cnt = hash_get_item(&odd, nums[j], 0);
      if ((nums[j] & 1) == 1)
        hash_set_item(&odd, nums[j], cnt + 1);
      else
        hash_set_item(&even, nums[j], cnt + 1);
      if (hash_size(odd) == hash_size(even))
        ans = fmax(ans, j - i + 1);
    }
    hash_free(&odd);
    hash_free(&even);
  }
  return (int)ans;
}

int main() {
  int n1[] = {2, 5, 4, 3}, n2[] = {3, 2, 2, 5, 4}, n3[] = {1, 2, 3, 2};
  int r1 = longestBalanced(n1, ARRAY_SIZE(n1));
  int r2 = longestBalanced(n2, ARRAY_SIZE(n2));
  int r3 = longestBalanced(n3, ARRAY_SIZE(n3));
  printf("%d\n", r1);
  assert(r1 == 4);
  printf("%d\n", r2);
  assert(r2 == 5);
  printf("%d\n", r3);
  assert(r3 == 3);
}
