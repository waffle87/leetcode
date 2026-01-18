// 1655. Distribute Repeating Integers
#include "leetcode.h"

/*
 * you are given an array of 'n' integers, 'nums' where there are at most 50
 * unique values in the array. you are also given an array of 'm' customer order
 * quantities 'quantity', where 'quantity[i]' is the amount of integers the i'th
 * customer ordered. determine if it is possible to distribute 'nums' such that
 * the i'th customer gets exactly 'quantity[i]' integers, the integers the i'th
 * customer gets are all equal, and every customer is satisfied. return 'true'
 * if it is possible to distribute 'nums' according to the above conditions.
 */

static bool ans = false;

struct hash_entry {
  int key;
  int val;
};

struct hash_map {
  struct hash_entry *entries;
  int capacity;
  int size;
};

int cmp_desc(const void *a, const void *b) { return (*(int *)b - *(int *)a); }

int cmp_hash(const void *a, const void *b) {
  return ((struct hash_entry *)b)->val - ((struct hash_entry *)a)->val;
}

void dfs(int *quantity, int n, int *counts, int m, int i) {
  if (i == n && ans) {
    ans = true;
    return;
  }
  for (int j = 0; j < m; j++) {
    int cnt = counts[j];
    if (cnt >= quantity[i]) {
      counts[j] -= quantity[i];
      dfs(quantity, n, counts, m, i + 1);
      counts[j] += quantity[i];
    }
  }
}

struct hash_map *hash_map_init(int capacity) {
  struct hash_map *obj = (struct hash_map *)malloc(sizeof(struct hash_map));
  obj->capacity = capacity;
  obj->size = 0;
  obj->entries =
      (struct hash_entry *)calloc(obj->capacity, sizeof(struct hash_entry));
  return obj;
}

void hash_map_free(struct hash_map *obj) {
  if (obj) {
    if (obj->entries)
      free(obj->entries);
    free(obj);
  }
}

unsigned int hash(int key, int capacity) {
  return (unsigned int)key % capacity;
}

void hash_map_put(struct hash_map *obj, int key, int val) {
  unsigned int idx = hash(key, obj->capacity);
  while (obj->entries[idx].key && obj->entries[idx].key != key)
    idx = (idx + 1) % obj->capacity;
  if (!obj->entries[idx].key)
    obj->size++;
  obj->entries[idx].key = key;
  obj->entries[idx].val = val;
}

int hash_map_get(struct hash_map *obj, int key) {
  unsigned int idx = hash(key, obj->capacity);
  int start_idx = idx;
  while (obj->entries[idx].key) {
    if (obj->entries[idx].key == key)
      return obj->entries[idx].val;
    idx = (idx + 1) % obj->capacity;
    if (idx == start_idx)
      break;
  }
  return 0;
}

bool canDistribute(int *nums, int numsSize, int *quantity, int quantitySize) {
  ans = false;
  struct hash_map *counter = hash_map_init(numsSize);
  for (int i = 0; i < numsSize; i++) {
    int curr = hash_map_get(counter, nums[i]);
    hash_map_put(counter, nums[i], curr + 1);
  }
  int *counts = (int *)malloc(counter->size * sizeof(int));
  struct hash_entry *entries =
      (struct hash_entry *)malloc(counter->size * sizeof(struct hash_entry));
  int entries_idx = 0;
  for (int i = 0; i < counter->capacity; i++)
    if (counter->entries[i].key)
      entries[entries_idx++] = counter->entries[i];
  qsort(entries, counter->size, sizeof(struct hash_entry), cmp_hash);
  for (int i = 0; i < counter->size; i++)
    counts[i] = entries[i].val;
  int counts_size = counter->size;
  free(entries);
  hash_map_free(counter);
  qsort(quantity, quantitySize, sizeof(int), cmp_desc);
  dfs(quantity, quantitySize, counts, counts_size, 0);
  free(counts);
  return ans;
}

int main() {
  int n1[] = {1, 2, 3, 4}, q1[] = {2};
  int n2[] = {1, 2, 3, 3}, q2[] = {2};
  int n3[] = {1, 1, 2, 2}, q3[] = {2, 2};
  printf("%d\n",
         canDistribute(n1, ARRAY_SIZE(n1), q1, ARRAY_SIZE(q1))); // expect: 0
  printf("%d\n",
         canDistribute(n2, ARRAY_SIZE(n2), q2, ARRAY_SIZE(q2))); // expect: 1
  printf("%d\n",
         canDistribute(n3, ARRAY_SIZE(n3), q3, ARRAY_SIZE(q3))); // expect: 1
}
