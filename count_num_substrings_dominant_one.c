// 3234. Count the Number of Substrings With Dominant Ones
#include "leetcode.h"

/*
 * you are given a binary string 's'. return the number of substrings with
 * dominant ones. a string has dominant ones if the number of ones in the string
 * is greater than or equal to the sqaure of the number of zeroes in the string.
 */

int numberOfSubstrings(char *s) {
  int n = strlen(s), ans = 0;
  int *pre = (int *)malloc((n + 1) * sizeof(int));
  pre[0] = -1;
  for (int i = 0; i < n; i++)
    pre[i + 1] = !i || (i > 0 && s[i - 1] == '0') ? i : pre[i];
  for (int i = 1; i <= n; i++) {
    int cnt0 = s[i - 1] == '0' ? 1 : 0, j = i;
    while (j > 0 && cnt0 * cnt0 <= n) {
      int cnt1 = (i - pre[j]) - cnt0;
      if (cnt0 * cnt0 <= cnt1) {
        int add = j - pre[j];
        if (cnt1 - cnt0 * cnt0 + 1 < add)
          add = cnt1 - cnt0 * cnt0 + 1;
        ans += add;
      }
      j = pre[j];
      cnt0++;
    }
  }
  free(pre);
  return ans;
}

int main() {
  char *s1 = "00011", *s2 = "101101";
  printf("%d\n", numberOfSubstrings(s1)); // expect: 5
  printf("%d\n", numberOfSubstrings(s2)); // expect: 16
}
