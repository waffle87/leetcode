// 2791. Count Paths That Can Form a Palindrome in a Tree
#include "leetcode.h"

/*
 * you are given a tree (ie. a connected, undirected graph that has no cycles)
 * rooted at node 0 consisting of 'n' nodes numbered from 0 to 'n - 1'. the tree
 * is represented by a 0-indexed array 'parent' of size 'n' where 'parent[i]' is
 * the parent of node 'i'. since node 0 is the root, 'parent[0] == -1'. you are
 * also given a string 's' of length 'n' where 's[i]' is the character assigned
 * to the edge between 'i' and 'parent[i]'. 's[0]' can be ignored. return the
 * number of pairs of nodes '(u, v)' such that 'u < v' and the characters
 * assigned to edges on the path from 'u' to 'v' can rearranged to form a
 * palindrome
 */

void fill_table(int *parent, int parentSize, char *s, int *dp, int *filled,
                int k, int *hash_table, int *hash_vals) {
  if (filled[k])
    return;
  if (!k) {
    filled[k] = 1;
    hash_table[0] = 1;
    hash_vals[0] = 0;
    return;
  }
  fill_table(parent, parentSize, s, dp, filled, parent[k], hash_table,
             hash_vals);
  int mask = dp[parent[k]] ^ (1 << (s[k] - 97));
  dp[k] = mask;
  filled[k] = 1;
  int kk = parentSize * 2, idx = mask % kk;
  while (hash_vals[idx] != -1 && hash_vals[idx] != mask) {
    idx++;
    if (idx >= kk)
      idx -= kk;
  }
  if (hash_vals[idx] == -1)
    hash_vals[idx] = mask;
  hash_table[idx]++;
}

long long countPalindromePaths(int *parent, int parentSize, char *s) {
  int kk = parentSize * 2, n = parentSize;
  int *dp = (int *)calloc(n, sizeof(int));
  int *filled = (int *)calloc(n, sizeof(int));
  int *hash_table = (int *)calloc(kk, sizeof(int));
  int *hash_vals = (int *)malloc(kk * sizeof(int));
  for (int i = 0; i < kk; i++)
    hash_vals[i] = -1;
  for (int k = 0; k < n; k++)
    fill_table(parent, parentSize, s, dp, filled, k, hash_table, hash_vals);
  long long cnt = 0;
  for (int k = 0; k < n; k++) {
    int mask = dp[k];
    int idx = mask % kk;
    while (hash_vals[idx] != -1 && hash_vals[idx] != mask) {
      idx++;
      if (idx >= kk)
        idx -= kk;
    }
    cnt += hash_table[idx] - 1;
    for (int j = 0; j < 26; j++) {
      int new_mask = mask ^ (1 << j);
      int new_idx = new_mask % kk;
      while (hash_vals[new_idx] != -1 && hash_vals[new_idx] != new_mask) {
        new_idx++;
        if (new_idx >= kk)
          new_idx -= kk;
      }
      cnt += hash_table[new_idx];
    }
  }
  free(dp), free(filled), free(hash_table), free(hash_vals);
  return cnt;
}

int main() {
  int p1[] = {-1, 0, 0, 1, 1, 2}, p2[] = {-1, 0, 0, 0, 0};
  char *s1 = "acaabc", *s2 = "aaaaa";
  printf("%lld\n", countPalindromePaths(p1, ARRAY_SIZE(p1), s1)); // expect: 8
  printf("%lld\n", countPalindromePaths(p2, ARRAY_SIZE(p2), s2)); // expect: 10
}
