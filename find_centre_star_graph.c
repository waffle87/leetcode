// 1791. Find Center of Star Graph
#include "leetcode.h"

/*
 * there is an undirected star graph consisting of 'n' nodes labeled from 1 to
 * 'n'. a star graph is a graph where there is one centre node and exactly 'n -
 * 1' edges that connect the centre node with every other node. you are given a
 * 2d integer array 'edges' where 'edges[i] = [ui, vi]' indicates that there is
 * an edge between the node 'ui' and 'vi'. return the centre of the star graph.
 */

int findCenter(int **edges, int edgesSize, int *edgesColSize) {
  int centre = 0, col = 0, candidate = edges[0][col], n = 0;
  for (int i = 0; i < edgesSize; i++) {
    for (int j = 0; j < edgesColSize[i]; j++)
      if (candidate == edges[i][j]) {
        centre = edges[i][j];
        n++;
      }
    if (i == edgesSize - 1 && n < edgesSize) {
      i = 0;
      candidate = edges[0][col + 1];
    }
  }
  return centre;
}

int main() {
  int e1[3][2] = {{1, 2}, {2, 3}, {4, 2}},
      e2[4][2] = {{1, 2}, {5, 1}, {1, 3}, {1, 4}};
  int ecs1 = 3, ecs2 = 4;
  printf("%d\n", findCenter((int **)e1, ARRAY_SIZE(e1), &ecs1)); // expect: 2
  printf("%d\n", findCenter((int **)e2, ARRAY_SIZE(e2), &ecs2)); // expect: 1
}
