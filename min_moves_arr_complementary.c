// 1674. Minimum Moves to Make Array Complementary
#include "leetcode.h"

/*
 * you are given an integer array 'nums' of even length 'n' and an integer
 * 'limit'. in one move, you can replace any integer from 'nums' with another
 * integer between 1 and 'limit', inclusive. the array 'nums' is complementary
 * if for all indices 'i' (0-indexed), 'nums[i] + nums[n - i - 1]' equals the
 * same number. return the minimum number of moves required to make 'nums'
 * complementary.
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

bool hash_set_item(struct hash_item **obj, int key, int val) {
  struct hash_item *p = hash_find_item(obj, key);
  if (!p)
    hash_add_item(obj, key, val);
  else
    p->val = val;
  return true;
}

int hash_get_item(struct hash_item **obj, int key, int defaultVal) {
  struct hash_item *p = hash_find_item(obj, key);
  if (!p)
    return defaultVal;
  return p->val;
}

void hashFree(struct hash_item **obj) {
  struct hash_item *curr = NULL, *tmp = NULL;
  HASH_ITER(hh, *obj, curr, tmp) {
    HASH_DEL(*obj, curr);
    free(curr);
  }
}

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int lower_bound(int *arr, int size, int target) {
  int left = 0, right = size;
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] >= target)
      right = mid;
    else
      left = mid + 1;
  }
  return left;
}

int minMoves(int *nums, int numsSize, int limit) {
  int n = numsSize, half = n / 2, min_ops = n;
  struct hash_item *sum_cnt = NULL;
  int *min = (int *)malloc(half * sizeof(int));
  int *max = (int *)malloc(half * sizeof(int));
  for (int i = 0; i < half; i++) {
    int a = fmin(nums[i], nums[n - 1 - i]);
    int b = fmax(nums[i], nums[n - 1 - i]);
    int sum = a + b;
    int currCount = hash_get_item(&sum_cnt, sum, 0);
    hash_set_item(&sum_cnt, sum, currCount + 1);
    min[i] = a;
    max[i] = b;
  }
  qsort(min, half, sizeof(int), cmp);
  qsort(max, half, sizeof(int), cmp);
  for (int c = 2; c <= 2 * limit; c++) {
    int add_left = half - lower_bound(min, half, c);
    int add_right = lower_bound(max, half, c - limit);
    int currOps = half + add_left + add_right - hash_get_item(&sum_cnt, c, 0);
    if (currOps < min_ops)
      min_ops = currOps;
  }
  free(min);
  free(max);
  hashFree(&sum_cnt);

  return min_ops;
}

int main() {
  int n1[] = {1, 2, 4, 3}, n2[] = {1, 2, 2, 1}, n3[] = {1, 2, 1, 2};
  int r1 = minMoves(n1, ARRAY_SIZE(n1), 4);
  int r2 = minMoves(n2, ARRAY_SIZE(n2), 2);
  int r3 = minMoves(n3, ARRAY_SIZE(n3), 2);
  printf("%d\n", r1);
  assert(r1 == 1);
  printf("%d\n", r2);
  assert(r2 == 2);
  printf("%d\n", r3);
  assert(r3 == 0);
}
