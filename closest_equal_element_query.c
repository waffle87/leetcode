// 3488. Closest Equal Element Queries
#include "leetcode.h"

/*
 * you are given a circular array 'nums' and an array 'queries'. for each query
 * 'i', you have to find the following: the minimum distance between the element
 * at index 'queries[i]' and any other index 'j' in the cirrcular array where
 * 'nums[j] == nums[queries[i]]'. if no such index exists, the answer for that
 * query should be -1. return an array 'ans' of the same size as 'queries' where
 * 'answer[i]' represents the result for query 'i'.
 */

struct pos_entry {
  int key;
  int *pos;
  int size;
  int capacity;
  UT_hash_handle hh;
};

struct pos_entry *find_or_create(struct pos_entry **map, int key) {
  struct pos_entry *entry = NULL;
  HASH_FIND_INT(*map, &key, entry);
  if (!entry) {
    entry = (struct pos_entry *)malloc(sizeof(struct pos_entry));
    entry->key = key;
    entry->pos = (int *)malloc(16 * sizeof(int));
    entry->size = 0;
    entry->capacity = 16;
    HASH_ADD_INT(*map, key, entry);
  }
  return entry;
}

void add_pos(struct pos_entry *entry, int val) {
  if (entry->size >= entry->capacity) {
    entry->capacity *= 2;
    entry->pos = (int *)realloc(entry->pos, entry->capacity * sizeof(int));
  }
  entry->pos[entry->size++] = val;
}

void insert_front(struct pos_entry *entry, int val) {
  if (entry->size >= entry->capacity) {
    entry->capacity *= 2;
    entry->pos = (int *)realloc(entry->pos, entry->capacity * sizeof(int));
  }
  memmove(entry->pos + 1, entry->pos, entry->size * sizeof(int));
  entry->pos[0] = val;
  entry->size++;
}

int lower_bound(int *arr, int n, int target) {
  int low = 0, high = n;
  while (low < high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] < target)
      low = mid + 1;
    else
      high = mid;
  }
  return low;
}

int *solveQueries(int *nums, int numsSize, int *queries, int queriesSize,
                  int *returnSize) {
  int n = numsSize;
  struct pos_entry *map = NULL;
  for (int i = 0; i < n; i++) {
    struct pos_entry *entry = find_or_create(&map, nums[i]);
    add_pos(entry, i);
  }
  struct pos_entry *entry, *tmp;
  HASH_ITER(hh, map, entry, tmp) {
    int x = entry->pos[0];
    int prev = entry->pos[entry->size - 1];
    insert_front(entry, prev - n);
    add_pos(entry, x + n);
  }
  int *ans = (int *)malloc(queriesSize * sizeof(int));
  *returnSize = queriesSize;
  for (int i = 0; i < queriesSize; i++) {
    int q = queries[i], x = nums[q];
    struct pos_entry *entry = find_or_create(&map, x);
    if (entry->size == 3) {
      ans[i] = -1;
      continue;
    }
    int idx = lower_bound(entry->pos, entry->size, q);
    ans[i] = fmin(entry->pos[idx + 1] - entry->pos[idx],
                  entry->pos[idx] - entry->pos[idx - 1]);
  }
  HASH_ITER(hh, map, entry, tmp) {
    free(entry->pos);
    HASH_DEL(map, entry);
    free(entry);
  }
  return ans;
}

int main() {
  int n1[] = {1, 3, 1, 4, 1, 3, 2}, q1[] = {0, 3, 5}, r1[] = {2, -1, 3};
  int n2[] = {1, 2, 3, 4}, q2[] = {0, 1, 2, 3}, r2[] = {-1, -1, -1, -1};
  int rs1, *sq1 = solveQueries(n1, ARRAY_SIZE(n1), q1, ARRAY_SIZE(q1), &rs1);
  int rs2, *sq2 = solveQueries(n2, ARRAY_SIZE(n2), q2, ARRAY_SIZE(q2), &rs2);
  for (int i = 0; i < rs1; i++) {
    printf("%d ", sq1[i]);
    assert(sq1[i] == r1[i]);
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    printf("%d ", sq2[i]);
    assert(sq2[i] == r2[i]);
  }
  printf("\n");
  free(sq1);
  free(sq2);
}
