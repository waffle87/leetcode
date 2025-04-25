// 2845. Count of Interesting Subarrays
#include "leetcode.h"

/*
 * you are given a 0-indexed integer array 'nums', an integer 'modulo', and an
 * integer 'k'. your task is to find the count of the subarrays that are
 * interesting. a subarray 'nums[l..r]' is interesting if the following
 * condition holds: let 'cnt' be the number of indices 'i' in the range '[l, r]'
 * such that 'nums[i] % modulo == k'. then 'cnt % modulo == k'. return an
 * integer denoting the count of interesting subarrays.
 */

struct pair {
  int key;
  int val;
};

struct hash {
  struct pair *pairs;
  int size;
  int max;
};

struct hash *hash_init(int size) {
  struct hash *new = (struct hash *)malloc(sizeof(struct hash));
  new->pairs = (struct pair *)malloc(size * sizeof(struct pair));
  new->size = 0;
  new->max = size;
  return new;
}

int get(struct hash *obj, int key) {
  for (int i = 0; i < obj->size; i++)
    if (obj->pairs[i].key == key)
      return obj->pairs[i].val;
  return 0;
}

void put(struct hash *obj, int key, int val) {
  for (int i = 0; i < obj->size; i++)
    if (obj->pairs[i].key == key) {
      obj->pairs[i].val = val;
      return;
    }
  if (obj->size == obj->max) {
    obj->max *= 2;
    obj->pairs =
        (struct pair *)realloc(obj->pairs, obj->max * sizeof(struct pair));
  }
  obj->pairs[obj->size].key = key;
  obj->pairs[obj->size].val = val;
  obj->size++;
}

void hash_free(struct hash *obj) {
  free(obj->pairs);
  free(obj);
}

long long countInterestingSubarrays(int *nums, int numsSize, int modulo,
                                    int k) {
  int cnt = 0;
  struct hash *map = hash_init(numsSize);
  put(map, 0, 1);
  long long ans = 0;
  for (int i = 0; i < numsSize; i++) {
    cnt += (nums[i] % modulo == k);
    int k1 = cnt % modulo;
    int k2 = (k1 - k + modulo) % modulo;
    ans += get(map, k2);
    put(map, k1, get(map, k1) + 1);
  }
  hash_free(map);
  return ans;
}

int main() {
  int n1[] = {3, 2, 4}, n2[] = {3, 1, 9, 6};
  printf("%lld\n",
         countInterestingSubarrays(n1, ARRAY_SIZE(n1), 2, 1)); // expect: 3
  printf("%lld\n",
         countInterestingSubarrays(n2, ARRAY_SIZE(n2), 3, 0)); // expect: 2
}
