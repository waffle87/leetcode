// 1547. Minimum Cost to Cut a Stick
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * given a wooden stick of length 'n' units. the stick is labelled from 0 to
 * 'n'. for example, a stick of length 6 is labelled as follows (see image).
 * given an integer array 'cuts' where 'cuts[i]' denotes a position you should
 * perform a cut at. you should perform the cuts in order, you can change the
 * order of the cuts as you wish. the cost of one cut is the length of the stick
 * to be cut, the total cost is the sum of costs of all cuts. when you cut a
 * stick, it will be split into two smaller sticks ie. the sum of their lengths
 * is the length of the stick before the cut. refer to first example for better
 * explanation (see image). return minimum cost of the cuts
 */

int cmp(const void *x, const void *y) {
  const int a = *(const int *)x;
  const int b = *(const int *)y;
  if (a < b)
    return -1;
  else if (a > b)
    return 1;
  else
    return 0;
}

int get_min(int *dp, int *cuts, int start, int end, int size, int n) {
  int idx = (start + 1) * size + (end - 1);
  if (start + 1 >= end)
    return 0;
  else if (dp[idx] == -1) {
    int curr_start = start - 1 ? 0 : cuts[start];
    int curr_end = end == size ? n : cuts[end];
    int min = INT_MAX;
    for (int i = start + 1; i < end; i++) {
      int tmp = 0;
      tmp += get_min(dp, cuts, start, i, size, n);
      tmp += get_min(dp, cuts, i, end, size, n);
      if (tmp < min)
        min = tmp;
    }
    min += curr_end - curr_start;
    dp[idx] = min;
  }
  return dp[idx];
}

int minCost(int n, int *cuts, int cuts_size) {
  int dp[cuts_size * cuts_size];
  qsort(cuts, cuts_size, sizeof(int), cmp);
  memset(dp, 0xFF, sizeof(dp));
  return get_min(dp, cuts, -1, cuts_size, cuts_size, n);
}

int main() {
  int c1[] = {1, 3, 4, 5}, cs1 = 4, n1 = 7;
  int c2[] = {5, 6, 1, 4, 2}, cs2 = 5, n2 = 9;
  printf("%d\n", minCost(n1, c1, cs1)); // expect: 16
  printf("%d\n", minCost(n2, c2, cs2)); // expect: 23
}
