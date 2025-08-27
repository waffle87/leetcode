// 56. Merge Intervals
#include "leetcode.h"

/*
 * given an array of 'intervals' where 'intervals[i] = [start_i, end_i]', merge
 * all overlapping intervals, and return an array of the non-overlapping
 * intervals that cover all the intervals in the input.
 */

int cmp(const void *a, const void *b) {
  return (*(int **)a)[0] - (*(int **)b)[0];
}

int **merge(int **intervals, int intervalsSize, int *intervalsColSize,
            int *returnSize, int **returnColumnSizes) {
  qsort(intervals, intervalsSize, sizeof(int *), cmp);
  int **stack = (int **)malloc(intervalsSize * sizeof(int *)), top = 1;
  stack[0] = intervals[0];
  for (int i = 1; i < intervalsSize; i++) {
    if (intervals[i][0] <= stack[top - 1][1])
      stack[top - 1][1] = intervals[i][1] > stack[top - 1][1]
                              ? intervals[i][1]
                              : stack[top - 1][1];
    else
      stack[top++] = intervals[i];
  }
  *returnSize = top;
  *returnColumnSizes = (int *)malloc((*returnSize) * sizeof(int));
  for (int i = 0; i < *returnSize; i++)
    (*returnColumnSizes)[i] = 2;
  return stack;
}

int main() {
  int i1i[4][2] = {{1, 3}, {2, 6}, {8, 10}, {15, 18}},
      i2i[2][2] = {{1, 4}, {4, 5}};
  struct two_d_arr *i1 =
      two_d_arr_init(ARRAY_SIZE(i1i), ARRAY_SIZE(i1i[0]), i1i);
  struct two_d_arr *i2 =
      two_d_arr_init(ARRAY_SIZE(i2i), ARRAY_SIZE(i2i[0]), i2i);
  int rs1, *rcs1, rs2, *rcs2;
  int **m1 = merge(i1->arr, i1->row_size, i1->col_size, &rs1, &rcs1);
  int **m2 = merge(i2->arr, i2->row_size, i2->col_size, &rs2, &rcs2);
  for (int i = 0; i < rs1; i++) {
    for (int j = 0; j < rcs1[i]; j++)
      printf("%d ", m1[i][j]); // expect: [[1,6],[8,10],[15,18]]
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    for (int j = 0; j < rcs2[i]; j++)
      printf("%d ", m2[i][j]); // expect: [[1,5]]
    printf("\n");
  }
  printf("\n");
  for (int i = 0; i < rs1; i++)
    free(m1[i]);
  free(m1);
  two_d_arr_free(i1);
  for (int i = 0; i < rs2; i++)
    free(m2[i]);
  free(m2);
  two_d_arr_free(i2);
}
