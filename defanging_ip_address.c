// 1108. Defanging an IP Address
#include "leetcode.h"

/*
 * given a valid ipv4 'address', return a defanged version of that ip address. a
 * defanged ip address replaces every period "." with '[.]'.
 */

char *defangIPaddr(char *address) {
  char *ip = (char *)calloc(sizeof(char), sizeof("###[.]###[.]###[.]###"));
  char *ans = ip;
  for (char *i = address; *i; i++) {
    if (*i == '.') {
      *ip++ = '[';
      *ip++ = '.';
      *ip++ = ']';
    } else
      *ip++ = *i;
  }
  return ans;
}

int main() {
  char *a1 = "1.1.1.1", *dipa1 = defangIPaddr(a1);
  char *a2 = "255.100.50.0", *dipa2 = defangIPaddr(a2);
  printf("%s\n", dipa1); // expect: 1[.]1[.]1[.]1
  printf("%s\n", dipa2); // expect: 255[.]100[.]50[.]0
  free(dipa1);
  free(dipa2);
}
