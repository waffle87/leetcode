// 3000. Maximum Area of Longest Diagonal Rectangle
#include "leetcode.h"

/*
 * you are given a 2d 0-indexed integer array 'dimensions'. for all indices 'i',
 * '0 <= i < dimensions.size', 'dimensions[i][0]' represents the length and
 * 'dimensions[i][1]' represents the width of the rectangle 'i'. return the area
 * of the rectangle having the longest diagonal, return the area of the
 * rectangle having the maximum area.
 */

int areaOfMaxDiagonal(int **dimensions, int dimensionsSize,
                      int *dimensionsColSize) {
  int ans = 0, max = 0;
  for (int i = 0; i < dimensionsSize; i++) {
    int l = dimensions[i][0], w = dimensions[i][1];
    int curr = l * l + w * w;
    if (curr > max || (curr == max && l * w > ans)) {
      max = curr;
      ans = l * w;
    }
  }
  return ans;
}

int main() {
  int d1i[2][2] = {{9, 3}, {8, 6}}, d2i[2][2] = {{3, 4}, {4, 3}};
  struct two_d_arr d1, d2;
  two_d_arr_init(&d1, ARRAY_SIZE(d1i), ARRAY_SIZE(d1i[0]), d1i);
  two_d_arr_init(&d2, ARRAY_SIZE(d2i), ARRAY_SIZE(d2i[0]), d2i);
  printf("%d\n",
         areaOfMaxDiagonal(d1.arr, d1.row_size, d1.col_size)); // expect: 48
  printf("%d\n",
         areaOfMaxDiagonal(d2.arr, d2.row_size, d2.col_size)); // expect: 12
  two_d_arr_free(&d1);
  two_d_arr_free(&d2);
}
