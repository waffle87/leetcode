// 402. Remove K Digits
#include "leetcode.h"

/*
 * given string 'num' representing a non-negative integer 'num', and an integer
 * 'k' return the smallest possible integer after removing 'k' digits from
 * 'num'.
 */

char *removeKdigits(char *num, int k) {
  int n = strlen(num), s_idx = 1;
  if (k >= n)
    return "0";
  int *stk = malloc(n * sizeof(int));
  stk[0] = 0;
  for (int i = 1; i < n; i++) {
    if (!k) {
      stk[s_idx] = i;
      s_idx++;
      continue;
    }
    while (s_idx && num[i] < num[stk[s_idx - 1]]) {
      s_idx--, k--;
      if (!k)
        break;
    }
    stk[s_idx] = i;
    s_idx++;
  }
  int i = 0, a_idx = 0;
  s_idx -= k;
  char *ans = malloc(s_idx + 1);
  for (i = 0; i < s_idx; i++)
    if (num[stk[i]] != '0')
      break;
  for (int j = i; j < s_idx; j++) {
    ans[a_idx] = num[stk[j]];
    a_idx++;
  }
  ans[a_idx] = '\0';
  if (!a_idx)
    return "0";
  return ans;
}

int main() {
  char *n1 = "1432219", *n2 = "10200", *n3 = "10";
  printf("%s\n", removeKdigits(n1, 3)); // expect: 1219
  printf("%s\n", removeKdigits(n2, 1)); // expect: 200
  printf("%s\n", removeKdigits(n3, 2)); // expect: 0
}
