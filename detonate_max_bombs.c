// 2101. Detonate the Maximum Bombs
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * given a list of bombs. the range of a bomb is defined as the area where its
 * effect can be felt. this area is in the shape of a circle with the center as
 * the location of the bomb. the bombs are represented by a 0-indexed 2d integer
 * array 'bombs' where 'bombs[i] = [xi, yi, ri]'. 'xi' and 'yi' denote the x and
 * y coordinates of the location of the i'th bomb, whereas 'ri' denotes the
 * radius of its range. you may choose to detonate a single bomb. when a bomb is
 * detonated, it will detonate all the bombs that lie in its range. these bombs
 * will further detonate the bombs that lie in their ranges. given the list of
 * 'bombs', return the max number of bombs that can be detonated
 */

int maximumDetonation(int **bombs, int bombs_size, int *bombs_col_size) {
  bool *check = calloc(bombs_size, sizeof(bool));
  bool **attach = malloc(bombs_size * sizeof(bool *));
  for (int i = 0; i < bombs_size; i++)
    attach[i] = calloc(bombs_size, sizeof(bool));
  for (int i = 0; i < bombs_size; i++) {
    attach[i][i] = true;
    for (int j = i + 1; j < bombs_size; j++) {
      int x = abs(bombs[i][0] - bombs[j][0]);
      int y = abs(bombs[i][1] - bombs[j][1]);
      long long dis = (long long)x * x + (long long)y * y;
      if (dis <= (long long)bombs[i][2] * bombs[i][2])
        attach[i][j] = true;
      if (dis <= (long long)bombs[j][2] * bombs[j][2])
        attach[j][i] = true;
    }
  }
  int *stack1 = malloc(bombs_size * sizeof(int));
  int *stack2 = malloc(bombs_size * sizeof(int));
  int id1 = 0, id2 = 0, max = 1;
  for (int i = 0; i < bombs_size; i++) {
    check = calloc(bombs_size, sizeof(bool));
    int curr = 1;
    check[i] = true;
    stack1[id1] = i;
    id1++;
    while (id1 || id2) {
      if (id1) {
        for (int j = 0; j < id1; j++) {
          int p = stack1[j];
          for (int k = 0; k < bombs_size; k++) {
            if (attach[p][k] && !check[k]) {
              curr++;
              check[k] = true;
              stack2[id2] = k;
              id2++;
            }
          }
        }
        id1 = 0;
      } else {
        for (int j = 0; j < id2; j++) {
          int p = stack2[j];
          for (int k = 0; k < bombs_size; k++) {
            if (attach[p][k] && !check[k]) {
              curr++;
              check[k] = true;
              stack1[id1] = k;
              id1++;
            }
          }
        }
        id2 = 0;
      }
    }
    max = fmax(max, curr);
  }
  return max;
}

int main() {
  int b1[2][3] = {{2, 1, 3}, {6, 1, 4}}, bs1 = 2, *bcs1;
  int b2[2][5] = {{1, 1, 5}, {10, 10, 5}}, bs2 = 2, *bcs2;
  int b3[5][3] = {{1, 2, 3}, {2, 3, 1}, {3, 4, 2}, {4, 5, 3}, {5, 6, 4}},
      bs3 = 5, *bcs3;
  printf("%d\n", maximumDetonation(b1, bs1, bcs1)); // expect: 2
  printf("%d\n", maximumDetonation(b2, bs2, bcs2)); // expect: 1
  printf("%d\n", maximumDetonation(b3, bs3, bcs3)); // expect: 5
}
