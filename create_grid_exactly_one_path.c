// 3963. Create Grid With Exactly One Path
#include "leetcode.h"

/*
 * you are given two integers 'n' and 'm' representing the number of rows and
 * columns of a grid. construct any 'm x n' grid consisting of the characters
 * '.' and '#' where '.' represents a free cell, and '#' represents an obstacle
 * cell. a valid path is a sequence of free cells that starts at the top left
 * cell and ends att the bottom right cell. return any grid such that there is
 * exactly one valid path from the top left cell to the bottom right cell.
 */

char **createGrid(int m, int n, int *returnSize) {
  char **ans = (char **)calloc(m, sizeof(char *));
  *returnSize = m;
  ans[0] = (char *)calloc(n + 1, sizeof(char));
  memset(ans[0], '.', n * sizeof(char));
  for (int i = 1; i < m; i++) {
    ans[i] = calloc(n + 1, sizeof(char));
    memset(ans[i], '#', n * sizeof(char));
    ans[i][n - 1] = '.';
  }
  return ans;
}

int main() {
  int rs1, rs2, rs3;
  char *r1[] = {"..#", "#.."};
  char *r2[] = {"..#", "#..", "##."};
  char *r3[] = {"...."};
  char **cg1 = createGrid(2, 3, &rs1);
  char **cg2 = createGrid(3, 3, &rs2);
  char **cg3 = createGrid(1, 4, &rs3);
  for (int i = 0; i < rs1; i++) {
    printf("%s ", cg1[i]);
    assert(!strcmp(r1[i], cg1[i]));
  }
  printf("\n");
  for (int i = 0; i < rs2; i++) {
    printf("%s ", cg2[i]);
    assert(!strcmp(r2[i], cg2[i]));
  }
  printf("\n");
  for (int i = 0; i < rs3; i++) {
    printf("%s ", cg3[i]);
    assert(!strcmp(r3[i], cg3[i]));
  }
  printf("\n");
  for (int i = 0; i < rs1; i++)
    free(cg1[i]);
  free(cg1);
  for (int i = 0; i < rs2; i++)
    free(cg2[i]);
  free(cg2);
  for (int i = 0; i < rs3; i++)
    free(cg3[i]);
  free(cg3);
}
