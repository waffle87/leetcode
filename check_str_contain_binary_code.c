// 1461. Check If a String Contains All Binary Codes of Size K
#include "leetcode.h"

/*
 * given a binary string 's', and an integer 'k', return true if every binary
 * code of length 'k' is a substring of 's', otherwise return 'false'.
 */

bool hasAllCodes(char *s, int k) {
  int n = strlen(s), m = 1 << k, window = 0;
  if (n < m)
    return false;
  bool *vis = (bool *)calloc(m, sizeof(bool));
  if (k > 1)
    for (int i = 0; i < k - 1; i++)
      window = (window << 1) + (s[i] - '0');
  for (int i = k - 1; i < n; i++) {
    window = (window << 1) + (s[i] - '0');
    window &= (m - 1);
    vis[window] = true;
  }
  for (int i = 0; i < m; i++)
    if (!vis[i]) {
      free(vis);
      return false;
    }
  free(vis);
  return true;
}

int main() {
  char *s1 = "00110110", *s2 = "0110", *s3 = "0110";
  bool r1 = hasAllCodes(s1, 2);
  bool r2 = hasAllCodes(s2, 1);
  bool r3 = hasAllCodes(s3, 2);
  printf("%d\n", r1); // expect: 1
  assert(r1 == true);
  printf("%d\n", r2); // expect: 1
  assert(r2 == true);
  printf("%d\n", r3); // expect: 0
  assert(r3 == false);
}
