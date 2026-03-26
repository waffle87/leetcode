// 3548. Equal Sum Grid Partition II
#include "leetcode.h"

/*
 * you are given an 'm x n' matrix 'grid' of positive integers. your task is to
 * determine if it is possible to make either one horizontal or one vertical cut
 * on the grid such that each of the two resulting sections formed by the cut is
 * non-empty, the sum of the elements in both sections is equal or can be made
 * equal by discounting at most one single cell in total, and if a cell is
 * discounted, the rest of the section must remain connected. return 'true' if
 * such a partition exists, otherwise return false.
 */

struct hash_item {
  long long key;
  UT_hash_handle hh;
};

static inline struct hash_item *hash_find_item(struct hash_item **obj,
                                               long long key) {
  struct hash_item *p_entry = NULL;
  HASH_FIND(hh, *obj, &key, sizeof(key), p_entry);
  return p_entry;
}

bool hash_add_item(struct hash_item **obj, long long key) {
  if (hash_find_item(obj, key))
    return false;
  struct hash_item *p_entry =
      (struct hash_item *)malloc(sizeof(struct hash_item));
  p_entry->key = key;
  HASH_ADD(hh, *obj, key, sizeof(key), p_entry);
  return true;
}

void hash_free(struct hash_item **obj) {
  struct hash_item *curr, *tmp;
  HASH_ITER(hh, *obj, curr, tmp) {
    HASH_DEL(*obj, curr);
    free(curr);
  }
  *obj = NULL;
}

int **rotation(int **grid, int m, int n, int *new_m, int *new_n) {
  *new_m = n;
  *new_n = m;
  int **res = (int **)malloc(n * sizeof(int *));
  int *data = (int *)malloc(n * m * sizeof(int));
  for (int i = 0; i < n; i++)
    res[i] = data + i * m;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      res[j][m - 1 - i] = grid[i][j];
  return res;
}

void free_grid(int **grid, int n) {
  if (grid && grid[0])
    free(grid[0]);
  free(grid);
}

static inline bool check(struct hash_item **exist, int **curr, int curr_m,
                         int **original) {
  hash_free(exist);
  if (curr != original)
    free_grid(curr, curr_m);
  return true;
}

static inline void rotate_update(int ***curr_grid, int *curr_m, int *curr_n,
                                 int **original) {
  int new_m, new_n;
  int **new_grid = rotation(*curr_grid, *curr_m, *curr_n, &new_m, &new_n);
  if (*curr_grid != original)
    free_grid(*curr_grid, *curr_m);
  *curr_grid = new_grid;
  *curr_m = new_m;
  *curr_n = new_n;
}

bool canPartitionGrid(int **grid, int gridSize, int *gridColSize) {
  const int m = gridSize, n = gridColSize[0];
  long long total = 0;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      total += grid[i][j];
  int curr_m = m, curr_n = n, **curr_grid = grid;
  for (int k = 0; k < 4; k++) {
    struct hash_item *exist = NULL;
    hash_add_item(&exist, 0LL);
    long long sum = 0;
    if (curr_m < 2 || curr_n == 1) {
      if (curr_n == 1 && curr_m >= 2)
        for (int i = 0; i < curr_m - 1; i++) {
          sum += curr_grid[i][0];
          long long tag = sum * 2 - total;
          if (!tag || tag == curr_grid[0][0] || tag == curr_grid[i][0])
            return check(&exist, curr_grid, curr_m, grid);
        }
      rotate_update(&curr_grid, &curr_m, &curr_n, grid);
      hash_free(&exist);
      continue;
    }
    for (int i = 0; i < curr_m - 1; i++) {
      for (int j = 0; j < curr_n; j++) {
        hash_add_item(&exist, (long long)curr_grid[i][j]);
        sum += curr_grid[i][j];
      }
      long long tag = sum * 2 - total;
      if (!i) {
        if (!tag || tag == curr_grid[0][0] || tag == curr_grid[0][curr_n - 1])
          return check(&exist, curr_grid, curr_m, grid);
        continue;
      }
      if (hash_find_item(&exist, tag))
        return check(&exist, curr_grid, curr_m, grid);
    }
    rotate_update(&curr_grid, &curr_m, &curr_n, grid);
    hash_free(&exist);
  }
  if (curr_grid != grid)
    free_grid(curr_grid, curr_m);
  return false;
}

int main() {
  int g1i[2][2] = {{1, 4}, {2, 3}};
  int g2i[2][2] = {{1, 2}, {3, 4}};
  int g3i[2][3] = {{1, 2, 4}, {2, 3, 5}};
  int g4i[2][3] = {{4, 1, 8}, {3, 2, 6}};
  struct two_d_arr *g1 =
      two_d_arr_init(ARRAY_SIZE(g1i), ARRAY_SIZE(g1i[0]), g1i);
  struct two_d_arr *g2 =
      two_d_arr_init(ARRAY_SIZE(g2i), ARRAY_SIZE(g2i[0]), g2i);
  struct two_d_arr *g3 =
      two_d_arr_init(ARRAY_SIZE(g3i), ARRAY_SIZE(g3i[0]), g3i);
  struct two_d_arr *g4 =
      two_d_arr_init(ARRAY_SIZE(g4i), ARRAY_SIZE(g4i[0]), g4i);
  bool r1 = canPartitionGrid(g1->arr, g1->row_size, g1->col_size);
  bool r2 = canPartitionGrid(g2->arr, g2->row_size, g2->col_size);
  bool r3 = canPartitionGrid(g3->arr, g3->row_size, g3->col_size);
  bool r4 = canPartitionGrid(g4->arr, g4->row_size, g4->col_size);
  printf("%d\n", r1);
  assert(r1 == true);
  printf("%d\n", r2);
  assert(r2 == true);
  printf("%d\n", r3);
  assert(r3 == false);
  printf("%d\n", r4);
  assert(r4 == false);
  two_d_arr_free(g1);
  two_d_arr_free(g2);
  two_d_arr_free(g3);
  two_d_arr_free(g4);
}
