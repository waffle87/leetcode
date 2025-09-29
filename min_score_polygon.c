// 1039. Minimum Score Triangulation of Polygon
#include "leetcode.h"

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

int minScoreTriangulation(int *values, int valuesSize) {
  int dp[50][50] = {0};
  for (int i = 2; i < valuesSize; i++)
    for (int j = 0; j + i < valuesSize; j++) {
      int k = j + i;
      dp[j][k] = INT_MAX;
      for (int l = j + 1; l < k; l++) {
        int score = dp[j][l] + dp[l][k] + values[j] * values[k] * values[l];
        if (score < dp[j][k])
          dp[j][k] = score;
      }
    }
  return dp[0][valuesSize - 1];
}

int main() {
  int v1[] = {1, 2, 3}, v2[] = {3, 7, 4, 5}, v3[] = {1, 3, 1, 4, 1, 5};
  printf("%d\n", minScoreTriangulation(v1, ARRAY_SIZE(v1))); // expect: 6
  printf("%d\n", minScoreTriangulation(v2, ARRAY_SIZE(v2))); // expect: 144
  printf("%d\n", minScoreTriangulation(v3, ARRAY_SIZE(v3))); // expect: 13
}
