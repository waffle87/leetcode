// 3347. Maximum Frequency of an Element After Performing Operations II
#include "leetcode.h"

/*
 * you are given an integer array 'nums' and two integers 'k' and
 * 'numOperations'. you must perform an operation 'numOperations' times on
 * 'nums', where in each operation you select an index 'i' that was not selected
 * in any previous operations, and add an integer in the range '[-k, k]' to
 * 'nums[i]'. return the maximum possible frequency of any elements in 'nums'
 * after performing the operations.
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

bool hash_add_item(struct hash_item **obj, int key, int val) {
  if (hash_find_item(obj, key))
    return false;
  struct hash_item *p = (struct hash_item *)malloc(sizeof(struct hash_item));
  p->key = key;
  p->val = val;
  HASH_ADD_INT(*obj, key, p);
  return true;
}

void hash_set_item(struct hash_item **obj, int key, int val) {
  struct hash_item *p = hash_find_item(obj, key);
  if (!p)
    hash_add_item(obj, key, val);
  else
    p->val = val;
}

int hash_get_item(struct hash_item **obj, int key, int val) {
  struct hash_item *p = hash_find_item(obj, key);
  if (!p)
    return val;
  return p->val;
}

void hash_free(struct hash_item **obj) {
  struct hash_item *curr = NULL, *tmp = NULL;
  HASH_ITER(hh, *obj, curr, tmp) {
    HASH_DEL(*obj, curr);
    free(curr);
  }
}

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

void add_mode(int *nums, int numsSize, int k, struct hash_item **modes,
              int val) {
  hash_add_item(modes, val, 1);
  if (val - k >= nums[0])
    hash_add_item(modes, val - k, 1);
  if (val + k <= nums[numsSize - 1])
    hash_add_item(modes, val + k, 1);
}

int left_bound(int *nums, int numsSize, int val) {
  int left = 0, right = numsSize - 1;
  while (left < right) {
    int mid = (left + right) / 2;
    if (nums[mid] < val)
      left = mid + 1;
    else
      right = mid;
  }
  return left;
}

int right_bound(int *nums, int numsSize, int val) {
  int left = 0, right = numsSize - 1;
  while (left < right) {
    int mid = (left + right + 1) / 2;
    if (nums[mid] > val)
      right = mid - 1;
    else
      left = mid;
  }
  return left;
}

int maxFrequency(int *nums, int numsSize, int k, int numOperations) {
  qsort(nums, numsSize, sizeof(int), cmp);
  int ans = 0, prev = 0;
  struct hash_item *num_cnt = NULL, *modes = NULL;
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] != nums[prev]) {
      hash_set_item(&num_cnt, nums[prev], i - prev);
      if (i - prev > ans)
        ans = i - prev;
      add_mode(nums, numsSize, k, &modes, nums[prev]);
      prev = i;
    }
  }
  hash_set_item(&num_cnt, nums[prev], numsSize - prev);
  if (numsSize - prev > ans)
    ans = numsSize - prev;
  add_mode(nums, numsSize, k, &modes, nums[prev]);
  int mode_size = HASH_COUNT(modes), pos = 0;
  int *sorted_modes = (int *)malloc(mode_size * sizeof(int));
  for (struct hash_item *p = modes; p; p = p->hh.next)
    sorted_modes[pos++] = p->key;
  qsort(sorted_modes, mode_size, sizeof(int), cmp);
  for (int i = 0; i < mode_size; i++) {
    int mode = sorted_modes[i], tmp;
    int l = left_bound(nums, numsSize, mode - k);
    int r = right_bound(nums, numsSize, mode + k);
    if (hash_find_item(&num_cnt, mode)) {
      int cnt = hash_get_item(&num_cnt, mode, 0);
      tmp = fmin(r - l + 1, cnt + numOperations);
    } else
      tmp = fmin(r - l + 1, numOperations);
    if (tmp > ans)
      ans = tmp;
  }
  hash_free(&num_cnt);
  hash_free(&modes);
  free(sorted_modes);
  return ans;
}

int main() {
  int n1[] = {1, 4, 5}, n2[] = {5, 11, 20, 20};
  printf("%d\n", maxFrequency(n1, ARRAY_SIZE(n1), 1, 2)); // expect: 2
  printf("%d\n", maxFrequency(n2, ARRAY_SIZE(n2), 5, 1)); // expect: 2
}
