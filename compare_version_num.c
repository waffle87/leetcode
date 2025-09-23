// 165. Compare Version Numbers
#include "leetcode.h"

/*
 * given two version numbers 'version1' and 'version2', compare them. version
 * numbers consist of one or more revisions joined by a dot. each revision
 * consists of digits and may contain leading zeros. every revision contains at
 * least one character. revisions are 0-indexed from left to right, right the
 * leftmost revision being revision 0, the next revision being revision 1, and
 * so on. to compare version numbers, use the following rules. if 'version1 <
 * version2' return -1, if 'version1 > version2' return 1, otherwise, return 0
 */

int compareVersion(char *version1, char *version2) {
  int i = 0, j = 0, num1 = 0, num2 = 0;
  int n = strlen(version1), m = strlen(version2);
  while (i < n || j < m) {
    while (i < n && version1[i] != '.')
      num1 = num1 * 10 + (version1[i++] - '0');
    while (j < m && version2[j] != '.')
      num2 = num2 * 10 + (version2[j++] - '0');
    if (num1 > num2)
      return 1;
    else if (num1 < num2)
      return -1;
    num1 = num2 = 0;
    if (i < n)
      i++;
    if (j < m)
      j++;
  }
  return 0;
}

int main() {
  char *v11 = "1.2", *v21 = "1.10";
  char *v12 = "1.01", *v22 = "1.001";
  char *v13 = "1.0", *v23 = "1.0.0.0";
  printf("%d\n", compareVersion(v11, v21)); // expect: -1
  printf("%d\n", compareVersion(v12, v22)); // expect: 0
  printf("%d\n", compareVersion(v13, v23)); // expect: 0
}
