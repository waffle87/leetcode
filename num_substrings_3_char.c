#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int helper(char *s, int k) {
  int n = strlen(s), type = 0, left = 0, right = 0, res = 0;
  int *cn = calloc(3, sizeof(int));
  for (int right = 0; right < n; right++) {
    cn[s[right] - 'a']++;
    if (cn[s[right] - 'a'] == 1)
      type++;
    while (type > k) {
      cn[s[left] - 'a']--;
      if (!cn[s[left] - 'a'])
        type--;
      left++;
    }
    res += right - left + 1;
  }
  return res;
}

int numberOfSubstrings(char *s) { return helper(s, 3) - helper(s, 2); }

int main() {
  char s1[] = {"abcabc"}, s2[] = {"aaacb"}, s3[] = {"abc"};
  printf("%d\n", numberOfSubstrings(s1)); // expect: 10
  printf("%d\n", numberOfSubstrings(s2)); // expect: 3
  printf("%d\n", numberOfSubstrings(s3)); // expect: 1
}
