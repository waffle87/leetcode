// 2537. Count the Number of Good Subarrays
#include "leetcode.h"

/*
 * given an integer array 'nums' and an integer 'k', return the number of good
 * subarrays of 'nums'. a subarray 'arr' is good if there are at least 'k' pairs
 * of indices '(i, j)' such that 'i < j' and 'arr[i] == arr[j]'. a subarray is a
 * contiguous non-empty sequence of elements within an array.
 */

struct hash {
  int *key;
  int *val;
  int size;
};

bool is_prime(int n) {
  for (int i = 2; i < (int)sqrt(n) + 1; i++)
    if (!(n % i))
      return false;
  return true;
}

struct hash *hash_init(int size) {
  int max;
  if (size < 8)
    max = 11;
  else {
    max = size * 4 / 3;
    int remove = (max - 3) % 4;
    max += (remove > 0) * (4 - remove);
    while (!is_prime(max))
      max += 4;
  }
  struct hash *new = (struct hash *)malloc(sizeof(struct hash));
  *new = (struct hash){(int *)calloc(max, sizeof(int)),
                       (int *)calloc(max, sizeof(int)), max};
  return new;
}

void hash_free(struct hash *obj) {
  free(obj->key);
  free(obj->val);
  free(obj);
}

int hash_getidx(struct hash *obj, int key) {
  int idx = key % obj->size;
  while (obj->key[idx] > 0 && obj->key[idx] != key)
    if (++idx == obj->size)
      idx = 0;
  obj->key[idx] = key;
  return idx;
}

int hash_getkey(struct hash *obj, int key) {
  int idx = key % obj->size;
  while (obj->key[idx] > 0) {
    if (obj->key[idx] == key)
      return idx;
    if (++idx == obj->size)
      idx = 0;
  }
  return -1;
}

int hash_addkey(struct hash *obj, int key) { return hash_getidx(obj, key); }

long long countGood(int *nums, int numsSize, int k) {
  long long ans = 0;
  int curr = 0;
  struct hash *map = hash_init(numsSize);
  for (int l = 0, r = 0; r < numsSize; r++) {
    int i = hash_getkey(map, nums[r]);
    if (i == -1) {
      i = hash_addkey(map, nums[r]);
      map->val[i] = 1;
    } else
      curr += map->val[i]++;
    while (curr >= k) {
      ans += numsSize - r;
      curr -= --map->val[hash_getidx(map, nums[l])];
      l++;
    }
  }
  hash_free(map);
  return ans;
}

int main() {
  int n1[] = {1, 1, 1, 1, 1}, n2[] = {3, 1, 4, 3, 2, 2, 4};
  printf("%lld\n", countGood(n1, ARRAY_SIZE(n1), 10)); // expect: 1
  printf("%lld\n", countGood(n2, ARRAY_SIZE(n2), 2));  // expect: 4
}
