// 2359. Find Closest Node to Given Two Nodes
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int closestMeetingNode(int *edges, int edgesSize, int node1, int node2) {
  int n = edgesSize, *path1 = malloc(n * sizeof(int)),
      *path2 = malloc(n * sizeof(int));
  memset(path1, -1, n * sizeof(int));
  memset(path2, -1, n * sizeof(int));
  int p = node1, step = 0;
  while (1) {
    path1[p] = step;
    step++;
    p = edges[p];
    if (p == -1)
      break;
    if (path1[p] != -1)
      break;
  }
  p = node2;
  step = 0;
  while (1) {
    path2[p] = step;
    step++;
    p = edges[p];
    if (p == -1)
      break;
    if (path2[p] != -1)
      break;
  }
  int min = INT_MAX, ans = -1;
  for (int i = 0; i < n; i++)
    if (path1[i] != -1 && path2[i] != -1)
      if (fmax(path1[i], path2[i]) < min) {
        min = fmax(path1[i], path2[i]);
        ans = i;
      }
  free(path1);
  free(path2);
  return ans;
}

int main() {
  int edges1[] = {2, 2, 3, -1}, edges2[] = {1, 2, -1};
  printf("%d\n", closestMeetingNode(edges1, 3, 0, 2)); // expect: 2
  printf("%d\n", closestMeetingNode(edges2, 3, 0, 2)); // expect: 2
}
