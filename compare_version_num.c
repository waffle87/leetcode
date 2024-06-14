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

int count_dot(char *s, int n) {
  int dot = 0;
  for (int i = 0; i < n; i++)
    if (s[i] == '.')
      dot++;
  return dot;
}

void helper(char *s, int n, int *data) {
  int val = 0, idx = 0;
  for (int i = 0; i < n; i++)
    if (s[i] == '.') {
      data[idx] = val;
      idx++;
      val = 0;
    } else {
      val = val * 10 + s[i] - '0';
    }
  data[idx] = val;
}

int compareVersion(char *version1, char *version2) {
  int n1 = strlen(version1), n2 = strlen(version2);
  int p1 = 0, p2 = 0, ans = 0;
  int item1 = count_dot(version1, n1) + 1;
  int item2 = count_dot(version2, n2) + 1;
  int *data1 = (int *)malloc(item1 * sizeof(int));
  int *data2 = (int *)malloc(item2 * sizeof(int));
  helper(version1, n1, data1);
  helper(version2, n2, data2);
  while (p1 < item1 || p2 < item2) {
    if (p1 == item1) {
      for (int i = p2; i < item2; i++)
        if (!data2[i]) {
          ans = -1;
          goto exit;
        }
      ans = 0;
      goto exit;
    } else if (p2 == item2) {
      for (int i = p1; i < item1; i++)
        if (!data1[i]) {
          ans = 1;
          goto exit;
        }
      ans = 0;
      goto exit;
    } else {
      if (data1[p1] > data2[p2]) {
        ans = 1;
        goto exit;
      }
      if (data1[p1] < data2[p2]) {
        ans = -1;
        goto exit;
      }
      p1++, p2++;
    }
  }
exit:
  free(data1), free(data2);
  return ans;
}

int main() {
  char *v11 = "1.01", *v21 = "1.001", *v12 = "1.0", *v22 = "1.0.0",
       *v13 = "0.1", *v23 = "1.1";
  printf("%d\n", compareVersion(v11, v21)); // expect: 0
  printf("%d\n", compareVersion(v12, v22)); // expect: 0
  printf("%d\n", compareVersion(v13, v23)); // expect: -1
}
