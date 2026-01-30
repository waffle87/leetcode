// 2977. Minimum Cost to Convert String II
#include "leetcode.h"

/*
 * you are given two 0 indexed strings 'source' and 'target'. both of length 'n'
 * and consisting of lowercase english letters. you are also given two 0 indexed
 * string arrays 'original' and 'changed', and an integer array 'cost' where
 * 'cost[i]' represents the cost of converting the string 'original[i]' to the
 * string 'changed[i]'. you start with the string 'source'. in one operation,
 * you can pick a substring 'x' from the string and change it to 'y' at a cost
 * of 'z' if there exists any index 'j' such that 'cost[j] == z', 'original[j]
 * == x', and 'changed[j] == y'. you are allowed to do any number of operations
 * but any pair of operations must satisfy either of these two conditions.
 * return the minimum cost to convert the string 'source' to the string 'target'
 * using any number of operations. if it is impossible to convert 'source' to
 * 'target', return -1. note that there may exist indices 'i', 'j' such that
 * 'original[i] == original[j]' and 'changed[i] == changed[j]'
 */

struct trie {
  struct trie *child[26];
  int id;
};

struct trie *trie_init(void) {
  struct trie *node = (struct trie *)malloc(sizeof(struct trie));
  for (int i = 0; i < 26; i++)
    node->child[i] = NULL;
  node->id = -1;
  return node;
}

void trie_free(struct trie *node) {
  if (node)
    free(node);
}

int trie_add(struct trie *node, const char *word, int *idx) {
  for (int i = 0; word[i]; i++) {
    int ch = word[i] - 'a';
    if (!node->child[ch])
      node->child[ch] = trie_init();
    node = node->child[ch];
  }
  if (node->id == -1)
    node->id = ++(*idx);
  return node->id;
}

void update(long long *x, long long y) {
  if (*x == -1 || y < *x)
    *x = y;
}

long long minimumCost(char *source, char *target, char **original,
                      int originalSize, char **changed, int changedSize,
                      int *cost, int costSize) {
  int n = strlen(source), m = originalSize, p = -1, node_cnt = m * 2;
  int **grid = (int **)malloc(node_cnt * sizeof(int *));
  struct trie *root = trie_init();
  for (int i = 0; i < node_cnt; i++) {
    grid[i] = (int *)malloc(node_cnt * sizeof(int));
    for (int j = 0; j < node_cnt; j++)
      grid[i][j] = INT_MAX / 2;
    grid[i][i] = 0;
  }
  for (int i = 0; i < m; i++) {
    int x = trie_add(root, original[i], &p);
    int y = trie_add(root, changed[i], &p);
    grid[x][y] = fmin(grid[x][y], cost[i]);
  }
  for (int k = 0; k <= p; k++)
    for (int i = 0; i <= p; i++)
      for (int j = 0; j <= p; j++)
        grid[i][j] = fmin(grid[i][j], grid[i][k] + grid[k][j]);
  long long *f = (long long *)malloc(n * sizeof(long long));
  memset(f, -1, n * sizeof(long long));
  for (int j = 0; j < n; j++) {
    if (j > 0 && f[j - 1] == -1)
      continue;
    long long base = !j ? 0 : f[j - 1];
    if (source[j] == target[j])
      update(&f[j], base);
    struct trie *u = root, *v = root;
    for (int i = j; i < n; i++) {
      u = u->child[source[i] - 'a'];
      v = v->child[target[i] - 'a'];
      if (!u || !v)
        break;
      if (u->id != -1 && v->id != -1 && grid[u->id][v->id] != INT_MAX / 2)
        update(&f[i], base + grid[u->id][v->id]);
    }
  }
  long long ans = f[n - 1];
  for (int i = 0; i < node_cnt; i++)
    free(grid[i]);
  free(grid);
  free(f);
  trie_free(root);
  return ans;
}

int main() {
  char *s1 = "abcd", *t1 = "acbe", *o1[] = {"a", "b", "c", "c", "e", "d"},
       *ch1[] = {"b", "c", "b", "e", "b", "e"};
  char *s2 = "abcdefgh", *t2 = "acdeeghh", *o2[] = {"bcd", "fgh", "thh"},
       *ch2[] = {"cde", "thh", "ghh"};
  char *s3 = "abcdefgh", *t3 = "addddddd", *o3[] = {"bcd", "defgh"},
       *ch3[] = {"ddd", "ddddd"};
  int co1[] = {2, 5, 5, 1, 2, 20}, co2[] = {1, 3, 5}, co3[] = {100, 1578};
  printf("%lld\n", minimumCost(s1, t1, o1, ARRAY_SIZE(o1), ch1, ARRAY_SIZE(ch1),
                               co1, ARRAY_SIZE(co1))); // expect: 28
  printf("%lld\n", minimumCost(s2, t2, o2, ARRAY_SIZE(o2), ch2, ARRAY_SIZE(ch2),
                               co2, ARRAY_SIZE(co2))); // expect: 9
  printf("%lld\n", minimumCost(s3, t3, o3, ARRAY_SIZE(o3), ch3, ARRAY_SIZE(ch3),
                               co3, ARRAY_SIZE(co3))); // expect: -1
}
