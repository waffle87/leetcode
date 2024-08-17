// 1937. Maximum Number of Points with Cost
#include "leetcode.h"

/*
 * you are given an 'm * n' integer matrix 'points' (0 indexed). starting with 0
 * points you want to maximise the numbber of points you can get from the
 * matrix. to gain points, you must pick one cell in each row. picking the cell
 * at coordinates '(r, c)' will add 'points[r][c]' to your score. however, you
 * will lose points if you pick a cell too far from the cell that you picked in
 * the previous row. for every two adjacent rows 'r' and 'r + 1', picking cells
 * at coordinates '(r, c_1)' and '(r + 1, c_2)' will subtract 'abs(c_1 - c_2)'
 * from your score. return the maximum number of points you can achieve
 */

long long maxPoints(int **points, int pointsSize, int *pointsColSize) {
  long long *pre = (long long *)malloc(*pointsColSize * sizeof(int));
  long long *left = (long long *)calloc(*pointsColSize, sizeof(long long));
  long long *right = (long long *)calloc(*pointsColSize, sizeof(long long));
  long long *curr = (long long *)calloc(*pointsColSize, sizeof(long long));
  for (int i = 0; i < *pointsColSize; i++)
    pre[i] = points[0][i];
  for (int i = 0; i < pointsSize - 1; ++i) {
    left[0] = pre[0];
    right[*pointsColSize - 1] = pre[*pointsColSize - 1];
    for (int j = 1; j < *pointsColSize; ++j)
      left[j] = fmax(left[j - 1] - 1, pre[j]);
    for (int j = *pointsColSize - 2; j >= 0; --j)
      right[j] = fmax(right[j + 1] - 1, pre[j]);
    for (int j = 0; j < *pointsColSize; ++j)
      curr[j] = points[i + 1][j] + fmax(left[j], right[j]);
    pre = curr;
  }
  long long ans = 0;
  for (int i = 0; i < *pointsColSize; i++)
    ans = fmax(ans, pre[i]);
  free(pre), free(left), free(right), free(curr);
  return ans;
}

int main() {
  int p1[3][3] = {{1, 2, 3}, {1, 5, 1}, {3, 1, 1}},
      p2[3][2] = {{1, 5}, {2, 3}, {4, 2}}, pcs1[] = {3, 3, 3},
      pcs2[] = {2, 2, 2};
  printf("%lld\n", maxPoints((int **)p1, ARRAY_SIZE(p1), pcs1)); // expect: 9
  printf("%lld\n", maxPoints((int **)p2, ARRAY_SIZE(p2), pcs2)); // expect: 11
}
