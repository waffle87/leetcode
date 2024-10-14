// 2246. Longest Path With Different Adjacent Characters
#include "leetcode.h"

/*
 * you are given a tree (ie. a connected undirected graph that has no cycles)
 * rooted at node '0' consisting of 'n' nodes numbered from '0' to 'n - 1'. the
 * tree is represented by a 0-indexed array 'parent' of size 'n' where
 * 'parent[i]' is the parent of node 'i'. since node 0 is the root, 'parent[0] =
 * -1'. you are also given a string 's' of length 'n', where 's[i]' is the
 * character assigned to node 'i'. return the legnth of the longest path in the
 * tree such that no pair of adjacnet nodes on the path have the same character
 * assigned to them.
 */

struct node {
  bool visited;
  int children;
  int *adjacent_list;
};

void dfs(int curr_node, int *dist, struct node **root, int parent_size, char *s,
         int *res) {
  int curr_child;
  dist[curr_node] = 1;
  root[curr_node]->visited = true;
  for (int i = 0; i < root[curr_node]->children; i++) {
    curr_child = root[curr_node]->adjacent_list[i];
    if (!root[curr_child]->visited) {
      dfs(curr_child, dist, root, parent_size, s, res);
      if (s[curr_node] != s[curr_child]) {
        *res = fmax(*res, dist[curr_node] + dist[curr_child]);
        dist[curr_node] = fmax(dist[curr_node], dist[curr_child] + 1);
      }
    }
  }
}

int longestPath(int *parent, int parentSize, char *s) {
  int ans = 1;
  int *cnt = (int *)calloc(parentSize, sizeof(int));
  int *dist = (int *)calloc(parentSize, sizeof(int));
  struct node **root =
      (struct node **)malloc(parentSize * sizeof(struct node *));
  struct node *curr_node;
  for (int i = 1; i < parentSize; i++) {
    cnt[parent[i]]++;
    cnt[i]++;
  }
  for (int i = 0; i < parentSize; i++) {
    root[i] = (struct node *)malloc(sizeof(struct node));
    root[i]->visited = false;
    root[i]->children = 0;
    root[i]->adjacent_list = (int *)malloc(cnt[i] * sizeof(int));
  }
  for (int i = 1; i < parentSize; i++) {
    curr_node = root[parent[i]];
    curr_node->adjacent_list[curr_node->children] = i;
    curr_node->children++;
  }
  dfs(0, dist, root, parentSize, s, &ans);
  for (int i = 0; i < parentSize; i++) {
    free(root[i]->adjacent_list);
    free(root[i]);
  }
  free(cnt), free(dist), free(root);
  return ans;
}

int main() {
  int p1[] = {-1, 0, 0, 1, 1, 2}, p2[] = {-1, 0, 0, 0};
  char *s1 = "abacbe", *s2 = "aabc";
  printf("%d\n", longestPath(p1, ARRAY_SIZE(p1), s1)); // expect: 3
  printf("%d\n", longestPath(p2, ARRAY_SIZE(p2), s2)); // expect: 3
}
