// 1232. Check If It Is a Straight Line
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * given an array 'coordinates, coordinates[i] = [x, y]' where '[x, y]'
 * represents the coordinate of a point. check if these points make a straight
 * line in the xy plane
 */

bool checkStraightLine(int **coordinates, int coordinates_size,
                       int *coordinates_col_size) {
  int n = coordinates_size, *x_coords = (int *)malloc(n * sizeof(int)),
      unique_x = 1, unique_slope = 1;
  float *slopes = (float *)malloc((n - 1) * sizeof(float));
  for (int i = 0; i < n; i++)
    x_coords[i] = coordinates[i][0];
  for (int i = 1; i < n; i++)
    if (x_coords[i] != x_coords[0]) {
      unique_x = 0;
      break;
    }
  if (unique_x) {
    free(x_coords);
    free(slopes);
    return true;
  }
  for (int i = 1; i < n; i++)
    slopes[i - 1] = (float)(coordinates[i][1] - coordinates[0][1]) /
                    (coordinates[i][0] - coordinates[0][0]);
  for (int i = 1; i < n - 1; i++)
    if (slopes[i] != slopes[0]) {
      unique_slope = 0;
      break;
    }
  free(x_coords);
  free(slopes);
  return unique_slope;
}

int main() {
  int c1[6][2] = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}}, cs1 = 6,
      *ccs1;
  int c2[6][2] = {{1, 1}, {2, 2}, {3, 4}, {4, 5}, {5, 6}, {7, 7}}, cs2 = 6,
      *ccs2;
  printf("%d\n", checkStraightLine(c1, cs2, ccs1)); // expect: 1
  printf("%d\n", checkStraightLine(c2, cs2, ccs2)); // expect: 0
}
