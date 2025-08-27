// 2503. Maximum Number of Points From Grid Queries
#include "leetcode.h"

/*
 * you are given an 'm x n' integer matrix 'grid' and an array 'queries' of size
 * 'k'. find an array 'answer' of size 'k' such that for each integer
 * 'queries[i]' start in the top left cell of the matrix and repeat the
 * following process: if 'queries[i]' is strictly greater than the value of the
 * current cell that you are in, then you get one point if it is your first time
 * visiting that cell, and you can move to any adjacent cell in all 4
 * directions, otherwise you do not get any points, and you end this process.
 * after the process 'answer[i]' is the maximum number of ponts you can get.
 * note that for each query, yu are allowed to visit the same cell multiple
 * times.
 */

struct list {
  int val;
  int x;
  int y;
};

struct pp {
  int val;
  int place;
};

int cmp(const void *a, const void *b) {
  return (*(struct pp *)a).val - (*(struct pp *)b).val;
}

void input(int **grid, int gridSize, int gridColSize, int i, int j,
           struct list *helper, int *cnt, bool **used, int *curr_point,
           int curr_val) {
  used[i][j] = true;
  if (curr_val > grid[i][j]) {
    *curr_point += 1;
    if (i - 1 >= 0 && !used[i - 1][j])
      input(grid, gridSize, gridColSize, i - 1, j, helper, cnt, used,
            curr_point, curr_val);
    if (i + 1 < gridSize && !used[i + 1][j])
      input(grid, gridSize, gridColSize, i + 1, j, helper, cnt, used,
            curr_point, curr_val);
    if (j - 1 >= 0 && !used[i][j - 1])
      input(grid, gridSize, gridColSize, i, j - 1, helper, cnt, used,
            curr_point, curr_val);
    if (j + 1 < gridColSize && !used[i][j + 1])
      input(grid, gridSize, gridColSize, i, j + 1, helper, cnt, used,
            curr_point, curr_val);
  } else {
    helper[*cnt].val = grid[i][j];
    helper[*cnt].x = i;
    helper[*cnt].y = j;
    (*cnt)++;
  }
}

int *maxPoints(int **grid, int gridSize, int *gridColSize, int *queries,
               int queriesSize, int *returnSize) {
  int curr_point = 0, c1 = 0, c2 = 0;
  struct list *h1 = (struct list *)malloc((gridSize * (*gridColSize)) *
                                          sizeof(struct list *));
  struct list *h2 = (struct list *)malloc((gridSize * (*gridColSize)) *
                                          sizeof(struct list *));
  struct pp *revis = (struct pp *)malloc(queriesSize * sizeof(struct pp));
  for (int i = 0; i < queriesSize; i++) {
    revis[i].val = queries[i];
    revis[i].place = i;
  }
  qsort(revis, queriesSize, sizeof(struct pp), cmp);
  *returnSize = queriesSize;
  int *ans = (int *)malloc(queriesSize * sizeof(int));
  bool **used = (bool **)malloc(queriesSize * sizeof(bool *));
  for (int i = 0; i < gridSize; i++)
    used[i] = (bool *)calloc(*gridColSize, sizeof(bool));
  input(grid, gridSize, *gridColSize, 0, 0, h1, &c1, used, &curr_point,
        revis[0].val);
  ans[revis[0].place] = curr_point;
  for (int i = 1; i < queriesSize; i++) {
    if ((i & 1) == 1) {
      c2 = 0;
      for (int j = 0; j < c1; j++)
        input(grid, gridSize, *gridColSize, h1[j].x, h1[j].y, h2, &c2, used,
              &curr_point, revis[i].val);
    } else {
      c1 = 0;
      for (int j = 0; j < c2; j++)
        input(grid, gridSize, *gridColSize, h2[j].x, h2[j].y, h1, &c1, used,
              &curr_point, revis[i].val);
    }
    ans[revis[i].place] = curr_point;
  }
  free(revis);
  free(h1);
  free(h2);
  for (int i = 0; i < gridSize; i++)
    free(used[i]);
  free(used);
  return ans;
}

int main() {
  int g1i[3][3] = {{1, 2, 3}, {2, 5, 7}, {3, 5, 1}}, q1[] = {5, 6, 2}, rs1;
  int g2i[2][3] = {{5, 2, 1}, {1, 1, 2}}, q2[] = {3}, rs2;
  struct two_d_arr *g1 =
      two_d_arr_init(ARRAY_SIZE(g1i), ARRAY_SIZE(g1i[0]), g1i);
  struct two_d_arr *g2 =
      two_d_arr_init(ARRAY_SIZE(g2i), ARRAY_SIZE(g2i[0]), g2i);
  int *mp1 =
      maxPoints(g1->arr, g1->row_size, g1->col_size, q1, ARRAY_SIZE(q1), &rs1);
  int *mp2 =
      maxPoints(g2->arr, g2->row_size, g2->col_size, q2, ARRAY_SIZE(q2), &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", mp1[i]); // expect: 5 8 1
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", mp2[i]); // expect: 0
  printf("\n");
  free(mp1);
  free(mp2);
  two_d_arr_free(g1);
  two_d_arr_free(g2);
}
