// 1894. Find the Student that Will Replace the Chalk
#include "leetcode.h"

/*
 * there are 'n' students in a class numbered from 0 to 'n - 1'. the teacher
 * will give each student a problem starting with the student number 0, then the
 * student number 1, and so on until the teach reaches the student number 'n -
 * 1'. after that the teach will restart the processes, starting with the
 * student number 0 again. you are given a 0-indexed integer array 'chalk' and
 * an integer 'k'. there are initially 'k' pieces of chalk. when the student
 * number 'i' is given a problem to solve, they will use 'chalk[i]' pieces of
 * chalk to solve that problem. however, if the current number of chalk pieces
 * is strictly less than 'chalk[i]', then the student number 'i' will be asked
 * to replace the chalk. return the index of the student that will replace the
 * chalk pieces.
 */

int chalkReplacer(int *chalk, int chalkSize, int k) {
  int sum = 0;
  for (int i = 0; i < chalkSize; i++)
    sum += chalk[i];
  int rem = k % sum;
  for (int i = 0; i < chalkSize; i++) {
    rem -= chalk[i];
    if (rem < 0)
      return i;
  }
  return -1;
}

int main() {
  int c1[] = {5, 1, 5}, c2[] = {3, 4, 1, 2};
  printf("%d\n", chalkReplacer(c1, ARRAY_SIZE(c1), 22)); // expect: 0
  printf("%d\n", chalkReplacer(c2, ARRAY_SIZE(c2), 25)); // expect: 1
}
