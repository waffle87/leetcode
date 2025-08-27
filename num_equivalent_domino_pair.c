// 1128. Number of Equivalent Domino Pairs
#include "leetcode.h"

/*
 * given a list of 'dominoes', 'dominoes[i] = [a, b]' is equivalent to
 * 'dominoes[j] = [c, d]' if and only if either 'a == c' and 'b == d' or 'a ==
 * d' and 'b == c'. return the number of pairs '(i, j)' for which '0 <= i < j <
 * dominoes.length' and 'dominoes[i]' is equivalent to 'dominoes[j]'.
 */

int numEquivDominoPairs(int **dominoes, int dominoesSize,
                        int *dominoesColSize) {
  int map[100] = {0}, cnt = 0;
  for (int i = 0; i < dominoesSize; ++i) {
    int u = dominoes[i][0], v = dominoes[i][1];
    int num = u > v ? v * 10 + u : u * 10 + v;
    cnt += map[num];
    map[num]++;
  }
  return cnt;
}

int main() {
  int d1i[4][2] = {{1, 2}, {2, 1}, {3, 4}, {5, 6}};
  int d2i[5][2] = {{1, 2}, {1, 2}, {1, 1}, {1, 2}, {2, 2}};
  struct two_d_arr *d1 =
      two_d_arr_init(ARRAY_SIZE(d1i), ARRAY_SIZE(d1i[0]), d1i);
  struct two_d_arr *d2 =
      two_d_arr_init(ARRAY_SIZE(d2i), ARRAY_SIZE(d2i[0]), d2i);
  printf("%d\n",
         numEquivDominoPairs(d1->arr, d1->row_size, d1->col_size)); // expect: 1
  printf("%d\n",
         numEquivDominoPairs(d2->arr, d2->row_size, d2->col_size)); // expect: 3
  two_d_arr_free(d1);
  two_d_arr_free(d2);
}
