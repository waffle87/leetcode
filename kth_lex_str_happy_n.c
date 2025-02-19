// 1415. The k-th Lexicographical String of All Happy Strings of Length n
#include "leetcode.h"

/*
 * a happy string is a string that consists only of letters of the set '[a, b,
 * c]', 's[i] != s[i + 1]' for all values of 'i' from 1 to 's.length - 1'. given
 * two integers 'n' and 'k', consider a list of all happy strings of length 'n'
 * sorted in lexicographical order. return the k'th string of this list or
 * return an empty string if there are less than 'k' strings of length 'n'.
 */

char *dfs(char *prefix, int n, int m, int *k) {
  if (!n)
    return prefix;
  for (char c = 'a'; c <= 'c'; c++) {
    int n = strlen(prefix);
    if (n && c == prefix[n - 1])
      continue;
    int cnt = (int)pow(2, m - n - 1);
    if (cnt >= *k) {
      prefix[n] = c;
      prefix[n + 1] = '\0';
      return dfs(prefix, n - 1, m, k);
    } else
      *k -= cnt;
  }
  return "";
}

char *getHappyString(int n, int k) {
  int m = n;
  char *prefix = (char *)malloc((n + 1) * sizeof(char));
  prefix[0] = '\0';
  return dfs(prefix, n, m, &k);
}

int main() {
  printf("%s\n", getHappyString(1, 3)); // expect: c
  printf("%s\n", getHappyString(1, 4)); // expect: null
  printf("%s\n", getHappyString(3, 9)); // expect: cab
}
