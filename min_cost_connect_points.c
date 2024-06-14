// 1584. Min Cost to Connect All Points
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * given a array 'points' representing integer coordinates of some points on a
 * 2d-plane, where 'points[i] = [x[i], y[i]]'. the cost of connecting two points
 * '[x[i], y[i]]' and '[x[j], y[j]]' is the manhattan distance between them:
 * '|x[i], - x[j]| + |y[i] + y[j]|', where '|val|' denotes the absolute value of
 * 'val'. return the minimum cost to make all points connected. all points are
 * connected if there is exactly one simple path betwen any two points.
 */

int cmp(const void *p1, const void *p2) {
  int *arr1 = *(int **)p1, *arr2 = *(int **)p2;
  if (arr1[2] == arr2[2])
    return arr1[0] - arr2[0];
  return arr1[2] - arr2[2];
}

int UnionFind(int *UNION, int val) {
  if (UNION[val] == val)
    return val;
  return UnionFind(UNION, UNION[val]);
}

bool UnionSet(int *UNION, int *Usize, int a, int b) {
  int Find_a = UnionFind(UNION, a), Find_b = UnionFind(UNION, b);
  if (Find_a == Find_b)
    return false;
  if (Usize[Find_a] > Usize[Find_b]) {
    UNION[Find_b] = UNION[Find_a];
    Usize[Find_a] += Usize[Find_b];
  } else {
    UNION[Find_a] = UNION[Find_b];
    Usize[Find_b] += Usize[Find_a];
  }
  return true;
}

int minCostConnectPoints(int points[][2], int points_size,
                         int *points_col_size) {
  int n = points_size, total_e = n * (n - 1) / 2, idx = 0;
  int **table = malloc(total_e * sizeof(int *));
  for (int i = 0; i < total_e; i++)
    table[i] = malloc(3 * sizeof(int));
  for (int i = 0; i < points_size; i++)
    for (int j = i + 1; j < points_size; j++) {
      table[idx][0] = i;
      table[idx][1] = j;
      table[idx][2] =
          abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
      idx++;
    }
  qsort(table, idx, sizeof(int *), cmp);
  int *UNION = malloc(n * sizeof(int)), *Usize = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    UNION[i] = i;
    Usize[i] = 1;
  }
  int ans = 0, edge = 0;
  for (int i = 0; i < idx; i++)
    if (UnionSet(UNION, Usize, table[i][0], table[i][1])) {
      ans += table[i][2];
      edge++;
      if (edge == n - 1)
        break;
    }
  return ans;
}

int main() {
  int p1[5][2] = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}},
      p2[3][2] = {{3, 12}, {-2, 5}, {-4, 1}};
  printf("%d\n", minCostConnectPoints(p1, 5, NULL)); // expect: 20
  printf("%d\n", minCostConnectPoints(p2, 3, NULL)); // expect: 18
}
