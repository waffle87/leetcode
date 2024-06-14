// 1697. Checking Existence of Edge Length Limited Paths
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * an undirected graph of 'n' nodes is defined by 'edge_list',
 * where 'edge_list[i] = [ui, vi, disi]' denotes an edge between
 * nodes 'ui' and 'vi' with distance 'disi'. note that there may
 * be multiple edges between two nodes. given an array 'queries',
 * where 'queries[j] = [pj, qj, limitj]', your task is to determine
 * for each 'queries[j]' whthere there is a path between 'pj' and
 * 'qj' such that each edge on the path has a distance strictly less
 * than 'limitj'. return boolean array where 'ans.length == queries.len'
 * and the j'th value of 'ans' is true if there is a path for
 * 'queries[j]' is true, and false otherwise
 */

int *root, **qcopy;

int find(int x) {
  if (x == root[x])
    return x;
  else
    return root[x] = find(root[x]);
}

int cmp(void const *a, void const *b) {
  return (*(int **)a)[2] - (*(int **)b)[2];
}

int cmp2(void const *a, void const *b) {
  return qcopy[*(int *)a][2] - qcopy[*(int *)b][2];
}

bool *distanceLimitedPathsExist(int n, int **edge_list, int edge_list_size,
                                int *edge_list_col_size, int **queries,
                                int queries_size, int *queries_col_size,
                                int *return_size) {
  *return_size = queries_size;
  int i = 0;
  root = (int *)malloc(sizeof(int) * n);
  for (i = 0; i < n; i++)
    root[i] = i;
  bool *ans = (bool *)malloc(sizeof(bool) * queries_size);
  int idx[queries_size];
  for (i = 0; i < queries_size; ++i)
    idx[i] = i;
  qcopy = queries;
  qsort(idx, queries_size, sizeof(int), cmp2);
  qsort(edge_list, edge_list_size, sizeof(int *), cmp);
  int j = 0;
  for (i = 0; i < queries_size; ++i) {
    int curr = idx[i], len = queries[curr][2];
    while (j < edge_list_size && edge_list[j][2] < len) {
      int a = find(edge_list[j][0]), b = find(edge_list[j][1]);
      root[b] = a;
      j++;
    }
    if (find(queries[curr][0]) == find(queries[curr][1]))
      ans[curr] = 1;
    else
      ans[curr] = 0;
  }
  return ans;
}
