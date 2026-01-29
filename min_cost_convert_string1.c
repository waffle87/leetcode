// 2976. Minimum Cost to Convert String I
#include "leetcode.h"

/*
 * you are given two 0 indexed strings 'source' and 'target', both of length 'n'
 * and consisting of lowercase english letters. you are also given two 0 indexed
 * character arrays 'original' and 'changed', and an integer array 'cost' where
 * 'cost[i]' represents the cost of changing the character 'original[i]' to the
 * character 'changed[i]' you start with the string 'source'. in one operation,
 * you can pick a character 'x' from te string and change it to the character
 * 'y' at a cost of 'z' if there exists any index 'j' such that 'cost[j] == z,
 * original[j] == x, changed[j] == y'. return the minimum cost to conver the
 * string 'source' to the string 'target'.
 */

long long minimumCost(char *source, char *target, char *original,
                      int originalSize, char *changed, int changedSize,
                      int *cost, int costSize) {
  int dist[26][26];
  for (int i = 0; i < 26; i++)
    for (int j = 0; j < 26; j++)
      dist[i][j] = i == j ? 0 : INT_MAX;
  for (int i = 0; i < originalSize; i++) {
    int u = original[i] - 'a';
    int v = changed[i] - 'a';
    int w = cost[i];
    if (w < dist[u][v])
      dist[u][v] = w;
  }
  for (int k = 0; k < 26; k++)
    for (int i = 0; i < 26; i++)
      for (int j = 0; j < 26; j++)
        if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&
            dist[i][k] + dist[k][j] < dist[i][j])
          dist[i][j] = dist[i][k] + dist[k][j];
  int s = strlen(source);
  long long ans = 0;
  for (int i = 0; i < s; i++) {
    int l = source[i] - 'a', r = target[i] - 'a';
    if (dist[l][r] == INT_MAX)
      return -1;
    else
      ans += dist[l][r];
  }
  return ans;
}

int main() {
  char *s1 = "abcd", *t1 = "acbe", o1[] = {'a', 'b', 'c', 'c', 'e', 'd'},
       c1[] = {'b', 'c', 'b', 'e', 'b', 'e'};
  char *s2 = "aaaa", *t2 = "bbbb", o2[] = {'a', 'c'}, c2[] = {'c', 'b'};
  char *s3 = "abcd", *t3 = "abce", o3[] = {'a'}, c3[] = {'e'};
  int co1[] = {2, 5, 5, 1, 2, 20}, co2[] = {1, 2}, co3[] = {10000};
  printf("%lld\n", minimumCost(s1, t1, o1, ARRAY_SIZE(o1), c1, ARRAY_SIZE(c1),
                               co1, ARRAY_SIZE(co1))); // expect: 28
  printf("%lld\n", minimumCost(s2, t2, o2, ARRAY_SIZE(o2), c2, ARRAY_SIZE(c2),
                               co2, ARRAY_SIZE(co3))); // expect: 12
  printf("%lld\n", minimumCost(s3, t3, o3, ARRAY_SIZE(o3), c3, ARRAY_SIZE(c3),
                               co3, ARRAY_SIZE(co3))); // expect: -1
}
