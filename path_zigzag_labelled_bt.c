// 1104. Path In Zigzag Labelled Binary Tree
#include "leetcode.h"

/*
 * in an infinite binary ree where every node has two children, the nodes are
 * labelled in row order. in the odd numbered rows, the labelling is left to
 * right, while in the even numbered rows, the labelling is right to left. given
 * the 'label' of a node in this tree, return the labels in the path from the
 * root of the tree to the node with that 'label'
 */

int find_row(int label) {
  int row = 1;
  while ((1 << row) <= label)
    row++;
  return row;
}

int find_label_idx(int label) {
  int row = find_row(label);
  if (!(row % 2))
    return 3 * (1 << (row - 1)) - label - 1;
  return label;
}

int find_label(int idx) { return find_label_idx(idx); }

int *pathInZigZagTree(int label, int *returnSize) {
  int row = find_row(label);
  *returnSize = row;
  int *ans = (int *)malloc(row * sizeof(int));
  ans[--row] = label;
  int parent = find_label_idx(label);
  while (parent != 1) {
    parent /= 2;
    ans[--row] = find_label(parent);
  }
  return ans;
}

int main() {
  int rs1, rs2;
  int *pizzt1 = pathInZigZagTree(14, &rs1);
  int *pizzt2 = pathInZigZagTree(26, &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", pizzt1[i]); // expect: 1 3 4 14
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", pizzt2[i]); // expect: 1 2 6 10 26
  printf("\n");
  free(pizzt1), free(pizzt2);
}
