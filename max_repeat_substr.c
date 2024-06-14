// 1668. Maximum Repeating Substring
#include "leetcode.h"

/*
 * for a string 'sequence', a string 'word' is 'k'-repeating if 'word'
 * concatenated 'k' times is a substring of 'sequence'. the 'word's maximum
 * 'k'-repeating value is the highest value 'k' where 'word' is 'k'-repeating in
 * 'sequence'. if 'word' is not a substring of 'sequence', 'word's maximum
 * 'k'-repeating value is 0. given strings 'sequence' and 'word', return the
 * maximum 'k'-repeating value of 'word' in 'sequence'.
 */

int maxRepeating(char *sequence, char *word) {
  int idx = 0, n = strlen(sequence), m = strlen(word), max = 0, cnt = 0;
  for (int i = 0; i < n; i++) {
    if (strncmp(&sequence[i], word, m))
      continue;
    else {
      cnt = 1;
      for (int k = i + m; i < n; k += m) {
        if (strncmp(&sequence[k], word, m))
          break;
        else
          cnt++;
      }
      max = fmax(max, cnt);
    }
  }
  return max;
}

int main() {
  char *s1 = "ababc", *w1 = "ab";
  char *s2 = "ababc", *w2 = "ba";
  char *s3 = "ababc", *w3 = "ac";
  printf("%d\n", maxRepeating(s1, w1)); // expect: 2
  printf("%d\n", maxRepeating(s2, w2)); // expect: 1
  printf("%d\n", maxRepeating(s3, w3)); // expect: 0
}
