// 93. Restore IP Addresses
#include "leetcode.h"

/*
 * a valid ip address consists of exactly 4 integers separated by single dots
 * each integer is between 0 and 255 (inclusive) and cannot have leading 0's
 * given: string 's' containing only digits, return all possible valid ip
 * addresses that can be formed by insert dots into 's'. digits cannot be
 * reordered or removed. return addresses in any order.
 */

char **restoreIpAddresses(char *s, int *returnSize) {
  int n = strlen(s), capacity = 0;
  char **ans = NULL;
  *returnSize = 0;
  for (int a = 1; a <= 3 && a + 2 < n && (1 == a || '0' != s[0]) &&
                  (a < 3 || 0 > memcmp(s, "256", 3));
       ++a) {
    for (int b = a + 1;
         b <= a + 3 && b + 1 < n && (a + 1 == b || '0' != s[a]) &&
         (b < a + 3 || 0 > memcmp(s + a, "256", 3));
         ++b) {
      for (int c = b + 1; c <= b + 3 && c < n && (b + 1 == c || '0' != s[b]) &&
                          (c < b + 3 || 0 > memcmp(s + b, "256", 3));
           ++c) {
        if (c + 3 >= n && (c + 1 == n || '0' != s[c]) &&
            (n < c + 3 || 0 > memcmp(s + c, "256", 3))) {
          if (*returnSize >= capacity) {
            capacity = capacity ? capacity * 2 : 1;
            ans = (char **)realloc(ans, capacity * sizeof(char *));
          }
          char *dest = (char *)malloc((n + 4) * sizeof(char));
          memcpy(dest, s, a);
          dest[a] = '.';
          memcpy(dest + a + 1, s + a, b - a);
          dest[b + 1] = '.';
          memcpy(dest + b + 2, s + b, c - b);
          dest[c + 2] = '.';
          memcpy(dest + c + 3, s + c, n - c);
          dest[n + 3] = '\0';
          ans[(*returnSize)++] = dest;
        }
      }
    }
  }
  return ans;
}

int main() {
  char *s1 = "25525511135", *s2 = "0000", *s3 = "101023";
  int rs1, rs2, rs3;
  char **ria1 = restoreIpAddresses(s1, &rs1);
  char **ria2 = restoreIpAddresses(s2, &rs2);
  char **ria3 = restoreIpAddresses(s3, &rs3);
  for (int i = 0; i < rs1; i++)
    printf("%s ", ria1[i]); // expect: ["255.255.11.135","255.255.111.35"]
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%s ", ria2[i]); // expect: ["0.0.0.0"]
  printf("\n");
  for (int i = 0; i < rs3; i++)
    printf(
        "%s ",
        ria3[i]); // expect:
                  // ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
  printf("\n");
  free(ria1);
  free(ria2);
  free(ria3);
}
