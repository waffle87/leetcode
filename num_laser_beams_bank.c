// 2125. Number of Laser Beams in a Bank
#include "leetcode.h"

/*
 * anti-theft security devices are activated inside a bank. you are given a
 * 0-indexed binary string array 'bank' representing the floor plan of the bank,
 * which is an 'm x n' 2d matrix. 'bank[i]' represents the i'th row, consisting
 * of '0's and '1's. '0' means the cell is empty, while '1' means the cell has a
 * security device. there is one laser beam between any two security devices if
 * both conditions are met. the two devices are located on two different rows
 * 'r1' and 'r2', where 'r1 < r2'. for each row 'i' where 'r1 < i < r2' there
 * are no security devices in the i'th row. laser beams are independent. return
 * the total number of laser beams in the bank.
 */

int numberOfBeams(char **bank, int bankSize) {
  int ans = 0, start = 0;
  for (int i = 0; i < bankSize; i++) {
    int n = 0;
    for (int j = 0;; j++) {
      if (!bank[i][j])
        break;
      else if (bank[i][j] == '1')
        n++;
    }
    if (n) {
      if (start)
        ans += start * n;
      start = n;
    }
  }
  return ans;
}

int main() {
  char *b1[] = {"011001", "000000", "010100", "001000"};
  char *b2[] = {"000", "111", "000"};
  printf("%d\n", numberOfBeams(b1, ARRAY_SIZE(b1))); // expect: 8
  printf("%d\n", numberOfBeams(b2, ARRAY_SIZE(b2))); // expect: 0
}
