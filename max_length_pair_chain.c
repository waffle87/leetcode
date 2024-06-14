// 646. Maximum Length of Pair Chain
#include <stdio.h>
#include <stdlib.h>

/*
 * given a n array of 'n' pairs, where 'pairs[i]= [lefti, righti]' and 'left[i]
 * < right[i]'. a pair 'p2 = [c, d]' follows a pair 'p1 = [a, b]' if 'b < c'. a
 * chain of pairs can be formed in this fashion. return the length of the
 * longest chain which can be formed. you do not need to use up all the given
 * intervals. you can select pairs in any order.
 */

int cmp(int **a, int **b) {
  int *tmpa = *a;
  int *tmpb = *b;
  if (tmpa[1] == tmpb[1])
    return tmpa[0] - tmpb[0];
  return tmpa[1] - tmpb[1];
}

int findLongestChain(int **pairs, int pairs_size, int *pairs_col_size) {
  qsort(pairs, pairs_size, sizeof(int *), cmp);
  int ans = 1, k = 0;
  for (int i = 1; i < pairs_size; i++)
    if (pairs[i][0] > pairs[k][1]) {
      ans++;
      k = i;
    }
  return ans;
}

int main() {
  int p1[3][2] = {{1, 2}, {2, 3}, {3, 4}}, p2[3][2] = {{1, 2}, {7, 8}, {4, 5}};
  printf("%d\n", findLongestChain(p1, 3, NULL)); // expect: 2
  printf("%d\n", findLongestChain(p2, 3, NULL)); // expect: 3
}
