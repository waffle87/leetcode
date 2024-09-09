// 2326. Spiral Matrix IV
#include "leetcode.h"

/*
 * you are given two integer 'm' and 'n', which represent the dimensions of a
 * matrix. you are also given the 'head' of a linked list of integers. generate
 * an 'm * n' matrix that contains the integers in the linked list presented in
 * spiral order (clockwise) starting from the top left of the matrix. if there
 * are remaining spaces, fill them with -1. return the generated matrix.
 */

int **spiralMatrix(int m, int n, struct ListNode *head, int *returnSize,
                   int **returnColumnSizes) {
  *returnSize = m;
  *returnColumnSizes = (int *)calloc(m, sizeof(int));
  int **ans = (int **)calloc(m, sizeof(int *));
  for (int i = 0; i < m; i++) {
    (*returnColumnSizes)[i] = n;
    ans[i] = (int *)calloc(n, sizeof(int));
    memset(ans[i], -1, n * sizeof(int));
  }
  int start_row = 0, start_col = 0, end_row = 0, end_col = 0;
  while (head) {
    for (int col = start_col; col < end_col && head; col++) {
      ans[start_row][col] = head->val;
      head = head->next;
    }
    start_row++;
    for (int row = start_row; row < end_row && head; row++) {
      ans[row][end_col - 1] = head->val;
      head = head->next;
    }
    end_col--;
    if (start_row < end_row) {
      for (int col = end_col - 1; col >= start_col && head; col--) {
        ans[end_row - 1][col] = head->val;
        head = head->next;
      }
      end_row--;
    }
    if (start_col < end_col) {
      for (int row = end_row - 1; row >= start_row && head; row--) {
        ans[row][start_col] = head->val;
        head = head->next;
      }
      start_col++;
    }
  }
  return ans;
}

int main() {
  struct ListNode *head = listnode_create(0);
  head->next = listnode_create(1);
  head->next->next = listnode_create(2);
  int returnSize, **returnColumnSizes;
  int **sm = spiralMatrix(1, 4, head, &returnSize, returnColumnSizes);
  for (int i = 0; i < returnSize; i++) {
    for (int j = 0; j < returnColumnSizes[i]; j++)
      printf("%d ", sm[i][j]);
    printf("\n");
  }
  for (int i = 0; i < returnSize; i++)
    free(sm[i]);
  free(sm);
}
