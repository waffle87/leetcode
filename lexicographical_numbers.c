// 386. Lexicographical Numbers
#include "leetcode.h"

/*
 * given an integer 'n', return all the numbers in the range '[1, n]' sorted in
 * lexicographical order. you must write an algorithm that runs in O(n) time
 * complexity and uses O(1) extra space.
 */

void lex(int *res, int n, int i, int digit, int *k) {
  if (!digit)
    return;
  for (int j = i * 10; j < (i + 1) * 10 && j <= n; j++) {
    res[(*k)++] = j;
    lex(res, n, j, digit - 1, k);
  }
}

int *lexicalOrder(int n, int *returnSize) {
  int *ans = (int *)malloc((n + 1) * sizeof(int));
  int tmp = n, max_digit = 0, k = 0;
  while (tmp) {
    tmp /= 10;
    max_digit++;
  }
  for (int i = 1; i < 10 && i <= n; i++) {
    ans[k++] = i;
    lex(ans, n, i, max_digit, &k);
  }
  *returnSize = k;
  return ans;
}

int main() {
  int rs1, rs2;
  int *lo1 = lexicalOrder(13, &rs1), *lo2 = lexicalOrder(2, &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", lo1[i]); // expect: [1,10,11,12,13,2,3,4,5,6,7,8,9]
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", lo2[i]); // expect: [1,2]
  printf("\n");
  free(lo1), free(lo2);
}
