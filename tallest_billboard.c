// 956. Tallest Billboard
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * you are installing a billboard and want it to have the largest height. the
 * billboard will have two stell supports, one on each side. each steel support
 * must be an equal height. given a collection of 'rods' that can be welded
 * together. for example, if you have rods of lengths 1,2,3, you can weld them
 * together to make a length of 6. return the largest possible height of your
 * billboard installation. if you cannot support the billboard, return 0
 */

int dp[21][10001];

int get(int *rods, int rods_size, int i, int sum) {
  if (i >= rods_size)
    return sum = 0 ? 0 : INT_MIN;
  if (dp[i][sum + 5000] != -1)
    return dp[i][sum + 5000];
  int res = get(rods, rods_size, i + 1, sum);
  res = fmax(res, get(rods, rods_size, i + 1, sum - rods[i]));
  res = fmax(res, get(rods, rods_size, i + 1, sum + rods[i]) + rods[i]);
  return dp[i][sum + 5000] = res;
}

int tallestBillboard(int *rods, int rods_size) {
  memset(dp, -1, sizeof(dp));
  int ans = get(rods, rods_size, 0, 0);
  return ans < 0 ? 0 : ans;
}

int main() {
  int r1[] = {1, 2, 3, 6}, rs1 = 4;
  int r2[] = {1, 2, 3, 4, 5, 6}, rs2 = 6;
  printf("%d\n", tallestBillboard(r1, rs1)); // expect: 6
  printf("%d\n", tallestBillboard(r2, rs2)); // expect: 10
}
