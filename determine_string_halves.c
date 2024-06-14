// 1704. Determine if String Halves Are Alike
#include "leetcode.h"

/*
 * given a string 's' of even length. split this string into two halves of equal
 * lengths and let 'a' be the first half and 'b' be the second half. two strings
 * are alike if they have the same number of vowels (a e i o u, A E I O U)
 * notice that 's' contains uppercase and lowercase letters. return 'true' if a
 * and b are alike, otherwise return false.
 */

int check(char *s, int n) {
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] >= 'a') {
      if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
          s[i] == 'u')
        ans++;
    } else {
      if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' ||
          s[i] == 'U')
        ans++;
    }
  }
  return ans;
}

bool halvesAreAlike(char *s) {
  int n = strlen(s);
  return check(s, n / 2) == check(&s[n / 2], n / 2) ? 1 : 0;
}

int main() {
  char s1[] = {"book"}, s2[] = {"textbook"};
  printf("%d\n", halvesAreAlike(s1)); // expect: 1
  printf("%d\n", halvesAreAlike(s2)); // expect: 0
}
