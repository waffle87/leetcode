// 3249. Count the Number of Good Nodes
#include "leetcode.h"

/*
 * there is an undirected tree with 'n' nodes labeled from 0 to 'n - 1', and
 * rooted at node 0. you are given a 2d integer array 'edges' of length 'n - 1'
 * where 'edges[i] = [a_i, b_i]' indicates that there is an edge between nodes
 * 'a_i' and 'b_i' in the tree. a node is good if all the subtrees rooted at is
 * children have the same size. return the number of good nodes in the given
 * tree. a subtree of 'treeName' is a tree consisting of a node in 'treeName'
 * and all of its descendants.
 */

struct map {
  int *next;
  int cnt;
};

int dfs(struct map *m, int fa, int curr, int *res) {
  int n = m[curr].cnt;
  if (n == 1 && curr) {
    (*res)++;
    return 1;
  }
  int prev = -1, sum = 0;
  bool flag = true;
  for (int i = 0; i < n; i++) {
    int next = m[curr].next[i];
    if (next != fa) {
      int x = dfs(m, curr, next, res);
      if (prev == -1)
        prev = x;
      else if (x != prev)
        flag = false;
      sum += x;
    }
  }
  *res += flag;
  return sum + 1;
}

int countGoodNodes(int **edges, int edgesSize, int *edgesColSize) {
  int n = edgesSize + 1;
  int *cnt_child = (int *)calloc(n, sizeof(int));
  for (int i = 0; i < edgesSize; i++) {
    int n1 = edges[i][0], n2 = edges[i][1];
    cnt_child[n1]++;
    cnt_child[n2]++;
  }
  struct map *m = (struct map *)calloc(n, sizeof(struct map));
  for (int i = 0; i < n; i++)
    m[i].next = (int *)calloc(cnt_child[i], sizeof(int));
  for (int i = 0; i < edgesSize; i++) {
    int n1 = edges[i][0], n2 = edges[i][1];
    m[n1].next[m[n1].cnt++] = n2;
    m[n2].next[m[n2].cnt++] = n1;
  }
  int ans = 0;
  dfs(m, -1, 0, &ans);
  return ans;
}

int main() {
  int e1i[6][2] = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}};
  int e2i[8][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 4},
                   {0, 5}, {1, 6}, {2, 7}, {3, 8}};
  struct two_d_arr e1, e2;
  two_d_arr_init(&e1, 6, 2, e1i);
  two_d_arr_init(&e2, 8, 2, e2i);
  printf("%d\n", countGoodNodes(e1.arr, e1.row_size, e1.col_size)); // expect: 7
  printf("%d\n", countGoodNodes(e2.arr, e2.row_size, e2.col_size)); // expect: 6
  two_d_arr_free(&e1);
  two_d_arr_free(&e2);
}
