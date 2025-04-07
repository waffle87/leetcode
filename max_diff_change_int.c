// 1432. Max Difference You Can Get From Changing an Integer
#include "leetcode.h"

/*
 * you are given an integer 'num'. you will apply the following steps exactly
 * two times: pick a digit 'x (0 <= x <= 9)', pick another digit 'y (0 <= y <=
 * 9)'. the digit 'y' can be equal to 'x'. replace all occurences of 'x' in the
 * decimal representation of 'num' by 'y'. the new integer cannot have any
 * leading zeros. also the new integer cannot be 0. let 'a' and 'b' be the
 * results of applying the operations to 'num' the first and second times
 * respectively. return the max difference between 'a' and 'b'.
 */

int maxDiff(int num) {
  char order[10], x, y;
  sprintf(order, "%d", num);
  int i;
  for (i = 0; order[i] && order[i] == '9'; i++)
    ;
  if (order[i]) {
    x = order[i];
    for (; order[i]; i++)
      if (order[i] == x)
        order[i] = '9';
  }
  int a = atoi(order);
  sprintf(order, "%d", num);
  for (i = 0; order[i] && (order[i] == '0' || order[i] == '1'); i++)
    ;
  if (order[i]) {
    x = order[i];
    y = (order[0] != '1') + '0';
    for (; order[i]; i++)
      if (order[i] == x)
        order[i] = y;
  }
  int b = atoi(order);
  return a - b;
}

int main() {
  printf("%d\n", maxDiff(555)); // expect: 888
  printf("%d\n", maxDiff(9));   // expect: 8
}
