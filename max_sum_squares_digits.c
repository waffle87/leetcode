// 3723. Maximize Sum of Squares of Digits
#include "leetcode.h"

/*
 * you are given two positive integers 'num' and 'sum'. a positive integer 'n'
 * is good if it satisfies both of the following: the number of digits in 'n' is
 * exactly 'num', and the sum of digits in 'n' is exactly 'sum'. return a string
 * denoting the good integer 'n' that achieves the maximum score
 */

char *maxSumOfSquares(int num, int sum) {
  if (num * 9 < sum)
    return "";
  char *ans = (char *)malloc((num + 1) * sizeof(char));
  memset(ans, '0', num * sizeof(char));
  ans[num] = '\0';
  int i = 0;
  for (int j = sum / 9; i != j; ++i)
    ans[i] = '9';
  if (i == num)
    return ans;
  ans[i++] = '0' + sum % 9;
  return ans;
}

int main() {
  char *msos1 = maxSumOfSquares(2, 3), *r1 = "30";
  char *msos2 = maxSumOfSquares(2, 17), *r2 = "98";
  char *msos3 = maxSumOfSquares(1, 10), *r3 = "";
  printf("%s\n", msos1);
  assert(!strcmp(msos1, r1));
  printf("%s\n", msos2);
  assert(!strcmp(msos2, r2));
  printf("%s\n", msos3);
  assert(!strcmp(msos3, r3));
  free(msos1);
  free(msos2);
}
