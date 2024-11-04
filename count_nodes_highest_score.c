// 2049. Count Nodes With the Highest Score
#include "leetcode.h"

/*
 * there is a binary tree rooted at 0 consisting of 'n' nodes. the nodes are
 * labeled from 0 to 'n - 1'. you are given a 0-indexed integer array 'parents'
 * representing the tree, where 'parents[i]' is the parent node 'i'. since node
 * 0 is the root 'parents[0] == -1'. each node has a score. to find the score of
 * a node, consider if the node and the edges connected to it were removed. the
 * tree would become one or more non empty subtrees. the size of a subtree is
 * the number of the nodes in it. the score of the nodes is the product of the
 * sizes of all those subtrees. return the number of nodes that have highest
 * score.
 */

int dfs(int **children, int *children_cnt, int parent_size, int parent,
        unsigned long long *max, int *highest_score) {
  if (!children || !max || !highest_score)
    return 0;
  int *child = children[parent];
  unsigned long long score = 0;
  int grandchild_cnt[2] = {0, 0};
  for (int i = 0; i < children_cnt[parent]; i++) {
    grandchild_cnt[i] =
        dfs(children, children_cnt, parent_size, child[i], max, highest_score);
    if (!score)
      score = grandchild_cnt[i];
    else if (grandchild_cnt[i])
      score *= grandchild_cnt[i];
  }

  int subtree_nodes_num = grandchild_cnt[0] + grandchild_cnt[1] + 1;
  int remaining_nodes_num = parent_size - subtree_nodes_num;
  if (!score)
    score = remaining_nodes_num;
  else if (remaining_nodes_num)
    score *= remaining_nodes_num;
  if (score > *max) {
    *max = score;
    *highest_score = 1;
  } else if (score == *max)
    (*highest_score)++;
  return subtree_nodes_num;
}

int countHighestScoreNodes(int *parents, int parentsSize) {
  if (!parents)
    return 0;
  unsigned long long max = 0;
  int highest_score = 0;
  int **children = (int **)calloc(parentsSize, sizeof(int *));
  int children_cnt[parentsSize];
  for (int i = 0; i < parentsSize; i++) {
    children[i] = (int *)calloc(2, sizeof(int));
    children_cnt[i] = 0;
  }
  for (int i = 1; i < parentsSize; i++) {
    if (children_cnt[parents[i]] >= 2)
      continue;
    children[parents[i]][children_cnt[parents[i]]++] = i;
  }
  dfs(children, children_cnt, parentsSize, 0, &max, &highest_score);
  for (int i = 0; i < parentsSize; i++)
    free(children[i]);
  free(children);
  return highest_score;
}

int main() {
  int p1[] = {-1, 2, 0, 2, 0}, p2[] = {-1, 2, 0};
  printf("%d\n", countHighestScoreNodes(p1, ARRAY_SIZE(p1))); // expect: 3
  printf("%d\n", countHighestScoreNodes(p2, ARRAY_SIZE(p2))); // expect: 2
}
