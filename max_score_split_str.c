// 1422. Maximum Score After Splitting a String
#include "leetcode.h"

/*
 * given a string 's' of zeros and ones, return the maximum score after
 * splitting the string into two non-empty substrings (ie. left and right). the
 * score after splitting a string is the number of zeros in the left substring
 * plus the number of ones in the right substring.
 */

int maxScore(char *s) {
  int ones = 0, tmp = s[0] == '0' ? 1 : 0, score = tmp;
  for (int i = 1; i < strlen(s) - 1; ++i) {
    if (s[i] == '0')
      tmp++;
    else {
      ones++;
      tmp--;
    }
    if (tmp > score)
      score = tmp;
  }
  ones += s[strlen(s) - 1] == '1' ? 1 : 0;
  return ones + score;
}

int main() {
  char *s1 = "011101", *s2 = "00111", *s3 = "1111";
  printf("%d\n", maxScore(s1)); // expect: 5
  printf("%d\n", maxScore(s2)); // expect: 5
  printf("%d\n", maxScore(s3)); // expect: 3
}
