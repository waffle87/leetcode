// 1769. Minimum Number of Operations to Move All Balls to Each Box
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *minOperations(char *boxes, int *returnSize) {
  int len = strlen(boxes), steps;
  int *ans = malloc(len * sizeof(int));
  for (int i = 0; i < len; i++) {
    steps = 0;
    for (int j = 0; j < len; j++)
      if (boxes[j] == '1')
        steps += abs(i - j);
    ans[i] = steps;
  }
  *returnSize = len;
  return ans;
}

int main() {
  char boxes1[] = {"110"}, boxes2[] = {"001011"};
  int rs1[] = {3}, rs2[] = {6};
  printf("%c\n", *minOperations(boxes1, rs1)); // expect: 1,1,3
  printf("%c\n", *minOperations(boxes2, rs2)); // expect: 11,8,5,4,3,4
}
