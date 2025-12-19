// 2092. Find All People With Secret
#include "leetcode.h"

/*
 * given an integer 'n' indicating there are 'n' people numbered from 0 to 'n -
 * 1'. you are also given a 0-indexed 2d integer array 'meetings' where
 * 'meetings[i] = [x_i, y_i, time_i]' indicates that person 'x_i'  and person
 * 'y_i' have a metting at 'time_i'. a person may attend multiple meetings at
 * the same time. finally, you are given an integer 'firstPerson'. person 0 has
 * a secret and initially shares the secret with a person 'firstPerson' at time
 * 0. this secret is then shared every time a meeting takes place with a person
 * that has the secret. more formall, for every meeting 'x_i', has secret at
 * 'time_i' then they will share the secret with person 'y_i' and vice versa
 */

int find(int *groups, int idx) {
  while (idx != groups[idx])
    idx = groups[idx];
  return idx;
}

int cmp(const void *a, const void *b) {
  const int *aa = *(const int **)a;
  const int *bb = *(const int **)b;
  return aa[2] - bb[2];
}

int *findAllPeople(int n, int **meetings, int meetingsSize,
                   int *meetingsColSize, int firstPerson, int *returnSize) {
  int *groups = (int *)malloc(n * sizeof(int));
  int *ans = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
    groups[i] = i;
  groups[firstPerson] = 0;
  qsort(meetings, meetingsSize, sizeof(meetings[0]), cmp);
  int *tmp = (int *)malloc(2 * n * sizeof(int));
  int ans_cnt = 0, i = 0;
  while (i < meetingsSize) {
    int curr_time = meetings[i][2], tmp_cnt = 0;
    while (i < meetingsSize && meetings[i][2] == curr_time) {
      int g1 = find(groups, meetings[i][0]), g2 = find(groups, meetings[i][1]);
      groups[g1 > g2 ? g1 : g2] = g1 < g2 ? g1 : g2;
      tmp[tmp_cnt++] = meetings[i][0];
      tmp[tmp_cnt++] = meetings[i][1];
      i++;
    }
    for (int j = 0; j < tmp_cnt; j++)
      if (find(groups, tmp[j]))
        groups[tmp[j]] = tmp[j];
  }
  for (int j = 0; j < n; j++)
    if (!find(groups, j))
      ans[ans_cnt++] = j;
  free(tmp);
  free(groups);
  *returnSize = ans_cnt;
  return ans;
}

int main() {
  int m1i[3][3] = {{1, 2, 5}, {2, 3, 8}, {1, 5, 10}}, rs1;
  int m2i[3][3] = {{3, 1, 3}, {1, 2, 2}, {0, 3, 3}}, rs2;
  int m3i[3][3] = {{3, 4, 2}, {1, 2, 1}, {2, 3, 1}}, rs3;
  struct two_d_arr *m1 =
      two_d_arr_init(ARRAY_SIZE(m1i), ARRAY_SIZE(m1i[0]), m1i);
  struct two_d_arr *m2 =
      two_d_arr_init(ARRAY_SIZE(m2i), ARRAY_SIZE(m2i[0]), m2i);
  struct two_d_arr *m3 =
      two_d_arr_init(ARRAY_SIZE(m3i), ARRAY_SIZE(m3i[0]), m3i);
  int *fap1 = findAllPeople(6, m1->arr, m1->row_size, m1->col_size, 1, &rs1);
  int *fap2 = findAllPeople(4, m2->arr, m2->row_size, m2->col_size, 3, &rs2);
  int *fap3 = findAllPeople(5, m3->arr, m3->row_size, m3->col_size, 1, &rs3);
  for (int i = 0; i < 5; i++)
    printf("%d ", fap1[i]); // expect: 0 1 2 3 5
  printf("\n");
  for (int i = 0; i < 3; i++)
    printf("%d ", fap2[i]); // expect: 0 1 3
  printf("\n");
  for (int i = 0; i < 5; i++)
    printf("%d ", fap3[i]); // expect: 0 1 2 3 4
  printf("\n");
  free(fap1);
  free(fap2);
  free(fap3);
  two_d_arr_free(m1);
  two_d_arr_free(m2);
  two_d_arr_free(m3);
}
