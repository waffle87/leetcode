// 765. Couples Holding Hands
#include <stdio.h>
#include <stdlib.h>

/*
 * there are 'n' couples sitting '2n' seats arranged in a row and want to hold
 * hands. the people and seats are represented by an integer array 'row' where
 * 'row[i]' is the id of the person sitting in the i'th seat. the couples are
 * numbered in order, the first couple being '(0, 1)', the second couple being
 * '(2, 3)', and so on with the last couple being '(2n -2, 2n -1)'. return the
 * minimum number of swaps so that every couple is sitting side by side. a swap
 * consists of choosing any two people then they stand up and switch seats.
 */

int minSwapsCouples(int *row, int row_size) {
  int pair[60], position[60], cnt = 0;
  for (int i = 0; i < 60; i += 2) {
    pair[i] = i + 1;
    pair[i + 1] = i;
  }
  for (int i = 0; i < row_size; i++)
    position[row[i]] = i;
  for (int i = 0; i < row_size; i += 2) {
    if (row[i + 1] != pair[row[i]]) {
      cnt++;
      int pos = position[pair[row[i]]];
      position[row[i + 1]] = pos;
      int tmp = row[pos];
      row[pos] = row[i + 1];
      row[i + 1] = tmp;
      position[pair[row[i]]] = i + 1;
    }
  }
  return cnt;
}

int main() {
  int r1[] = {0, 2, 1, 3}, r2[] = {3, 2, 0, 1};
  printf("%d\n", minSwapsCouples(r1, 4)); // expect: 1
  printf("%d\n", minSwapsCouples(r2, 4)); // expect: 0
}
