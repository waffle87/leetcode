// 1483. Kth Ancestor of a Tree Node
#include "leetcode.h"

/*
 * you are given a tree with 'n' nodes numbered from 0 to 'n - 1' in the form of
 * a parent array 'parent' where 'parent[i]' is the parent of the i'th node. the
 * root of the tree is node 0. find the k'th ancestor of a given node. the k'th
 * ancestor of a tree node is the k'th node in the path from that node to the
 * root node. implement the 'TreeAncestor' class.
 */

typedef struct {
  int **parents;
} TreeAncestor;

void build(TreeAncestor *obj, bool *built, int node) {
  if (node == -1)
    return;
  if (built[node])
    return;
  for (int i = 1; i <= 20; ++i) {
    int parent = obj->parents[node][i - 1];
    if (parent == -1)
      break;
    if (!built[parent])
      build(obj, built, parent);
    obj->parents[node][i] = obj->parents[parent][i - 1];
  }
  built[node] = true;
}

TreeAncestor *treeAncestorCreate(int n, int *parent, int parentSize) {
  TreeAncestor *obj = (TreeAncestor *)malloc(sizeof(TreeAncestor));
  obj->parents = (int **)malloc(parentSize * sizeof(int *));
  bool *built = (bool *)calloc(parentSize, sizeof(bool));
  for (int i = 0; i < parentSize; ++i) {
    obj->parents[i] = (int *)malloc(20 * sizeof(int));
    memset(obj->parents[i], -1, 20 * sizeof(int));
    obj->parents[i][0] = parent[i];
  }
  for (int i = 0; i < parentSize; ++i)
    build(obj, built, i);
  free(built);
  return obj;
}

int treeAncestorGetKthAncestor(TreeAncestor *obj, int node, int k) {
  if (!k)
    return node;
  if (node == -1)
    return -1;
  int tier = 0;
  for (int i = 20; i >= 1; --i)
    if ((1 << i) <= k) {
      tier = i;
      break;
    }
  return treeAncestorGetKthAncestor(obj, obj->parents[node][tier],
                                    k - (1 << tier));
}

void treeAncestorFree(TreeAncestor *obj) { free(obj); }

int main() {
  int parent[] = {-1, 0, 0, 1, 1, 2, 2};
  TreeAncestor *obj = treeAncestorCreate(7, parent, ARRAY_SIZE(parent));
  printf("%d\n", treeAncestorGetKthAncestor(obj, 3, 1)); // expect: 1
  printf("%d\n", treeAncestorGetKthAncestor(obj, 5, 2)); // expect: 0
  printf("%d\n", treeAncestorGetKthAncestor(obj, 6, 3)); // expect: -1
  treeAncestorFree(obj);
}
