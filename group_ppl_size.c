// 1282. Group the People Given the Group Size They Belong To
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * there are 'n' people that are split into some unknown number of groups. each
 * person is labeled with a unique id from 0 to 'n - 1'. you are given an
 * integer array 'group_sizes' where 'group_sizes[i]' is the size of the group
 * that person 'i' is in. for example if 'group_sizes[i] = 3', then person 1
 * must be in a groiup size of 3. return a list of groups such that each person
 * 'i' is in a group of size 'group_sizes[i]'. each person should appear in
 * exactly one group, and every person must be in a group. if there are multiple
 * answers, return any of them. it is guaranteed that there will be at least one
 * valid solution for the given input.
 */

int **groupThePeople(int *group_sizes, int group_sizes_size, int *return_size,
                     int **return_col_size) {
  int table[group_sizes_size + 1][group_sizes_size + 1],
      col[group_sizes_size + 1];
  memset(table, 0, sizeof(table));
  memset(col, 0, sizeof(col));
  int **ans = (int **)malloc(sizeof(int *) * group_sizes_size);
  *return_size = 0;
  *return_col_size = (int *)malloc(sizeof(int) * group_sizes_size);
  for (int i = 0; i < group_sizes_size; i++) {
    table[group_sizes[i]][col[group_sizes[i]]] = i;
    col[group_sizes[i]]++;
  }
  for (int i = 0; i <= group_sizes_size; i++) {
    int k = 0;
    while (col[i]) {
      ans[*return_size] = (int *)malloc(sizeof(int) * i);
      (*return_col_size)[*return_size] = i;
      for (int j = 0; j < i; j++) {
        ans[*return_size][j] = table[i][k++];
        col[i]--;
      }
      (*return_size)++;
    }
  }
  return ans;
}

int main() {
  int gs1[] = {3, 3, 3, 3, 3, 1, 3}, gs2[] = {2, 1, 3, 3, 3, 2};
  int **gtp1 = groupThePeople(gs1, 7, NULL, NULL);
  int **gtp2 = groupThePeople(gs2, 6, NULL, NULL);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      printf("%d ", gtp1[i][j]);
  printf("\n");
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      printf("%d ", gtp2[i][j]);
  printf("\n");
}
