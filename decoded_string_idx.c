// 880. Decoded String at Index
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * given an encoded string 's'. to decode the string to a tape, the encoded
 * string is read one character at a time at a time the following steps are
 * taken. if the character read is a letter, that letter is written onto the
 * tape. if the character read is a digit 'd', the entire current tape is
 * repeatedly written 'd - 1' more times in total. given an integer 'k', return
 * the k'th letter (1-indexed) in the decoded string.
 */

char *decodeAtIndex(char *s, int k) {
  long long cnt = 0;
  int n = strlen(s);
  for (int i = 0; i < n; i++) {
    char ptr;
    if (isalpha(s[i])) {
      cnt++;
      ptr = s[i];
      if (cnt == k) {
        char *ans = malloc(2);
        ans[0] = s[i];
        ans[1] = '\0';
        return ans;
      }
    } else {
      int times = s[i] - '0';
      if (cnt * times < k)
        cnt *= times;
      else if (!(k % cnt)) {
        char *ans = malloc(2);
        ans[0] = ptr;
        ans[1] = '\0';
        return ans;
      } else {
        s[i] = '\0';
        return decodeAtIndex(s, k % cnt);
      }
    }
  }
  return "";
}

int main() {
  char s1[] = {"leet2code3"}, s2[] = {"ha22"},
       s3[] = {"a2345678999999999999999"};
  printf("%s\n", decodeAtIndex(s1, 10)); // expect: o
  printf("%s\n", decodeAtIndex(s2, 5));  // expect: h
  printf("%s\n", decodeAtIndex(s3, 1));  // expect: a
}
