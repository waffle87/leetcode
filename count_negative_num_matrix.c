// 1351. Count Negative Numbers in a Sorted Matrix
#include <stdio.h>

// given an 'm x n' matrix 'grid' which is sorted in non-increasing order both
// row-wise and column-wise, return the number of negative numbers in 'grid'

void search(int **grid, int grid_size, int row, int start, int end, int *ans) {
  while (start < end) {
    int mid = start + (end - start) / 2;
    if (grid[row][mid] >= 0) {
      start = mid + 1;
      if (grid[row][start] < 0) {
        (*ans) += grid_size - start;
        return;
      }
    } else {
      end = mid;
    }
  }
}

int countNegatives(int **grid, int grid_size, int *grid_col_size) {
  if (grid_size == 1 && grid_col_size[0] == 1)
    return grid[0][0] < 0 ? 1 : 0;
  int r_size = grid_size, c_size = grid_col_size[0], r_idx = 0, ans = 0;
  for (int r = r_size - 1; r >= 0; r--) {
    if (grid[r][0] >= 0) {
      r_idx = r;
      ans = (r_size - r_idx - 1) * c_size;
      break;
    }
  }
  for (int r = 0; r <= r_idx; r++) {
    if (grid[r][c_size - 1] >= 0)
      continue;
    search(grid, c_size, r, 0, c_size - 1, &ans);
  }
  return ans;
}

int main() {
  int g1[4][4] = {
      {4, 3, 2, -1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3}};
  int g2[2][2] = {{3, 2}, {1, 0}};
  int gs1 = 4, gs2 = 2;
  int *gcs1, *gcs2;
  printf("%d\n", countNegatives(g1, gs1, gcs1)); // expect: 8
  printf("%d\n", countNegatives(g2, gs2, gcs2)); // expect: 0
}
