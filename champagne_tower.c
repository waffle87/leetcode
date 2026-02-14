// 799. Champagne Tower
#include "leetcode.h"

/*
 * we stack glasses in a pyramid, where the first row has 1 glass, the second
 * row has 2 glasses, and so on until the 100th row. each glass holds one cup of
 * champagne. then, some champagne is poured into the first glass at the top.
 * when the topmost glass is full, any excess liquid poured will fall equally to
 * the glass immediately to the right and left of it. when those glasses become
 * full, any excess champange will fall equally to the left and right of those
 * glasses, and so on. (a glass at the bottom row has its excess champagne fall
 * on the floor). for example, after one cup of champagne is poured, the top
 * most glass is full. after cups of champagne is poured, the two glasses on the
 * second row are half full. after three cups are poured, those two cups become
 * full - there are three glasses total full now. now after pouring some
 * non-negative integer cups of champagne, return how full the j'th glass in the
 * i'th row is.
 */

double champagneTower(int poured, int query_row, int query_glass) {
  double flow[102][102] = {0.0};
  flow[0][0] = (double)poured;
  for (int r = 0; r <= query_row; ++r) {
    for (int c = 0; c <= r; ++c) {
      double q = (flow[r][c] - 1.0) / 2.0;
      if (q > 0) {
        flow[r + 1][c] += q;
        flow[r + 1][c + 1] += q;
      }
    }
  }
  return fmin(1.0, flow[query_row][query_glass]);
}

int main() {
  double r1 = champagneTower(1, 1, 1);
  double r2 = champagneTower(2, 1, 1);
  double r3 = champagneTower(100000009, 33, 17);
  printf("%f\n", r1); // expect: 0.00000
  assert(r1 == 0.00000);
  printf("%f\n", r2); // expect: 0.50000
  assert(r2 == 0.50000);
  printf("%f\n", r3); // expect: 1.00000
  assert(r3 == 1.00000);
}
