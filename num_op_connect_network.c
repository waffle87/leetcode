// 1319. Number of Operations to Make Network Connected
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int union_find(int *u, int val) {
  if (u[val] == val)
    return val;
  return union_find(u, u[val]);
}

bool union_set(int *u, int *usize, int a, int b) {
  int find_a = union_find(u, a);
  int find_b = union_find(u, b);
  if (find_a == find_b)
    return false;
  if (usize[find_a] > usize[find_b]) {
    u[find_b] = u[find_a];
    usize[find_a] += usize[find_b];
  } else {
    u[find_a] = u[find_b];
    usize[find_b] += usize[find_a];
  }
  return true;
}

int makeConnected(int n, int **connections, int connections_size,
                  int *connections_col_size) {
  if (connections_size < n - 1)
    return -1;
  int *u = malloc(n * sizeof(int));
  int *usize = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    u[i] = i;
    usize[i] = 1;
  }
  int ans = 0;
  for (int i = 0; i < connections_size; i++)
    if (union_set(u, usize, connections[i][0], connections[i][1]) == false)
      ans++;
  if (connections_size - ans >= n - 1)
    return 0;
  else
    return (n - 1) - (connections_size - ans);
}

int main() {
  int c1[3][2] = {{0, 1}, {0, 2}, {1, 2}};
  int c2[5][2] = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}};
  int c3[5][2] = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}};
  int c1_c_s[] = {3}, c2_c_s[] = {5}, c3_c_s[] = {5};
  printf("%d\n", makeConnected(4, c1, 3, c1_c_s));
  printf("%d\n", makeConnected(6, c2, 5, c1_c_s));
  printf("%d\n", makeConnected(6, c3, 5, c1_c_s));
}
