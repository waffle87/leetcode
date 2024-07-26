// 1334. Find the City With the Smallest Number of Neighbors at a Threshold
// Distance
#include "leetcode.h"

/*
 * there are 'n' cities numbered from 0 to 'n - 1'. given the array 'edges'
 * where 'edges[i] = [from_i, to_i, weight_i]' represents a bidirectional and
 * weighted edge between cities 'from_i' and 'to_i' and given the integer
 * 'distanceThreshold'. return the city with the smallest number of cities that
 * are reachable through some path and whose distance is at most
 * 'distanceThreshold', if there are multiple cities, return the city with the
 * greatest number. notice that the distance of a path connecting cities i and j
 * is equal to the sum of of the edges' weights along that path
 */

int findTheCity(int n, int **edges, int edgesSize, int *edgesColSize,
                int distanceThreshold) {
  int ans = 0, min_reach = INT_MAX, dist[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      dist[i][j] = 1e6;
    dist[i][i] = 0;
  }
  for (int i = 0; i < edgesSize; i++) {
    dist[edges[i][0]][edges[i][1]] = edges[i][2];
    dist[edges[i][1]][edges[i][0]] = edges[i][2];
  }
  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        dist[i][j] = fmin(dist[i][j], dist[i][k] + dist[k][j]);
  for (int i = 0; i < n; i++) {
    int reachable = 0;
    for (int j = 0; j < n; j++) {
      if (dist[i][j] > distanceThreshold)
        continue;
      reachable++;
    }
    if (reachable > min_reach)
      continue;
    min_reach = reachable;
    ans = i;
  }
  return ans;
}

int main() {
  int e1[4][3] = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}},
      e2[6][3] = {{0, 1, 2}, {0, 4, 8}, {1, 2, 3},
                  {1, 4, 2}, {2, 3, 1}, {3, 4, 1}};
  int ecs1 = 4, ecs2 = 6;
  printf("%d\n",
         findTheCity(4, (int **)e1, ARRAY_SIZE(e1), &ecs1, 4)); // expect: 3
  printf("%d\n",
         findTheCity(5, (int **)e1, ARRAY_SIZE(e1), &ecs2, 2)); // expect: 0
}
