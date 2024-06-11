// 2663. Lexicographically Smallest Beautiful String
#include "leetcode.h"

/*
 * a string is beautiful if it consists of the first 'k' letters of the english
 * lowercase alphabet, it does not contain a palindrome of length 2 or more
 * which is a palindrome. you are given a beautiful string 's' of length 'n',
 * and a positive integer 'k'. return the lexicographically smallest string of
 * length 'n' which is larger than 's', and is beautiful. if there is no such
 * string, return an empty string.
 */

char *smallestBeautifulString(char *s, int k) {
  int n = strlen(s);
  char *ans = (char *)malloc((n + 1) * sizeof(char));
  strcpy(ans, s);
  for (int i = n - 1; i >= 0; i--) {
    for (int j = ans[i] - 'a' + 1; j < k; j++) {
      char curr = j + 'a';
      if ((i < 1 || curr != ans[i - 1]) && (i < 2 || curr != ans[i - 2])) {
        ans[i] = curr;
        for (int l = i + 1; l < n; l++) {
          for (int m = 0; m < k; m++) {
            curr = m + 'a';
            if ((l < 1 || curr != ans[l - 1]) &&
                (l < 2 || curr != ans[l - 2])) {
              ans[l] = curr;
              break;
            }
          }
        }
        return ans;
      }
    }
  }
  return "";
}

int main() {
  char *s1 = "abcz", *s2 = "dc";
  char *sbs1 = smallestBeautifulString(s1, 26);
  char *sbs2 = smallestBeautifulString(s2, 4);
  printf("%s\n", sbs1); // expect: abda
  printf("%s\n", sbs2); // expect: null
  free(sbs1);
  free(sbs2);
}
