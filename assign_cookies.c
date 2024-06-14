// 455. Assign Cookies
#include "leetcode.h"

/*
 * assume you are an awesome parent and want to give your children some cookies.
 * but you should give each child at most one cookie. each child 'i' has a greed
 * factor 'g[i]', which is the minimum size of a cookie that the child will be
 * content with; and each cookie 'j' has a size 's[j]' if 's[j] >= g[i]', we can
 * assign the cookie 'j' to the child 'i', and the child 'i' will be content.
 * your goal is to maximise the number of your content children and output the
 * maximum number.
 */

int cmp(const void *a, const void *b) {
  return *(const int *)a > *(const int *)b;
}

int findContentChildren(int *g, int g_size, int *s, int s_size) {
  qsort(g, g_size, sizeof(int), cmp);
  qsort(s, s_size, sizeof(int), cmp);
  int s_idx = 0, g_idx = 0, cnt = 0;
  while (s_idx < s_size && g_idx < g_size) {
    if (s[s_idx] < g[g_idx])
      s_idx++;
    else
      s_idx++, g_idx++, cnt++;
  }
  return cnt;
}

int main() {
  int g1[] = {1, 2, 3}, g2[] = {1, 2};
  int s1[] = {1, 1}, s2[] = {1, 2, 3};
  printf("%d\n", findContentChildren(g1, ARRAY_SIZE(g1), s1,
                                     ARRAY_SIZE(s1))); // expect: 1
  printf("%d\n", findContentChildren(g2, ARRAY_SIZE(g2), s2,
                                     ARRAY_SIZE(s2))); // expect: 2
}
