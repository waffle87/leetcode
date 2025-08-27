// 684. Redundant Connection
#include "leetcode.h"

/*
 * in this problem, a tree is an undirected graph that is connected and has no
 * cycles. you are given a graph that started as a tree with 'n' nodes labeled
 * from 1 to 'n', with one additional edge added. the added edge has two
 * different vertices chosen from 1 to 'n', and was not an edge that already
 * existed. the graph is represented as an array 'edges' of length 'n' where
 * 'edges[i] = [a_i, b_i]' indicates that there is an edge between nodes 'a_i'
 * and 'b_i' in the graph. return an edge that can removed so that the resulting
 * graph is a tree of 'n' nodes. if there are multiple answers, return the
 * answer that occurs last in the input.
 */

int find(int *parent, int x) {
  if (parent[x] != x)
    parent[x] = find(parent, parent[x]);
  return parent[x];
}

void union_set(int *parent, int *rank, int x, int y) {
  int root_x = find(parent, x), root_y = find(parent, y);
  if (root_x != root_y) {
    if (rank[root_x] > rank[root_y])
      parent[root_y] = root_x;
    else if (rank[root_x] < rank[root_y])
      parent[root_x] = root_y;
    else {
      parent[root_y] = root_x;
      rank[root_x]++;
    }
  }
}

int *findRedundantConnection(int **edges, int edgesSize, int *edgesColSize,
                             int *returnSize) {
  int *parent = (int *)malloc((edgesSize + 1) * sizeof(int));
  int *rank = (int *)calloc(edgesSize + 1, sizeof(int));
  int *result = (int *)malloc(2 * sizeof(int));
  *returnSize = 2;
  for (int i = 1; i <= edgesSize; i++)
    parent[i] = i;
  for (int i = 0; i < edgesSize; i++) {
    int u = edges[i][0], v = edges[i][1];
    if (find(parent, u) == find(parent, v)) {
      result[0] = u;
      result[1] = v;
    } else
      union_set(parent, rank, u, v);
  }
  free(parent), free(rank);
  return result;
}

int main() {
  int e1i[3][2] = {{1, 2}, {1, 3}, {2, 3}}, rs1;
  int e2i[5][2] = {{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}}, rs2;
  struct two_d_arr *e1 =
      two_d_arr_init(ARRAY_SIZE(e1i), ARRAY_SIZE(e1i[0]), e1i);
  struct two_d_arr *e2 =
      two_d_arr_init(ARRAY_SIZE(e2i), ARRAY_SIZE(e2i[0]), e2i);
  int *frc1 =
      findRedundantConnection(e1->arr, e1->row_size, e1->col_size, &rs1);
  int *frc2 =
      findRedundantConnection(e2->arr, e2->row_size, e2->col_size, &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", frc1[i]); // expect: 2 3
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", frc2[i]); // expect: 1 4
  printf("\n");
  free(frc1), two_d_arr_free(e1);
  free(frc2), two_d_arr_free(e2);
}
