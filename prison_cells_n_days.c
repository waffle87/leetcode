// 957. Prison Cells After N Days
#include "leetcode.h"

/*
 * there are 8 prison cells in a row and each cell is either occupied or vacant.
 * each day, whether the cell is occupied or vacant changes according to the
 * following rules: if a cell has two adjacent neighbours that are both occupied
 * or both vacant, then the cell becomes occupied, otherwise it becomes vacant.
 * note that because the prison is a row, the first and the last cells in the
 * row can't have two adjacent neighbours. you are given an integer array
 * 'cells' where 'cells[i] == 1' if the i'th cell is occupied and 'cells[i] ==
 * 0' if the i'th cell is vacant, and you are given an integer 'n'. return the
 * state of the prison after 'n' days (ie. 'n' such changes desribed above)
 */

int *prisonAfterNDays(int *cells, int cellsSize, int n, int *returnSize) {
  *returnSize = cellsSize;
  int state = 0;
  for (int i = 0; i < cellsSize; i++)
    if (cells[i])
      state |= 1 << (7 - i);
  n = (n % 14) + 14;
  for (int i = 0; i < n; i++) {
    int clear = 0, set = 0;
    for (int j = 1; j < 7; j++) {
      int low = (1 << (8 - j)), high = (1 << (6 - j));
      if (((low & state) == low && (high & state) == high) ||
          (!(low & state) && !(high & state)))
        set |= 1 << (7 - j);
      else
        clear |= 1 << (7 - j);
    }
    state &= ~0x81;
    state &= ~clear;
    state |= set;
  }
  int *ans = (int *)calloc(cellsSize, sizeof(int));
  for (int i = 0; i < cellsSize; i++)
    if (1 << (7 - i) & state)
      ans[i] = 1;
  return ans;
}

int main() {
  int c1[] = {0, 1, 0, 1, 1, 0, 0, 1}, c2[] = {1, 0, 0, 1, 0, 0, 1, 0}, rs1,
      rs2;
  int *pand1 = prisonAfterNDays(c1, ARRAY_SIZE(c1), 7, &rs1);
  int *pand2 = prisonAfterNDays(c2, ARRAY_SIZE(c2), 1000000000, &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", pand1[i]); // expect: [0,0,1,1,0,0,0,0]
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", pand2[i]); // expect: [0,0,1,1,1,1,1,0]
  printf("\n");
  free(pand1), free(pand2);
}
