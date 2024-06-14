// 834. Sum of Distances in Tree
#include "leetcode.h"

/*
 * there is an undirected connected tree with 'n' nodes labeled from 0 to 'n -
 * 1' and 'n - 1' edges. you are given the integer 'n' and the array 'edges'
 * where 'edges[i] = [ai, bi]' indicates that there is an edge between nodes
 * 'ai' and 'bi' in the tree. return an array 'ans' of length 'n' where 'ans[i]'
 * is thesum of the distances between the i'th node in the tree and all other
 * nodes.
 */

void helper(int *res, int *cnt, int *parent, int i, int n) {
  if (res[parent[i]] == -1)
    helper(res, cnt, parent, parent[i], n);
  res[i] = res[parent[i]] + n - 2 * cnt[i];
}

void change_root(int *parent, int root) {
  if (parent[root] == -1)
    return;
  parent[parent[root]] = root;
  parent[root] = -1;
}

int *sumOfDistancesInTree(int n, int **edges, int edgesSize, int *edgesColSize,
                          int *returnSize) {
  int *ans = (int *)malloc(sizeof(int) * (*returnSize = n));
  int parent[n], cnt[n];
  memset(parent, 255, sizeof(parent));
  memset(ans, 255, sizeof(cnt));
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < edgesSize; i++) {
    if (parent[edges[i][1]] == -1)
      parent[edges[i][1]] = edges[i][0];
    else if (parent[edges[i][0]] == -1)
      parent[edges[i][0]] = edges[i][1];
    else {
      change_root(parent, edges[i][0]);
      parent[edges[i][0]] = edges[i][1];
    }
  }
  int sum = 0, root;
  for (int i = 0; i < n; i++) {
    if (parent[i] == -1)
      root = i;
    else {
      int j = i;
      while (parent[j] != -1) {
        cnt[j]++;
        sum++;
        j = parent[j];
      }
    }
  }
  cnt[root] = n;
  ans[root] = sum;
  for (int i = 0; i < n; i++) {
    if (ans[i] != -1)
      continue;
    helper(ans, cnt, parent, i, n);
  }
  return ans;
}
