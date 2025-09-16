// 2197. Replace Non-Coprime Numbers in Array
#include "leetcode.h"

/*
 * you are given an array of integers 'nums'. perform the following steps: find
 * any two adjacent numbers in 'nums' that are non-coprime, if no such numbers
 * are found, stop the process. otherwise, delete the two numbers and replace
 * them with their lcm. repeat this process as long as you keep finding two
 * adjacent non-coprime integers. return the final modified array. it can be
 * shown that replacing adjacent non-coprime numbers in any arbitrary order will
 * lead to the same result. two values 'x' and '' aree non-coprime if 'gcd(x, y)
 * > 1' where 'gcd(x, y)' is the greatest common denomiator
 */

int gcd(int a, int b) {
  while (b != 0) {
    int tmp = b;
    b = a % b;
    a = tmp;
  }
  return a;
}

int *replaceNonCoprimes(int *nums, int numsSize, int *returnSize) {
  int *ans = (int *)malloc(numsSize * sizeof(int)), top = 0;
  for (int i = 0; i < numsSize; i++) {
    int curr = nums[i];
    while (top > 0) {
      int prev = ans[top - 1];
      int g = gcd(prev, curr);
      if (g == 1)
        break;
      top--;
      long long merged = (long long)prev / g * curr;
      curr = (int)merged;
    }
    ans[top++] = curr;
  }
  *returnSize = top;
  return ans;
}

int main() {
  int n1[] = {6, 4, 3, 2, 7, 6, 2}, rs1;
  int n2[] = {2, 2, 1, 1, 3, 3, 3}, rs2;
  int *rnc1 = replaceNonCoprimes(n1, ARRAY_SIZE(n1), &rs1);
  int *rnc2 = replaceNonCoprimes(n2, ARRAY_SIZE(n2), &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", rnc1[i]); // expect: 12 7 6
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", rnc2[i]); // expect: 2 1 1 3
  printf("\n");
  free(rnc1);
  free(rnc2);
}
