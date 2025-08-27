// 1462. Course Schedule IV
#include "leetcode.h"

/*
 * there are a total of 'numCourses' courses that you have to take, labeled from
 * 0 to 'numCourses - 1'. you are given an array 'prerequisites' where
 * 'prerequisites[i] = [a_i, b_i]' indicates that you must take course 'a_i'
 * before 'b_i'. prerequisites can also be indirect. if course 'a' is a
 * prerequisite of course 'b', and course 'b' is a prerequisite of course 'c',
 * then course 'a' is a prerequisite of course 'c'. you are also given an array
 * 'queries' where 'queries[j] = [u_j, v_j]'. for the j'th query, you should
 * answer whether course 'u_j' is a prerequisite of course 'v_j' or not.
 */

bool *checkIfPrerequisite(int numCourses, int **prerequisites,
                          int prerequisitesSize, int *prerequisitesColSize,
                          int **queries, int queriesSize, int *queriesColSize,
                          int *returnSize) {
  *returnSize = queriesSize;
  bool *ans = (bool *)malloc(queriesSize * sizeof(bool));
  bool **connected = (bool **)malloc(numCourses * sizeof(bool *));
  for (int i = 0; i < numCourses; i++)
    connected[i] = (bool *)calloc(numCourses, sizeof(bool));
  for (int i = 0; i < prerequisitesSize; i++) {
    int a = prerequisites[i][0];
    int b = prerequisites[i][1];
    connected[a][b] = true;
  }
  for (int k = 0; k < numCourses; k++)
    for (int i = 0; i < numCourses; i++)
      for (int j = 0; j < numCourses; j++)
        if (connected[i][k] && connected[k][j])
          connected[i][j] = true;
  for (int i = 0; i < queriesSize; i++) {
    int u = queries[i][0];
    int v = queries[i][1];
    ans[i] = connected[u][v];
  }
  for (int i = 0; i < numCourses; i++)
    free(connected[i]);
  free(connected);
  return ans;
}

int main() {
  int p1i[1][2] = {{1, 0}}, q1i[2][2] = {{0, 1}, {1, 0}}, rs1;
  int p2i[1][0] = {{}}, q2i[2][2] = {{1, 0}, {0, 1}}, rs2;
  int p3i[3][2] = {{1, 2}, {1, 0}, {2, 0}}, q3i[2][2] = {{1, 0}, {1, 2}}, rs3;
  struct two_d_arr *p1 =
      two_d_arr_init(ARRAY_SIZE(p1i), ARRAY_SIZE(p1i[0]), p1i);
  struct two_d_arr *p2 = two_d_arr_init(0, ARRAY_SIZE(p2i[0]), p2i);
  struct two_d_arr *p3 =
      two_d_arr_init(ARRAY_SIZE(p3i), ARRAY_SIZE(p3i[0]), p3i);
  struct two_d_arr *q1 =
      two_d_arr_init(ARRAY_SIZE(q1i), ARRAY_SIZE(q1i[0]), q1i);
  struct two_d_arr *q2 =
      two_d_arr_init(ARRAY_SIZE(q2i), ARRAY_SIZE(q2i[0]), q2i);
  struct two_d_arr *q3 =
      two_d_arr_init(ARRAY_SIZE(q3i), ARRAY_SIZE(q3i[0]), q3i);
  bool *cip1 = checkIfPrerequisite(2, p1->arr, p1->row_size, p1->col_size,
                                   q1->arr, q1->row_size, q1->col_size, &rs1);
  bool *cip2 = checkIfPrerequisite(2, p2->arr, p2->row_size, p2->col_size,
                                   q2->arr, q2->row_size, q2->col_size, &rs2);
  bool *cip3 = checkIfPrerequisite(3, p3->arr, p3->row_size, p3->col_size,
                                   q3->arr, q3->row_size, q3->col_size, &rs3);
  for (int i = 0; i < rs1; i++)
    printf("%d ", cip1[i]); // expect: 0 1
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", cip2[i]); // expect: 0 0
  printf("\n");
  for (int i = 0; i < rs3; i++)
    printf("%d ", cip3[i]); // expect: 1 1
  printf("\n");
  free(cip1);
  free(cip2);
  free(cip3);
  two_d_arr_free(p1);
  two_d_arr_free(p2);
  two_d_arr_free(p3);
  two_d_arr_free(q1);
  two_d_arr_free(q2);
  two_d_arr_free(q3);
}
