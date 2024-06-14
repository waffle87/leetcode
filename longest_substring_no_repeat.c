// 3. Longest Substring Without Repeating Characters
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * given a string 's', find the length of the longest substring without
 * repeating characters.
 */

int lengthOfLongestSubstring(char *s) {
  int cnt[512], n = strlen(s), win_start = 0, best = 0, i;
  memset(cnt, 0, sizeof(int) * 512);
  for (i = 0; i < n; i++) {
    int c = s[i];
    if (cnt[c] >= 1) {
      assert(cnt[c] >= 1);
      while (win_start < i) {
        int to_delete = s[win_start];
        cnt[to_delete]--;
        win_start++;
        if (!cnt[c])
          break;
      }
    }
    cnt[c]++;
    best = fmax(best, i - win_start + 1);
  }
  return best;
}

int main() {
  char s1[] = {"abcabcbb"}, s2[] = {"bbbbb"}, s3[] = {"pwwkew"};
  printf("%d\n", lengthOfLongestSubstring(s1)); // expect: 3
  printf("%d\n", lengthOfLongestSubstring(s2)); // expect: 1
  printf("%d\n", lengthOfLongestSubstring(s3)); // expect: 3
}
