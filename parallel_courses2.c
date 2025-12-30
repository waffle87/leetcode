// 1494. Parallel Courses II
#include "leetcode.h"

/*
 * you are given an integer 'n' which indicates that there are 'n' courses
 * labeled from 1 to 'n'. you are also given an array 'relations' where
 * 'relations[i] = [prev_course[i], next_course[i]]', representing a
 * prerequisite relationship between course 'prev_course' and course
 * 'next_course': course 'prev_course' has to be taken before 'next_course'.
 * also, you are given integer 'k'. in one semester, you can take most 'k'
 * course as long as you have taken all the prerequisites in the previous
 * semesters for the courses you are taking. return the minimum number of
 * semesters needed to take all courses. the testcases will be generated such
 * that it is possible to take every course.
 */

int minNumberOfSemesters(int n, int **relations, int relationsSize,
                         int *relationsColSize, int k) {
  int *dp = (int *)malloc((1 << n) * sizeof(int));
  int *prereq = (int *)calloc(1 << n, sizeof(int));
  int *pre_course = (int *)malloc(n);
  for (int i = 0; i < (1 << n); i++)
    dp[i] = INT_MAX / 2;
  for (int i = 0; i < relationsSize; i++) {
    int u = relations[i][0] - 1;
    int v = relations[i][1] - 1;
    pre_course[v] |= (1 << u);
  }
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < n; j++)
      if ((i >> j) & 1)
        prereq[i] |= pre_course[j];
    if (!prereq[i] && __builtin_popcount(i) <= k)
      dp[i] = 1;
  }
  dp[0] = 0;
  for (int i = 0; i < (1 << n); i++) {
    int x = __builtin_popcount(i);
    for (int j = i; j > 0; j = ((j - 1) & j)) {
      int y = __builtin_popcount(j);
      if (x - y > k)
        continue;
      if ((prereq[i] & j) == prereq[i])
        dp[i] = fmin(dp[i], dp[j] + 1);
    }
  }
  int ans = (dp[(1 << n) - 1] == INT_MAX / 2) ? -1 : dp[(1 << n) - 1];
  free(dp);
  free(prereq);
  free(pre_course);
  return ans;
}

int main() {
  int r1i[3][2] = {{2, 1}, {3, 1}, {1, 4}};
  int r2i[4][2] = {{2, 1}, {3, 1}, {4, 1}, {1, 5}};
  struct two_d_arr *r1 =
      two_d_arr_init(ARRAY_SIZE(r1i), ARRAY_SIZE(r1i[0]), r1i);
  struct two_d_arr *r2 =
      two_d_arr_init(ARRAY_SIZE(r2i), ARRAY_SIZE(r2i[0]), r2i);
  printf("%d\n", minNumberOfSemesters(4, r1->arr, r1->row_size, r1->col_size,
                                      2)); // expect: 3
  printf("%d\n", minNumberOfSemesters(5, r2->arr, r2->row_size, r2->col_size,
                                      2)); // expect: 4
  two_d_arr_free(r1);
  two_d_arr_free(r2);
}
