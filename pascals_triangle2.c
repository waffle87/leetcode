// 119. Pascal's Triangle II
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * given an integer 'row_index', return the 'row_index'th row of the pascals
 * triangle. in pascals triangle, each number is the sum of the two numbers
 * directly above it as shown.
 */

int *getRow(int row_index, int *return_size) {
  uint val[34];
  memset(val, 0, sizeof(val));
  val[0] = 1;
  *return_size = row_index + 1;
  for (int i = 0; i < row_index; ++i) {
    int prev = 1, j;
    const int total = row_index + 1, half = total / 2;
    for (j = 1; j < half; ++j) {
      val[j] = prev + val[j];
      prev = val[j] - prev;
      val[total - j - 1] = val[j];
    }
    if (total & 1)
      val[j] = prev + val[j];
    val[total - 1] = 1;
  }
  return val;
}

int main() {
  int rs1[] = {}, rs2[] = {}, rs3[] = {};
  int *gr1 = getRow(3, rs1);
  int *gr2 = getRow(0, rs2);
  int *gr3 = getRow(1, rs3);
  for (int i = 0; i < 4; i++)
    printf("%d ", gr1[i]); // expect: 1 3 3 1
  printf("\n");
  for (int i = 0; i < 1; i++)
    printf("%d ", gr2[i]); // expect: 1
  printf("\n");
  for (int i = 0; i < 2; i++)
    printf("%d ", gr3[i]); // expect: 1 1
  printf("\n");
}
