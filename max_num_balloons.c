// 1189. Maximum Number of Balloons
#include "leetcode.h"

/*
 * given a string 'text', you want to use the characters of 'text' to form as
 * many instances of the word "balloon" as possible. you can use each character
 * in 'text' at most once. return the maximum number of instances that can be
 * formed.
 */

int maxNumberOfBalloons(char *text) {
  int freq[5] = {0};
  char *s = "balon";
  for (int i = 0; text[i]; i++)
    for (int j = 0; j < 5; j++)
      freq[j] += (text[i] == s[j]);
  int min = freq[0];
  min = fmin(min, freq[1]);
  min = fmin(min, freq[2] >> 1);
  min = fmin(min, freq[3] >> 1);
  min = fmin(min, freq[4]);
  return min;
}

int main() {
  char *t1 = "nlaebolko";
  char *t2 = "loonbalxballpoon";
  char *t3 = "leetcode";
  int r1 = maxNumberOfBalloons(t1);
  int r2 = maxNumberOfBalloons(t2);
  int r3 = maxNumberOfBalloons(t3);
  printf("%d\n", r1);
  assert(r1 == 1);
  printf("%d\n", r2);
  assert(r2 == 2);
  printf("%d\n", r3);
  assert(r3 == 0);
}
