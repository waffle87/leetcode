// 1665. Minimum Initial Energy to Finish Tasks
#include "leetcode.h"

/*
 * you are given an array 'tasks' where 'tasks[i] = [actual_i, minimum_i]'.
 * 'actual_i' is the actual amount of energy you spen to finish the i'th task,
 * and 'minimum_i' is the minimum amount of energy you require to begin the i'th
 * task. return the minimum initial amount of energy you will need to finish all
 * the tasks
 */

int cmp(const void *a, const void *b) {
  int *aa = *(int **)a;
  int *bb = *(int **)b;
  return (bb[1] - bb[0]) - (aa[1] - aa[0]);
}

int minimumEffort(int **tasks, int tasksSize, int *tasksColSize) {
  qsort(tasks, tasksSize, sizeof(int *), cmp);
  int need = 0;
  for (int i = tasksSize - 1; i >= 0; i--) {
    int actual = tasks[i][0];
    int minimum = tasks[i][1];
    need = (minimum > need + actual) ? minimum : need + actual;
  }
  return need;
}

int main() {
  int t1i[3][2] = {{1, 2}, {2, 4}, {4, 8}};
  int t2i[5][2] = {{1, 3}, {2, 4}, {10, 11}, {10, 12}, {8, 9}};
  int t3i[6][2] = {{1, 7}, {2, 8}, {3, 9}, {4, 10}, {5, 11}, {6, 12}};
  struct two_d_arr *t1 =
      two_d_arr_init(ARRAY_SIZE(t1i), ARRAY_SIZE(t1i[0]), t1i);
  struct two_d_arr *t2 =
      two_d_arr_init(ARRAY_SIZE(t2i), ARRAY_SIZE(t2i[0]), t2i);
  struct two_d_arr *t3 =
      two_d_arr_init(ARRAY_SIZE(t3i), ARRAY_SIZE(t3i[0]), t3i);
  int r1 = minimumEffort(t1->arr, t1->row_size, t1->col_size);
  int r2 = minimumEffort(t2->arr, t2->row_size, t2->col_size);
  int r3 = minimumEffort(t3->arr, t3->row_size, t3->col_size);
  printf("%d\n", r1);
  assert(r1 == 8);
  printf("%d\n", r2);
  assert(r2 == 32);
  printf("%d\n", r3);
  assert(r3 == 27);
  two_d_arr_free(t1);
  two_d_arr_free(t2);
  two_d_arr_free(t3);
}
