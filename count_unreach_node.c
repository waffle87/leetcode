// 2316. Count Unreachable Pairs of Nodes in an Undirected Graph
#include <stdio.h>
#include <stdlib.h>

/*
 * given integer 'n', there is undirected graph with 'n' nodes, numbered 0 to 'n
 * - 1' given 2d integer array 'edges' where 'edges[i] = [ai bi]' denotes that
 * there exists an undirected edge connecting nodes ai and bi. return number of
 * pairs of different nodes that are unreachable from each other
 */

int union_find(int *u, int val) {
  if (u[val] == val)
    return val;
  else
    return union_find(u, u[val]);
}

void union_set(int *u, int *u_size, int a, int b) {
  a = union_find(u, a);
  b = union_find(u, b);
  if (a == b)
    return;
  if (u_size[a] > u_size[b]) {
    u[b] = u[a];
    u_size[a] += u_size[b];
  } else {
    u[a] = u[b];
    u_size[b] += u_size[a];
  }
}

long long countPairs(int n, int **edges, int edges_size, int *edges_col_size) {
  int *u = malloc(n * sizeof(int)), *u_size = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    u[i] = i;
    u_size[i] = 1;
  }
  for (int i = 0; i < edges_size; i++)
    union_set(u, u_size, edges[i][0], edges[i][1]);
  long long ans = 0;
  for (int i = 0; i < n; i++)
    ans += n - u_size[union_find(u, i)];
  return ans / 2;
}

int main() {
  int n1 = 3, e1[][3] = {{0, 1}, {0, 2}, {1, 2}}, es1 = 3, ecs1[] = {3};
  int n2 = 7, e2[][5] = {{0, 2}, {0, 5}, {2, 4}, {1, 6}, {5, 4}}, es2 = 5,
      ecs2[] = {5};
  printf("%lld\n", countPairs(n1, e1, es1, ecs1)); // expect: 0
  printf("%lld\n", countPairs(n2, e2, es2, ecs2)); // expect: 0
}
