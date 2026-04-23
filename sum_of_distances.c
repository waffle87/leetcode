// 2615. Sum of Distances
#include "leetcode.h"

/*
 * you are given a 0 indexed integer array 'nums'. there exists an array 'arr'
 * of length 'nums.length' where 'arr[i]' is the sum of '|i - j|' over all 'j'
 * such that 'nums[j] == nums[i]' and 'j != i'. if there is no such 'j', set
 * 'arr[i]' to be 0. return the array 'arr'.
 */

struct group {
  int key;
  int *indices;
  int count;
  int capacity;
  UT_hash_handle hh;
};

long long *distance(int *nums, int numsSize, int *returnSize) {
  *returnSize = numsSize;
  long long *ans = (long long *)calloc(numsSize, sizeof(long long));
  struct group *map = NULL;
  for (int i = 0; i < numsSize; i++) {
    struct group *g = NULL;
    HASH_FIND_INT(map, &nums[i], g);
    if (!g) {
      g = (struct group *)malloc(sizeof(struct group));
      g->key = nums[i];
      g->capacity = 16;
      g->indices = (int *)malloc(g->capacity * sizeof(int));
      g->count = 0;
      HASH_ADD_INT(map, key, g);
    }
    if (g->count == g->capacity) {
      g->capacity *= 2;
      g->indices = (int *)realloc(g->indices, g->capacity * sizeof(int));
    }
    g->indices[g->count++] = i;
  }
  struct group *g, *tmp;
  HASH_ITER(hh, map, g, tmp) {
    long long total = 0;
    for (int j = 0; j < g->count; j++) {
      total += g->indices[j];
    }
    long long prefixTotal = 0;
    for (int j = 0; j < g->count; j++) {
      int idx = g->indices[j];
      ans[idx] = total - prefixTotal * 2 + (long long)idx * (2 * j - g->count);
      prefixTotal += idx;
    }
    HASH_DEL(map, g);
    free(g->indices);
    free(g);
  }
  return ans;
}

int main() {
  int n1[] = {1, 3, 1, 1, 2}, r1[] = {5, 0, 3, 4, 0}, rs1;
  int n2[] = {0, 5, 3}, r2[] = {0, 0, 0}, rs2;
  long long *d1 = distance(n1, ARRAY_SIZE(n1), &rs1);
  long long *d2 = distance(n2, ARRAY_SIZE(n2), &rs2);
  for (int i = 0; i < rs1; i++) {
    printf("%lld ", d1[i]);
    assert(d1[i] == r1[i]);
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    printf("%lld ", d2[i]);
    assert(d2[i] == r2[i]);
  }
  printf("\n");
  free(d1);
  free(d2);
}
