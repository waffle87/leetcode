// 2579. Count Total Number of Colored Cells
#include "leetcode.h"

/*
 * there exists an infinitely large two-dimensional grid of uncoloured unit
 * cells. you are given a positive integer 'n', indicating that you must do the
 * following routine for 'n' minutes: at the first minute, colour any arbitrary
 * unit cell blue, and every minute thereafter, colour blue every uncoloured
 * cell that touches a blue cell.
 */

long long coloredCells(int n) { return 2L * n * (n - 1) + 1; }

int main() {
  printf("%lld\n", coloredCells(1)); // expect: 1
  printf("%lld\n", coloredCells(2)); // expect: 5
}
