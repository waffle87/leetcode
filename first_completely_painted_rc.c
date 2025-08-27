// 2661. First Completely Painted Row or Column
#include "leetcode.h"

/*
 * you are given a 0-indexed integer array 'arr', and an 'm x n' integer array
 * 'matrix'. 'arr' and 'mat' bboth contain all the integers in the range '[1, m
 * * n]'. go through each index 'i' in 'arr' starting from index 0, and paint
 * the cell in 'mat' containing the integer 'arr[i]'. return the smallest index
 * 'i' at which either a row or a column will bbe completely painted in 'mat'.
 */

typedef struct {
  UT_hash_handle hh;
  int val;
  int row;
  int col;
} hElem;

int firstCompleteIndex(int *arr, int arrSize, int **mat, int matSize,
                       int *matColSize) {
  int m = matSize, n = matColSize[0];
  int *row_cnt = (int *)calloc(m, sizeof(int));
  int *col_cnt = (int *)calloc(n, sizeof(int));
  hElem *map = NULL, *tmp;
  for (int r = 0; r < m; r++)
    for (int c = 0; c < n; c++) {
      HASH_FIND_INT(map, &mat[r][c], tmp);
      if (!tmp) {
        tmp = (hElem *)malloc(sizeof(hElem));
        tmp->val = mat[r][c];
        tmp->row = r;
        tmp->col = c;
        HASH_ADD_INT(map, val, tmp);
      }
    }
  for (int i = 0; i < arrSize; i++) {
    int r = 0, c = 0;
    HASH_FIND_INT(map, &arr[i], tmp);
    if (tmp) {
      r = tmp->row;
      c = tmp->col;
    }
    ++row_cnt[r];
    ++col_cnt[c];
    if (n == row_cnt[r] || m == col_cnt[c])
      return i;
  }
  free(row_cnt);
  free(col_cnt);
  return -1;
}

int main() {
  int a1[] = {1, 3, 4, 2}, m1i[2][2] = {{1, 4}, {2, 3}};
  int a2[] = {2, 8, 7, 4, 1, 3, 5, 6, 9},
      m2i[3][3] = {{3, 2, 5}, {1, 4, 6}, {8, 7, 9}};
  struct two_d_arr *m1 =
      two_d_arr_init(ARRAY_SIZE(m1i), ARRAY_SIZE(m1i[0]), m1i);
  struct two_d_arr *m2 =
      two_d_arr_init(ARRAY_SIZE(m2i), ARRAY_SIZE(m2i[0]), m2i);
  printf("%d\n", firstCompleteIndex(a1, ARRAY_SIZE(a1), m1->arr, m1->row_size,
                                    m1->col_size)); // expect: 2
  printf("%d\n", firstCompleteIndex(a2, ARRAY_SIZE(a2), m2->arr, m2->row_size,
                                    m2->col_size)); // expect: 3
  two_d_arr_free(m1);
  two_d_arr_free(m2);
}
