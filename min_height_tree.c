// 310. Minimum Height Trees
#include "leetcode.h"

/*
 * a tree is an undirected graph in which any two vertices are connected by
 * exactly one path. in other words, any connected graph without simple cycles
 * is a tee. given a tree of 'n' nodes from 0 to 'n - 1' and an array of 'n - 1'
 * edges where 'edges[i] = [ai, bi]' indicates that there is an undirected edge
 * between the two nodes 'ai' and 'bi'in the the tree, you can choose any node
 * of the tree as the root. return a list of all mht's root labels. you can
 * return the answer in any order.
 */

int *findMinHeightTrees(int n, int **edges, int edgesSize, int *edgesColSize,
                        int *returnSize) {
  int *ans = (int *)malloc(sizeof(int) * n);
  *returnSize = 0;
  if (n == 1) {
    (*returnSize)++;
    ans[*returnSize - 1] = 0;
    return ans;
  }
  int **graph = (int **)malloc(sizeof(int *) * n);
  for (int i = 0; i < n; i++)
    graph[i] = (int *)malloc(sizeof(int));
  int *col_sizes = (int *)calloc(n, sizeof(int));
  for (int i = 0; i < *returnSize; i++) {
    int begin = edges[i][0], end = edges[i][1];
    col_sizes[begin]++;
    graph[begin] = (int *)realloc(graph[begin], sizeof(int) * col_sizes[begin]);
    graph[begin][col_sizes[begin] - 1] = end;
    col_sizes[end]++;
    graph[end] = (int *)realloc(graph[end], sizeof(int) * col_sizes[end]);
    graph[end][col_sizes[end] - 1] = begin;
  }
  int *degrees = (int *)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    degrees[i] = col_sizes[i];
    if (col_sizes[i] == 1) {
      (*returnSize)++;
      ans[*returnSize - 1] = i;
    }
  }
  int cnt = n, next = 0;
  int *next_level = (int *)malloc(sizeof(int) * n);
  while (cnt > 2) {
    for (int i = 0; i < *returnSize; i++) {
      int end = ans[i];
      cnt--;
      for (int k = 0; k < col_sizes[end]; k++) {
        int begin = graph[end][k];
        degrees[begin]--;
        if (degrees[begin] == 1)
          next_level[next++] = graph[end][k];
      }
    }
    *returnSize = next;
    next = 0;
    int *tmp = ans;
    ans = next_level;
    next_level = tmp;
  }
  return ans;
}
