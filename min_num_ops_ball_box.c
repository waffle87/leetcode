// 1769. Minimum Number of Operations to Move All Balls to Each Box
#include "leetcode.h"

/*
 * you have 'n' boxes. you are given a binary string 'boxes' of length 'n' where
 * 'boxes[i]' is '0' if the i'th box is empty, and '1' if it contains one ball.
 * in one operation, you can move one ball from a box to an adjacent box. box
 * 'i' is adjacent to box 'j' if 'abs(i - j) == 1'. note that after doing so,
 * there may be more than one ball in some boxes. return an array 'answer' of
 * size 'n' where 'answer[i]' is the minimum number of operations needed to move
 * all the balls to i'th box.
 */

int *minOperations(char *boxes, int *returnSize) {
  int n = strlen(boxes), steps;
  int *ans = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    steps = 0;
    for (int j = 0; j < n; j++)
      if (boxes[j] == '1')
        steps += abs(i - j);
    ans[i] = steps;
  }
  *returnSize = n;
  return ans;
}

int main() {
  char *b1 = "110", *b2 = "001011";
  int rs1, *mo1 = minOperations(b1, &rs1);
  int rs2, *mo2 = minOperations(b2, &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", mo1[i]); // expect: 1 1 3
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", mo2[i]); // expect: 11 8 5 4 3 4
  printf("\n");
  free(mo1), free(mo2);
}
