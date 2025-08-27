// 3203. Find Minimum Diameter After Merging Two Trees
#include "leetcode.h"

/*
 * there exists two undirected trees with 'n' and 'm' nodes numbered from 0 to
 * 'n - 1' and from 0 to 'm - 1', respectively. you are given two 2d integer
 * arrays 'edges1', and 'edges2' of lengths 'n - 1' and 'm - 1', respectively,
 * where 'edges1[i] = [a_i, b_i]' indicates that thereis an edge between nodes
 * 'a_i' and 'b_i' in the first tree, and 'edges2[i] = [u_i, v_i]' indicates
 * there is an edge between nodes 'u_i' and 'v_i' in the second tree. you must
 * connect one node from the first tree with another node from the second tree
 * with an edge. return the minimum possible diameter of the resulting tree. the
 * diameter of a tree is the length of the longest path between any two nodes in
 * the tree
 */

enum state { VAL, NEXT };

int max_diameter(int **edges, int edgesSize) {
  int i, n = edgesSize + 1, queue[n + 1], head = 0, tail = 0;
  int hash[n], nodes[(edgesSize << 1) + 1][2], node, ptr = 0;
  int cnt, prev, curr, next, diam = 0;
  bool *vis = (bool *)calloc(n, sizeof(bool));
  memset(hash, -1, sizeof(hash));
  for (int i = 0; i < edgesSize; i++) {
    node = ptr++;
    nodes[node][VAL] = edges[i][0];
    nodes[node][NEXT] = hash[edges[i][1]];
    hash[edges[i][1]] = node;
    node = ptr++;
    nodes[node][VAL] = edges[i][1];
    nodes[node][NEXT] = hash[edges[i][0]];
    hash[edges[i][0]] = node;
  }
  vis[0] = true;
  queue[tail++] = 0;
  while (head < tail) {
    cnt = tail - head;
    while (cnt--) {
      curr = queue[head++];
      node = hash[curr];
      while (node >= 0) {
        next = nodes[node][VAL];
        node = nodes[node][NEXT];
        if (vis[next])
          continue;
        vis[next] = true;
        queue[tail++] = next;
      }
    }
  }
  memset(vis, false, n);
  head = 0;
  tail = 1;
  queue[0] = curr;
  while (head < tail) {
    cnt = tail - head;
    while (cnt--) {
      curr = queue[head++];
      node = hash[curr];
      while (node >= 0) {
        next = nodes[node][VAL];
        node = nodes[node][NEXT];
        if (vis[next])
          continue;
        vis[next] = true;
        queue[tail++] = next;
      }
    }
    if (head < tail)
      ++diam;
  }
  return diam;
}

int minimumDiameterAfterMerge(int **edges1, int edges1Size, int *edges1ColSize,
                              int **edges2, int edges2Size,
                              int *edges2ColSize) {
  int d1 = max_diameter(edges1, edges1Size);
  int d2 = max_diameter(edges2, edges2Size);
  int d3 = (d1 >> 1) + (d1 & 1);
  d3 += (d2 >> 1) + (d2 & 1) + 1;
  if (d1 < d2)
    d1 = d2;
  if (d1 < d3)
    d1 = d3;
  return d1;
}

int main() {
  int e1i1[3][2] = {{0, 1}, {0, 2}, {0, 3}}, e2i1[1][2] = {{0, 1}};
  int e1i2[7][2] = {{0, 1}, {0, 2}, {0, 3}, {2, 4}, {2, 5}, {3, 6}, {2, 7}},
      e2i2[7][2] = {{0, 1}, {0, 2}, {0, 3}, {2, 4}, {2, 5}, {3, 6}, {2, 7}};
  struct two_d_arr *e11 = two_d_arr_init(3, 2, e1i1);
  struct two_d_arr *e21 = two_d_arr_init(1, 2, e2i1);
  struct two_d_arr *e12 = two_d_arr_init(7, 2, e1i2);
  struct two_d_arr *e22 = two_d_arr_init(7, 2, e2i2);
  printf("%d\n", minimumDiameterAfterMerge(
                     e11->arr, e11->row_size, e11->col_size, e21->arr,
                     e21->row_size, e21->col_size)); // expect: 3
  printf("%d\n", minimumDiameterAfterMerge(
                     e12->arr, e12->row_size, e12->col_size, e22->arr,
                     e22->row_size, e22->col_size)); // expect: 5
  two_d_arr_free(e11);
  two_d_arr_free(e21);
  two_d_arr_free(e12);
  two_d_arr_free(e22);
}
