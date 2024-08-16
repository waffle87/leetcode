// 3223. Minimum Length of String After Operations
#include "leetcode.h"

/*
 * you are given a string 's'. you can perform the following process on 's' any
 * number of times: choose an index 'i' in the string such that there is at
 * least one character to the left of index 'i' that is equal to 's[i]' and at
 * least one character to the right that is also equal to 's[i]', delete the
 * closest character to the left of index 'i' that is equal to 's[i]', delete
 * the closest character to the right of index 'i' that is equal to 's[i]'.
 * return the minimum length of the final string 's' that you can achieve
 */

int minimumLength(char *s) {
  int *lower_cnt = (int *)calloc(26, sizeof(int)), ans = 0;
  for (int i = 0; s[i] != '\0'; i++) {
    assert(s[i] >= 'a' && s[i] <= 'z');
    lower_cnt[s[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++)
    ans += lower_cnt[i] <= 2 ? lower_cnt[i] : (lower_cnt[i] % 2 ? 1 : 2);
  free(lower_cnt);
  return ans;
}

int main() {
  char *s1 = "abaacbcbb", *s2 = "aa";
  printf("%d\n", minimumLength(s1)); // expect: 5
  printf("%d\n", minimumLength(s2)); // expect: 2
}
