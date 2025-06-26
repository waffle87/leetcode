// 728. Self Dividing Numbers
#include "leetcode.h"

/*
 * a self-dividing number is a number that is divisible by every digit it
 * contains. for example, 128 is a self-dividing number because 128 % 1 == 0,
 * 128 % 2 == 0, and 128 % 8 == 0. a self-dividing number is not allowed to
 * contain the digit zero. given two integers 'left' and 'right', return a list
 * of all the self-dividing numbers in the range '[left, right]' (both
 * inclusive).
 */

int *selfDividingNumbers(int left, int right, int *returnSize) {
  int tracker, curr, digit;
  bool valid;
  int *ans = (int *)malloc((right - left + 1) * sizeof(int));
  *returnSize = 0;
  for (int i = left; i <= right; i++) {
    curr = i;
    valid = true;
    tracker = 0;
    while (curr > 0) {
      if (i < 10)
        break;
      digit = curr % 10;
      curr /= 10;
      if (!digit)
        valid = false;
      else if (digit > 1 && !(tracker & (1 << digit))) {
        valid = !(i % digit);
        tracker |= (1 << digit);
      }
      if (!valid)
        break;
    }
    if (valid)
      ans[(*returnSize)++] = i;
  }
  return ans;
}

int main() {
  int rs1, *sdn1 = selfDividingNumbers(1, 22, &rs1);
  int rs2, *sdn2 = selfDividingNumbers(47, 85, &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", sdn1[i]); // expect: [1,2,3,4,5,6,7,8,9,11,12,15,22]
  printf("\n");
  for (int i = 0; i < rs1; i++)
    printf("%d ", sdn2[i]); // expect: [48,55,66,77]
  printf("\n");
  free(sdn1);
  free(sdn2);
}
