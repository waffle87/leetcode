// 386. Lexicographical Numbers
#include "leetcode.h"

/*
 * given an integer 'n', return all the numbers in the range '[1, n]' sorted in
 * lexicographical order. you must write an algorithm that runs in O(n) time
 * complexity and uses O(1) extra space.
 */

int *lexicalOrder(int n, int *returnSize) {
  int *ans = (int *)malloc(n * sizeof(int));
  int curr = 1, k = 0;
  for (int i = 0; i < n; i++) {
    ans[i] = curr;
    if (((curr << 3) + (curr << 1)) <= n)
      curr = (curr << 3) + (curr << 1);
    else {
      if (curr >= n)
        curr /= 10;
      curr++;
      while (!(curr % 10))
        curr /= 10;
    }
  }
  *returnSize = n;
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
