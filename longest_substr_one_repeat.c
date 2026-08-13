// 2213. Longest Substring of One Repeating Character
#include "leetcode.h"

/*
 * you are given a 0-indexed string 's'. you are also given a 0-indexed string
 * 'queryCharacters' of length 'k' and a 0-indexed array of integer indices
 * 'queryIndices' of length 'k', both of which are used to describe 'k' queries.
 * the i'th query updates the character in 's' at index 'queryIndices[i]' to the
 * character 'queryCharacters[i]'. return an array 'lengths' of length 'k' where
 * 'lengths[i]' is the length of the longest substring of 's' consisting of only
 * one repeating character after the i'th query is performed.
 */

struct node {
  char left_char;
  char right_char;
  int length;
  int prefix;
  int suffix;
  int best;
};

struct node merge_nodes(struct node left, struct node right) {
  struct node res;
  res.left_char = left.left_char;
  res.right_char = right.right_char;
  res.length = left.length + right.length;
  res.prefix = left.prefix;
  if (left.right_char == right.left_char && left.prefix == left.length)
    res.prefix = left.length + right.prefix;
  res.suffix = right.suffix;
  if (left.right_char == right.left_char && right.suffix == right.length)
    res.suffix = right.length + left.suffix;
  res.best = fmax(left.best, right.best);
  if (left.right_char == right.left_char)
    res.best = fmax(res.best, left.suffix + right.prefix);
  return res;
}

void build_node(struct node *tree, const char *s, int node, int start,
                int end) {
  if (start == end) {
    tree[node] = (struct node){s[start], s[start], 1, 1, 1, 1};
    return;
  }
  int mid = (start + end) / 2;
  build_node(tree, s, node * 2, start, mid);
  build_node(tree, s, node * 2 + 1, mid + 1, end);
  tree[node] = merge_nodes(tree[node * 2], tree[node * 2 + 1]);
}

void update_node(struct node *tree, int node, int start, int end, int idx,
                 char c) {
  if (start == end) {
    tree[node] = (struct node){c, c, 1, 1, 1, 1};
    return;
  }
  int mid = (start + end) / 2;
  if (idx <= mid)
    update_node(tree, node * 2, start, mid, idx, c);
  else
    update_node(tree, node * 2 + 1, mid + 1, end, idx, c);
  tree[node] = merge_nodes(tree[node * 2], tree[node * 2 + 1]);
}

int *longestRepeating(char *s, char *queryCharacters, int *queryIndices,
                      int queryIndicesSize, int *returnSize) {
  int n = strlen(s);
  struct node *tree = (struct node *)malloc(4 * n * sizeof(struct node));
  build_node(tree, s, 1, 0, n - 1);
  int *ans = (int *)malloc(queryIndicesSize * sizeof(int));
  *returnSize = queryIndicesSize;
  for (int i = 0; i < queryIndicesSize; i++) {
    update_node(tree, 1, 0, n - 1, queryIndices[i], queryCharacters[i]);
    ans[i] = tree[1].best;
  }
  free(tree);
  return ans;
}

int main() {
  char *s1 = "babacc", *qc1 = "bcb";
  int qi1[] = {1, 3, 3}, r1[] = {3, 3, 4};
  char *s2 = "abyzz", *qc2 = "aa";
  int qi2[] = {2, 1}, r2[] = {2, 3};
  int rs1, *lr1 = longestRepeating(s1, qc1, qi1, ARRAY_SIZE(qi1), &rs1);
  int rs2, *lr2 = longestRepeating(s2, qc2, qi2, ARRAY_SIZE(qi2), &rs2);
  for (int i = 0; i < rs1; i++) {
    printf("%d ", lr1[i]);
    assert(lr1[i] == r1[i]);
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    printf("%d ", lr2[i]);
    assert(lr2[i] == r2[i]);
  }
  printf("\n");
  free(lr1);
  free(lr2);
}
