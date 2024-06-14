// 688. Knight Probability in Chessboard
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * on an 'n x n' chessboard, a knight starts at the cell '(row, column)' and
 * attempts to make exactly 'k' moves. the rows and columns are 0-indexed, so
 * the top-left cell is '(0, 0)', and the bottom-right cell is '(n - 1, n - 1)'.
 * a chess knight has eight possible moves it can make, as illustrated below
 * [see image]. each move is two cells in a cardinal direction, then one cell in
 * an orthogonal direction.
 */

bool in_bound(int row, int col, int n) {
  return 0 <= row && row < n && col >= 0 && col < n;
}

double knightProbability(int n, int k, int row, int col) {
  double **a = (double **)malloc(sizeof(double *) * n);
  double **b = (double **)malloc(sizeof(double *) * n);
  for (int i = 0; i < n; i++) {
    a[i] = (double *)malloc(sizeof(double) * n);
    b[i] = (double *)malloc(sizeof(double) * n);
    for (int j = 0; j < n; j++) {
      a[i][j] = 0;
      b[i][j] = 0;
    }
  }
  static int dr[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
  static int dc[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
  a[row][col] = 1;
  double **to = a;
  double **from = NULL;
  for (int step = 1; step <= k; step++) {
    to = ((step % 2) != 0 ? b : a);
    from = ((step % 2) != 0 ? a : b);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        to[i][j] = 0;
        for (int l = 0; l < 8; l++) {
          to[i][j] += in_bound(i + dr[l], j + dc[l], n)
                          ? from[i + dr[l]][j + dc[l]] / 8
                          : 0;
        }
      }
    }
  }
  double ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      ans += to[i][j];
  for (int i = 0; i < n; i++)
    free(a[i]), free(b[i]);
  free(a), free(b);
  return ans;
}

int main() {
  printf("%f\n", knightProbability(3, 2, 0, 0)); // expect: 0.06250
  printf("%f\n", knightProbability(1, 0, 0, 0)); // expect: 1.00000
}
