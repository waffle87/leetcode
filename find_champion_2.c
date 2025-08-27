// 2924. Find Champion II
#include "leetcode.h"

/*
 * there are 'n' teams numbered from 0 to 'n - 1' in a tournament; each team is
 * also a node in DAG. you are given the integer 'n' and a 0-indexed 2d integer
 * array 'edges' of length 'm' representing the DAG, where 'edges[i] = [u_i,
 * v_i]' indicates that is a directed edge from team 'u_i' to team 'v_i' in the
 * graph. a directed edge from 'a' to 'b' in the graph means that team 'a' is
 * strong than team 'b' and team 'b' is weaker than team 'a'. return the team
 * that will be the champion of the tournament if there is a unique champion,
 * otherwise return -1.
 */

int findChampion(int n, int **edges, int edgesSize, int *edgesColSize) {
  char state[n];
  memset(state, 'w', sizeof(state));
  for (int i = 0; i < edgesSize; i++)
    state[edges[i][1]] = 'l';
  int cnt = 0, ans = 0;
  for (int i = 0; i < n; i++)
    if (state[i] == 'w') {
      cnt++;
      ans = i;
    }
  return cnt == 1 ? ans : -1;
}

int main() {
  int e1i[2][2] = {{0, 1}, {1, 2}}, e2i[3][2] = {{0, 2}, {1, 3}, {1, 2}};
  struct two_d_arr *e1 = two_d_arr_init(2, 2, e1i);
  struct two_d_arr *e2 = two_d_arr_init(3, 2, e2i);
  printf("%d\n",
         findChampion(3, e1->arr, e1->row_size, e1->col_size)); // expect:
                                                                // 0
  printf("%d\n",
         findChampion(4, e2->arr, e2->row_size, e2->col_size)); // expect: -1
  two_d_arr_free(e1);
  two_d_arr_free(e2);
}
