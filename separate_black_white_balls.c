// 2938. Separate Black and White Balls
#include "leetcode.h"

/*
 * there are 'n' balls on a table, each ball has a colour black or white. you
 * are given a 0-indexed binary string 's' of length 'n', where 1 and 0
 * represent black and white balls respectively. in each step, you can choose
 * two adjacent balls and swap them. return the minimum number of steps to group
 * all the black balls to the right and all the white balls to the left
 */

long long minimumSteps(char *s) {
  long long one_cnt = 0, swap_cnt = 0;
  for (int i = 0; s[i] != '\0'; i++) {
    if (s[i] == '1')
      one_cnt++;
    else
      swap_cnt += one_cnt;
  }
  return swap_cnt;
}

int main() {
  char *s1 = "101", *s2 = "100";
  printf("%lld\n", minimumSteps(s1)); // expect: 1
  printf("%lld\n", minimumSteps(s2)); // expect: 2
}
