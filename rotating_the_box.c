// 1861. Rotating the Box
#include "leetcode.h"

/*
 * you are given an 'm x n' matrix of characters 'box' representing a side-view
 * of a box. each cell of the box is one of the following: a stone '#', a
 * stationary obstacle '*', or empty '.'. the box is rotated 90 degrees
 * clockwise, causing some of the stones to fall due to gravity. each stone
 * falls down until it lands on an obstacle, another stone, or the bottom of the
 * box. gravity does not affect the obstacles' positions and the inertia from
 * the box's rotation does not affect the stones' horizontal positions. return
 * an 'm x n' matrix representing the box after the rotation.
 */

char **rotateTheBox(char **box, int boxSize, int *boxColSize, int *returnSize,
                    int **returnColumnSizes) {
  int n = boxColSize[0];
  *returnSize = n;
  *returnColumnSizes = (int *)malloc(n * sizeof(int));
  char **rotated = (char **)malloc(n * sizeof(char *));
  for (int i = 0; i < n; i++) {
    (*returnColumnSizes)[i] = boxSize;
    rotated[i] = (char *)malloc(boxSize * sizeof(char));
  }
  for (int i = 0; i < boxSize; i++) {
    int idx = boxSize - 1 - i, ceiling = 0, cnt = 0;
    for (int j = 0; j < n; j++) {
      if (box[i][j] == '#')
        cnt++;
      else if (box[i][j] == '*') {
        rotated[j][idx] = '*';
        for (int k = j - cnt; k < j; k++)
          rotated[k][idx] = '#';
        for (int k = ceiling; k < j - cnt; k++)
          rotated[k][idx] = '.';
        cnt = 0, ceiling = j + 1;
      }
    }
    for (int k = n - cnt; k < n; k++)
      rotated[k][idx] = '#';
    for (int k = ceiling; k < n - cnt; k++)
      rotated[k][idx] = '.';
  }
  return rotated;
}

int main() {
  char *b1[] = {"#.#"}, *b2[] = {"#.*.", "##*."},
       *b3[] = {"##*.*.", "###*..", "###.#."};
  int rs1, rs2, rs3, *rcs1, *rcs2, *rcs3;
  int bcs1[] = {3}, bcs2[] = {3, 3}, bcs3[] = {6, 6, 6};
  char **rtb1 = rotateTheBox((char **)b1, 1, bcs1, &rs1, &rcs1);
  char **rtb2 = rotateTheBox((char **)b2, 2, bcs2, &rs2, &rcs2);
  char **rtb3 = rotateTheBox((char **)b3, 3, bcs3, &rs3, &rcs3);
  for (int i = 0; i < rs1; i++)
    for (int j = 0; j < rcs1[i]; j++)
      printf("%c ", rtb1[i][j]);
  printf("\n");
  for (int i = 0; i < rs1; i++)
    for (int j = 0; j < rcs1[i]; j++)
      printf("%c ", rtb1[i][j]);
  printf("\n");
  for (int i = 0; i < rs1; i++)
    for (int j = 0; j < rcs1[i]; j++)
      printf("%c ", rtb1[i][j]);
  printf("\n");
  for (int i = 0; i < rs1; i++)
    free(rtb1[i]);
  free(rtb1), free(rcs1);
  for (int i = 0; i < rs2; i++)
    free(rtb2[i]);
  free(rtb2), free(rcs2);
  for (int i = 0; i < rs3; i++)
    free(rtb3[i]);
  free(rtb3), free(rcs3);
}
