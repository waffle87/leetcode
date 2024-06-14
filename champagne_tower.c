// 799. Champagne Tower
#include <stdio.h>

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
  double rem[query_row + 1][query_row + 1];
  for (int i = 0; i < query_row; i++)
    for (int j = 0; j < query_row; j++)
      rem[i][j] = 0;
  rem[0][0] = poured;
  for (int i = 1; i <= query_row; i++) {
    rem[i][0] = (rem[i - 1][0] >= 1) ? ((rem[i - 1][0] - 1) * 0.5) : 0;
    rem[i][i] = (rem[i - 1][i - 1] >= 1) ? ((rem[i - 1][i - 1] - 1) * 0.5) : 0;
    for (int j = 1; j < i; j++)
      rem[i][j] =
          ((rem[i - 1][j - 1] >= 1) ? ((rem[i - 1][j - 1] - 1) * 0.5) : 0) +
          ((rem[i - 1][j] >= 1) ? ((rem[i - 1][j] - 1) * 0.5) : 0);
  }
  return (rem[query_row][query_glass] > 1) ? 1 : rem[query_row][query_glass];
}

int main() {
  printf("%f\n", champagneTower(1, 1, 1));           // expect: 0.00000
  printf("%f\n", champagneTower(2, 1, 1));           // expect: 0.50000
  printf("%f\n", champagneTower(100000009, 33, 17)); // expect: 1.00000
}
