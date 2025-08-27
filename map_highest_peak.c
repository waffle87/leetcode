// 1765. Map of Highest Peak
#include "leetcode.h"

/*
 * you are given an integer matrix 'isWater' of size 'm x n' that represents a
 * map of land and water cells. if 'isWater[i][j] == 0' cell '(i, j)' is a land
 * cell. if 'isWater[i][j] == 1', cell '(i, j)' is a water cell. you must assign
 * each cell a height in a way that follows the given rules. find an assignment
 * of heights such that the maximum height in the matrix is maximised.
 */

struct land {
  int x;
  int y;
  int val;
  struct land *next;
};

struct land *head, *tail;

void push(int x, int y, int val) {
  struct land *tmp = (struct land *)malloc(sizeof(struct land));
  tmp->x = x;
  tmp->y = y;
  tmp->val = val;
  tmp->next = NULL;
  if (!head) {
    head = tmp;
    tail = tmp;
  } else {
    tail->next = tmp;
    tail = tmp;
  }
}

void bfs(int **isWater, int row, int col, struct land *curr) {
  isWater[curr->x][curr->y] = curr->val ? curr->val : -1;
  if (curr->x - 1 >= 0)
    if (!isWater[curr->x - 1][curr->y]) {
      isWater[curr->x - 1][curr->y] = -1;
      push(curr->x - 1, curr->y, curr->val + 1);
    }
  if (curr->x + 1 < row)
    if (!isWater[curr->x + 1][curr->y]) {
      isWater[curr->x + 1][curr->y] = -1;
      push(curr->x + 1, curr->y, curr->val + 1);
    }
  if (curr->y - 1 >= 0)
    if (!isWater[curr->x][curr->y - 1]) {
      isWater[curr->x][curr->y - 1] = -1;
      push(curr->x, curr->y - 1, curr->val + 1);
    }
  if (curr->y + 1 < col)
    if (!isWater[curr->x][curr->y + 1]) {
      isWater[curr->x][curr->y + 1] = -1;
      push(curr->x, curr->y + 1, curr->val + 1);
    }
  if (curr->next)
    bfs(isWater, row, col, curr->next);
  free(curr);
}

int **highestPeak(int **isWater, int isWaterSize, int *isWaterColSize,
                  int *returnSize, int **returnColumnSizes) {
  head = NULL, tail = NULL;
  for (int i = 0; i < isWaterSize; i++)
    for (int j = 0; j < *isWaterColSize; j++)
      if (isWater[i][j])
        push(i, j, 0);
  int col = *isWaterColSize;
  bfs(isWater, isWaterSize, *isWaterColSize, head);
  for (int i = 0; i < isWaterSize; i++)
    for (int j = 0; j < *isWaterColSize; j++)
      if (isWater[i][j] == -1)
        isWater[i][j] = 0;
  *returnSize = isWaterSize;
  *returnColumnSizes = (int *)malloc(isWaterSize * sizeof(int));
  for (int i = 0; i < *returnSize; i++)
    (*returnColumnSizes)[i] = *isWaterColSize;
  return isWater;
}

int main() {
  int iw1i[2][2] = {{0, 1}, {0, 0}},
      iw2i[3][3] = {{0, 0, 1}, {1, 0, 0}, {0, 0, 0}};
  struct two_d_arr *iw1 =
      two_d_arr_init(ARRAY_SIZE(iw1i), ARRAY_SIZE(iw1i[0]), iw1i);
  struct two_d_arr *iw2 =
      two_d_arr_init(ARRAY_SIZE(iw2i), ARRAY_SIZE(iw2i[0]), iw2i);
  int rs1, rs2, *rcs1, *rcs2;
  int **hp1 = highestPeak(iw1->arr, iw1->row_size, iw1->col_size, &rs1, &rcs1);
  int **hp2 = highestPeak(iw2->arr, iw2->row_size, iw2->col_size, &rs2, &rcs2);
  for (int i = 0; i < rs1; i++) {
    for (int j = 0; j < rcs1[i]; j++)
      printf("%d ", hp1[i][j]); // expect: 1 0 2 1
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    for (int j = 0; j < rcs2[i]; j++)
      printf("%d ", hp2[i][j]); // expect: 1 1 0 0 1 1 1 2 2
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < rs1; i++)
    free(hp1[i]);
  free(hp1);
  free(rcs1);
  two_d_arr_free(iw1);
  for (int i = 0; i < rs2; i++)
    free(hp2[i]);
  free(hp2);
  free(rcs2);
  two_d_arr_free(iw2);
}
