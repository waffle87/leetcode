// 3414. Maximum Score of Non-overlapping Intervals
#include "leetcode.h"

/*
 * you are given a 2d integer array 'intervals' where 'intervals[i] = [l_i, r_i,
 * weight_i]'. interval 'i' starts at position 'l_i', and ends at 'r_i' and has
 * a weight of 'weight_i'. you can choose up to 4 non overlapping intervals. the
 * score of the chosen intervals is defined as the total sum of their weights.
 * return the lexicographically smallest array of at most 4 indices from
 * 'intervals' with maximum score, representing your choice of non-overlapping
 * intervals.
 */

struct interval {
  int l;
  int r;
  int weight;
  int idx;
};

int cmp1(const void *a, const void *b) {
  return ((struct interval *)a)->r - ((struct interval *)b)->r;
}

int cmp2(const void *a, const void *b) { return (*(int *)a) - (*(int *)b); }

int binary_search(struct interval *a, int end, int x) {
  int left = 0, right = end;
  while (left < right) {
    int mid = (left + right) / 2;
    if (a[mid].r < x)
      left = mid + 1;
    else
      right = mid;
  }
  return left;
}

int compare_arrays(int *a, int n, int *b, int m) {
  int min = fmin(n, m);
  for (int i = 0; i < min; i++)
    if (a[i] != b[i])
      return a[i] - b[i];
  return n - m;
}

int *maximumWeight(int **intervals, int intervalsSize, int *intervalsColSize,
                   int *returnSize) {
  int n = intervalsSize;
  struct interval *arr = (struct interval *)malloc(n * sizeof(struct interval));
  for (int i = 0; i < n; i++) {
    arr[i].l = intervals[i][0];
    arr[i].r = intervals[i][1];
    arr[i].weight = intervals[i][2];
    arr[i].idx = i;
  }
  qsort(arr, n, sizeof(struct interval), cmp1);
  long long **dp = (long long **)malloc((n + 1) * sizeof(long long *));
  int ***indices = (int ***)malloc((n + 1) * sizeof(int **));
  int **indices_size = (int **)malloc((n + 1) * sizeof(int *));
  for (int i = 0; i <= n; i++) {
    dp[i] = (long long *)calloc(5, sizeof(long long));
    indices[i] = (int **)malloc(5 * sizeof(int *));
    indices_size[i] = (int *)calloc(5, sizeof(int));
    for (int j = 0; j < 5; j++) {
      indices[i][j] = NULL;
    }
  }
  for (int i = 0; i < n; i++) {
    int l = arr[i].l, weight = arr[i].weight, idx = arr[i].idx;
    int k = binary_search(arr, i, l);
    for (int j = 1; j < 5; j++) {
      long long s1 = dp[i][j];
      long long s2 = dp[k][j - 1] + weight;
      if (s1 > s2) {
        dp[i + 1][j] = dp[i][j];
        if (indices[i + 1][j])
          free(indices[i + 1][j]);
        indices[i + 1][j] = (int *)malloc(indices_size[i][j] * sizeof(int));
        memcpy(indices[i + 1][j], indices[i][j],
               indices_size[i][j] * sizeof(int));
        indices_size[i + 1][j] = indices_size[i][j];
        continue;
      }
      int new_size = indices_size[k][j - 1] + 1;
      int *new_idx = (int *)malloc(new_size * sizeof(int));
      if (indices_size[k][j - 1] > 0) {
        memcpy(new_idx, indices[k][j - 1],
               indices_size[k][j - 1] * sizeof(int));
      }
      new_idx[indices_size[k][j - 1]] = idx;
      qsort(new_idx, new_size, sizeof(int), cmp2);
      if (s1 == s2 && compare_arrays(indices[i][j], indices_size[i][j], new_idx,
                                     new_size) < 0) {
        free(new_idx);
        new_idx = (int *)malloc(indices_size[i][j] * sizeof(int));
        memcpy(new_idx, indices[i][j], indices_size[i][j] * sizeof(int));
        new_size = indices_size[i][j];
      }
      dp[i + 1][j] = s2;
      if (indices[i + 1][j])
        free(indices[i + 1][j]);
      indices[i + 1][j] = new_idx;
      indices_size[i + 1][j] = new_size;
    }
  }
  *returnSize = indices_size[n][4];
  int *ans = (int *)malloc(*returnSize * sizeof(int));
  memcpy(ans, indices[n][4], *returnSize * sizeof(int));
  for (int i = 0; i <= n; i++) {
    free(dp[i]);
    for (int j = 0; j < 5; j++) {
      if (indices[i][j])
        free(indices[i][j]);
    }
    free(indices[i]);
    free(indices_size[i]);
  }
  free(dp);
  free(indices);
  free(indices_size);
  free(arr);
  return ans;
}

int main() {
  int i1i[6][3] = {{1, 3, 2}, {4, 5, 2}, {1, 5, 5},
                   {6, 9, 3}, {6, 7, 1}, {8, 9, 1}};
  int r1[] = {2, 3}, rs1;
  int i2i[7][3] = {{5, 8, 1}, {6, 7, 7},   {4, 7, 3}, {9, 10, 6},
                   {7, 8, 2}, {11, 14, 3}, {3, 5, 5}};
  int r2[] = {1, 3, 5, 6}, rs2;
  struct two_d_arr *i1 =
      two_d_arr_init(ARRAY_SIZE(i1i), ARRAY_SIZE(i1i[0]), i1i);
  struct two_d_arr *i2 =
      two_d_arr_init(ARRAY_SIZE(i2i), ARRAY_SIZE(i2i[0]), i2i);
  int *mw1 = maximumWeight(i1->arr, i1->row_size, i1->col_size, &rs1);
  int *mw2 = maximumWeight(i2->arr, i2->row_size, i2->col_size, &rs2);
  for (int i = 0; i < rs1; i++) {
    printf("%d ", mw1[i]);
    assert(mw1[i] == r1[i]);
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    printf("%d ", mw2[i]);
    assert(mw2[i] == r2[i]);
  }
  printf("\n");
  free(mw1);
  free(mw2);
  two_d_arr_free(i1);
  two_d_arr_free(i2);
}
