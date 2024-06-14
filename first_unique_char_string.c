// 387. First Unique Character in a String
#include "leetcode.h"

/*
 * given a string 's', find the first non-repeating character in it and return
 * its index. if it does not exist, return -1
 */

int firstUniqChar(char *s) {
  int cnt[26], n = strlen(s);
  memset(cnt, 0, sizeof(int) * 26);
  for (int i = 0; i < n; i++) {
    char c = s[i];
    cnt[c - 'a'] += 1;
  }
  for (int i = 0; i < n; i++) {
    char c = s[i];
    if (cnt[c - 'a'] == 1)
      return i;
  }
  return -1;
}

int main() {
  char *s1 = "leetcode", *s2 = "loveleetcode", *s3 = "aabb";
  printf("%d\n", firstUniqChar(s1)); // expect: 0
  printf("%d\n", firstUniqChar(s2)); // expect: 2
  printf("%d\n", firstUniqChar(s3)); // expect: -1
}
