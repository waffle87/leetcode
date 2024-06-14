// 1039. Minimum Score Triangulation of Polygon
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * given a convex n-sided polygon where each vertex has an integer value. you
 * are given an integer array 'values' where 'values[i]' is the value of the
 * i'th vertex (ie. clockwise order). you will triangulate the polygon into 'n -
 * 2' triangles. for each triangle, the value of that triangle is the product of
 * the values of its vertices and the total score of the triangulation is the
 * sum of these values over all 'n - 2' triangles in the triangulation. return
 * the smallest possible total score that you can achieve with some
 * triangulation of the polygon
 */

int minScoreTriangulation(int *values, int values_size) {
  int n = values_size, **dp = malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    dp[i] = malloc(n * sizeof(int));
    dp[i][i] = 0;
    if (i + 1 < n)
      dp[i][i + 1] = 0;
    for (int j = i + 2; j < n; j++)
      dp[i][j] = INT_MAX / 3;
  }
  for (int len = 3; len <= n; len++) {
    for (int i = 0; i < n; i++) {
      int j = i + len - 1;
      if (j >= n)
        break;
      for (int k = i + 1; k < j; k++)
        dp[i][j] = fmin(dp[i][j], dp[i][k] + values[i] * values[k] * values[j] +
                                      dp[k][j]);
    }
  }
  int ans = dp[0][n - 1];
  for (int i = 0; i < n; i++)
    free(dp[i]);
  free(dp);
  return ans;
}

int main() {
  int v1[] = {1, 2, 3}, v2[] = {3, 7, 4, 5}, v3[] = {1, 3, 1, 4, 1, 5};
  printf("%d\n", minScoreTriangulation(v1, 3)); // expect: 6
  printf("%d\n", minScoreTriangulation(v2, 4)); // expect: 144
  printf("%d\n", minScoreTriangulation(v3, 6)); // expect: 13
}
