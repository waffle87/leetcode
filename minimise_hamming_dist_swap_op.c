// 1722. Minimize Hamming Distance After Swap Operations
#include "leetcode.h"

/*
 * you are given two integer arrays, 'source' and 'target', both of length 'n'.
 * you are also given an array 'allowedSwaps' where each 'allowedSwaps[i] = [ai,
 * bi]' indicates that you are allowed to swap the elements at a specific pair
 * of indices multiple times and in any order. the hamming distance of two
 * arrays of the same length 'source' and 'target', is the number of positions
 * where the elements are different. return the minimum hamming distance of
 * 'source' and 'target' after performing any aount of swap operations on array
 * 'source'.
 */

struct hash_item {
  int key;
  int value;
  UT_hash_handle hh;
};

struct union_find {
  int *fa;
  int *rank;
  int size;
};

struct union_find *union_find_init(int n) {
  struct union_find *obj =
      (struct union_find *)malloc(sizeof(struct union_find));
  obj->fa = (int *)malloc(n * sizeof(int));
  obj->rank = (int *)calloc(n, sizeof(int));
  obj->size = n;
  for (int i = 0; i < n; i++)
    obj->fa[i] = i;
  return obj;
}

int find(struct union_find *obj, int x) {
  if (obj->fa[x] != x)
    obj->fa[x] = find(obj, obj->fa[x]);
  return obj->fa[x];
}

void union_set(struct union_find *obj, int x, int y) {
  x = find(obj, x);
  y = find(obj, y);
  if (x == y)
    return;
  if (obj->rank[x] < obj->rank[y]) {
    int tmp = x;
    x = y;
    y = tmp;
  }
  obj->fa[y] = x;
  if (obj->rank[x] == obj->rank[y])
    obj->rank[x]++;
}

void union_find_free(struct union_find *obj) {
  free(obj->fa);
  free(obj->rank);
  free(obj);
}

int minimumHammingDistance(int *source, int sourceSize, int *target,
                           int targetSize, int **allowedSwaps,
                           int allowedSwapsSize, int *allowedSwapsColSize) {
  int n = sourceSize;
  struct union_find *uf = union_find_init(n);
  for (int i = 0; i < allowedSwapsSize; i++)
    union_set(uf, allowedSwaps[i][0], allowedSwaps[i][1]);
  struct hash_item **sets =
      (struct hash_item **)calloc(n, sizeof(struct hash_item *));
  for (int i = 0; i < n; i++) {
    int f = find(uf, i);
    struct hash_item *entry = NULL;
    HASH_FIND_INT(sets[f], &source[i], entry);
    if (!entry) {
      entry = (struct hash_item *)malloc(sizeof(struct hash_item));
      entry->key = source[i];
      entry->value = 1;
      HASH_ADD_INT(sets[f], key, entry);
    } else
      entry->value++;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int f = find(uf, i);
    struct hash_item *entry = NULL;
    HASH_FIND_INT(sets[f], &target[i], entry);
    if (entry && entry->value > 0)
      entry->value--;
    else
      ans++;
  }
  for (int i = 0; i < n; i++) {
    struct hash_item *curr, *tmp;
    HASH_ITER(hh, sets[i], curr, tmp) {
      HASH_DEL(sets[i], curr);
      free(curr);
    }
  }
  free(sets);
  union_find_free(uf);
  return ans;
}

int main() {
  int s1[] = {1, 2, 3, 4}, t1[] = {2, 1, 4, 5}, a1i[2][2] = {{0, 1}, {2, 3}};
  int s2[] = {1, 2, 3, 4}, t2[] = {1, 3, 2, 4}, a2i[0][0] = {{}};
  int s3[] = {5, 1, 2, 4, 3}, t3[] = {1, 5, 4, 2, 3},
      a3i[4][4] = {{0, 4}, {4, 2}, {1, 3}, {1, 4}};
  struct two_d_arr *a1 =
      two_d_arr_init(ARRAY_SIZE(a1i), ARRAY_SIZE(a1i[0]), a1i);
  struct two_d_arr *a2 =
      two_d_arr_init(ARRAY_SIZE(a2i), ARRAY_SIZE(a2i[0]), a2i);
  struct two_d_arr *a3 =
      two_d_arr_init(ARRAY_SIZE(a3i), ARRAY_SIZE(a3i[0]), a3i);
  int r1 = minimumHammingDistance(s1, ARRAY_SIZE(s1), t1, ARRAY_SIZE(t1),
                                  a1->arr, a1->row_size, a1->col_size);
  int r2 = minimumHammingDistance(s2, ARRAY_SIZE(s2), t2, ARRAY_SIZE(t2),
                                  a2->arr, a2->row_size, a2->col_size);
  int r3 = minimumHammingDistance(s3, ARRAY_SIZE(s3), t3, ARRAY_SIZE(t3),
                                  a3->arr, a3->row_size, a3->col_size);
  printf("%d\n", r1);
  assert(r1 == 1);
  printf("%d\n", r2);
  assert(r2 == 2);
  printf("%d\n", r3);
  assert(r3 == 0);
}
