// 93. Restore IP Addresses
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define IN_RANGE(c, m, n) ((c) >= (m) && c <= (n))

/*
 * a valid ip address consists of exactly 4 integers separated by single dots
 * each integer is between 0 and 255 (inclusive) and cannot have leading 0's
 * given: string 's' containing only digits, return all possible valid ip
 * addresses that can be formed by insert dots into 's'. digits cannot be
 * reordered or removed. return addresses in any order.
 */

int isValidPart(char *s, int l) {
  switch (l) {
  case 1:
    return IN_RANGE(s[0], '0', '9');
    break;
  case 2:
    return IN_RANGE(s[0], '1', '9') && IN_RANGE(s[1], '0', '9');
    break;
  case 3:
    return (s[0] == '1' && IN_RANGE(s[1], '0', '9') &&
            IN_RANGE(s[2], '0', '9')) ||
           (s[0] == '2' &&
            (IN_RANGE(s[1], '0', '4') && IN_RANGE(s[2], '0', '9') ||
             s[1] == '5' && IN_RANGE(s[2], '0', '5')));
    break;
  default:
    return 0;
  }
}

char *getAddr(char *s, int l, int a, int b, int c) {
  if (isValidPart(s, a) && isValidPart(s + a, b - a) &&
      isValidPart(s + b, c - b) && isValidPart(s + c, l - c)) {
    char *addr = malloc(sizeof(char) * (l + 4));
    memcpy(addr, s, a);
    memcpy(addr + a + 1, s + a, b - a);
    memcpy(addr + b + 2, s + b, c - b);
    memcpy(addr + c + 3, s + c, l - c);
    addr[a] = addr[b + 1] = addr[c + 2] = '.';
    addr[l + 3] = '\0';
    return addr;
  } else
    return NULL;
}

char **restoreIpAddresses(char *s, int *returnSize) {
  *returnSize = 0;
  int l = strlen(s), a, b, c;
  if (l < 4 || l > 12)
    return NULL;
  char **addrs = malloc(sizeof(char *) * ((l - 1) * (l - 2) * (l - 3) / 6)),
       *addr;
  for (a = 1; a < 4; a++) {
    if (a > l - 3 || a < l - 9)
      continue;
    for (b = a + 1; b < a + 4; b++) {
      if (b > l - 2 || b < l - 6)
        continue;
      for (c = b + 1; c < b + 4; c++) {
        if (c > l - 1 || c < l - 3)
          continue;
        if (addr = getAddr(s, l, a, b, c))
          addrs[(*returnSize)++] = addr;
      }
    }
  }
  return addrs;
}

int main() { char s1[] = {"25525511135"}, s2[] = {"0000"}, s3[] = {"101023"}; }
