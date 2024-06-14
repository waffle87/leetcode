// 1291. Sequential Digits
#include "leetcode.h"

/*
 * an integer has sequential digits if and only if each digit in the number is
 * one more than the previous digit. return a sorted list of all the integers in
 * the range '[low, high]' inclusive that have sequential digits.
 */

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int *sequentialDigits(int low, int high, int *return_size) {
  int *ans = NULL;
  *return_size = 0;
  for (int i = 1; i <= 9; i++) {
    int num = i;
    for (int j = i + 1; j <= 9; j++) {
      num *= 10 + j;
      if (low <= num && num <= high) {
        (*return_size)++;
        ans = realloc(ans, sizeof(int) * (*return_size));
        ans[(*return_size) - 1] = num;
      }
    }
  }
  if (!ans)
    return NULL;
  qsort(ans, *return_size, sizeof(int), cmp);
  return ans;
}

int main() {
  int rs1[] = {}, rs2[] = {};
  int *sd1 = sequentialDigits(100, 300, rs1);
  int *sd2 = sequentialDigits(1000, 13000, rs2);
  for (int i = 0; i < 2; i++)
    printf("%d ", sd1[i]);
  printf("\n");
  for (int i = 0; i < 7; i++)
    printf("%d ", sd2[i]);
  printf("\n");
  free(sd1), free(sd2);
}
