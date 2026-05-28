// 3093. Longest Common Suffix Queries
#include "leetcode.h"

/*
 * you are given two arrays of strings 'wordsContainer' and 'wordsQuery'. for
 * each 'wordsQuery[i]', you need to find a string from 'wordsContainer' that
 * has the longest common suffix with 'wordsQuery[i]'. if there are two or more
 * string in 'wordsContainer' that share the longest common suffix, find the
 * string that is the smallest in length. if there are two or more such strigs
 * that have the same smallest length, find the one that occured earlier in
 * 'wordsContainer'. return an array of integers 'ans' where 'ans[i]' is the
 * index of the string in 'wordsContainer' that has the longest common suffix
 * with 'wordsQuery[i]'.
 */

struct trie_node {
  struct trie_node *children[26];
  int min_len;
  int idx;
};

struct trie_node *trie_node_init(void) {
  struct trie_node *obj = (struct trie_node *)malloc(sizeof(struct trie_node));
  for (int i = 0; i < 26; i++)
    obj->children[i] = NULL;
  obj->min_len = obj->idx = INT_MAX;
  return obj;
}

void insert(struct trie_node *root, const char *s, int idx) {
  int n = strlen(s);
  struct trie_node *node = root;
  if (n < node->min_len) {
    node->min_len = n;
    node->idx = idx;
  }
  for (int i = 0; i < n; i++) {
    int curr = s[i] - 'a';
    if (!node->children[curr])
      node->children[curr] = trie_node_init();
    node = node->children[curr];
    if (n < node->min_len) {
      node->min_len = n;
      node->idx = idx;
    }
  }
}

int query(struct trie_node *root, const char *s) {
  int n = strlen(s);
  struct trie_node *node = root;
  for (int i = 0; i < n; i++) {
    int curr = s[i] - 'a';
    if (node->children[curr])
      node = node->children[curr];
    else
      break;
  }
  return node->idx;
}

void trie_node_free(struct trie_node *obj) {
  for (int i = 0; i < 26; i++)
    if (obj->children[i])
      trie_node_free(obj->children[i]);
  free(obj);
}

void reverse_string(char *s) {
  int n = strlen(s);
  for (int i = 0, j = n - 1; i < j; i++, j--) {
    char tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
  }
}

int *stringIndices(char **wordsContainer, int wordsContainerSize,
                   char **wordsQuery, int wordsQuerySize, int *returnSize) {
  struct trie_node *root = trie_node_init();
  for (int i = 0; i < wordsContainerSize; i++) {
    reverse_string(wordsContainer[i]);
    insert(root, wordsContainer[i], i);
  }
  int *ans = (int *)malloc(wordsQuerySize * sizeof(int));
  *returnSize = wordsQuerySize;
  for (int i = 0; i < wordsQuerySize; i++) {
    reverse_string(wordsQuery[i]);
    ans[i] = query(root, wordsQuery[i]);
  }
  trie_node_free(root);
  return ans;
}

int main() {
  char *wc1[] = {"abcd", "bcd", "xbcd"};
  char *wq1[] = {"cd", "bcd", "xyz"};
  char *wc2[] = {"abcdefgh", "poiuygh", "ghghgh"};
  char *wq2[] = {"gh", "acbfgh", "acbfegh"};
  int r1[] = {1, 1, 1}, rs1;
  int r2[] = {2, 0, 2}, rs2;
  int *si1 = stringIndices(wc1, ARRAY_SIZE(wc1), wq1, ARRAY_SIZE(wq1), &rs1);
  int *si2 = stringIndices(wc2, ARRAY_SIZE(wc2), wq2, ARRAY_SIZE(wq2), &rs2);
  for (int i = 0; i < rs1; i++) {
    printf("%d ", si1[i]);
    assert(si1[i] == r1[i]);
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    printf("%d ", si2[i]);
    assert(si2[i] == r2[i]);
  }
  printf("\n");
  free(si1);
  free(si2);
}
