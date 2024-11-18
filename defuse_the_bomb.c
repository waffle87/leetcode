// 1652. Defuse the Bomb
#include "leetcode.h"

/*
 * you have a bomb to defuse, and your time is running out. your informer will
 * provide you with a circular array 'code' of length 'n' and key 'k'. to
 * decrypt the code, you must replace every number. all the numbers are replace
 * simultaneously. if 'k > 0', replace the i'th number with the sum of the next
 * 'k' numbers. if 'k < 0', replace the i'th number with the sum of the previous
 * 'k' numbers. if 'k == 0', replace the i'th number with 0. as 'code' is
 * circular, the next element of 'code[n - 1]' is 'code[0]' and the previous
 * element of 'code[0]' is 'code[n - 1]'. given the circular array 'code' and an
 * integer 'k', return the decrypted code to defuse the bomb
 */

int *decrypt(int *code, int codeSize, int k, int *returnSize) {
  int *ans = (int *)malloc(codeSize * sizeof(int)), n, sum;
  if (k)
    for (int i = 0; i < codeSize; i++) {
      for (int j = 1; j <= k; j++) {
        n = code[(i + j) % codeSize];
        sum += n;
      }
      ans[i] = sum;
      n = sum = 0;
    }
  else if (!k)
    for (int i = 0; i < codeSize; i++)
      ans[i] = 0;
  else
    for (int i = 0; i < codeSize; i++) {
      for (int j = 1; j <= abs(k); j++) {
        n = code[(i + codeSize - j) % codeSize];
        sum += n;
      }
      ans[i] = sum;
      n = sum = 0;
    }
  *returnSize = codeSize;
  return ans;
}

int main() {
  int c1[] = {5, 7, 1, 4}, c2[] = {1, 2, 3, 4}, c3[] = {2, 4, 9, 3};
  int rs1, rs2, rs3;
  int *d1 = decrypt(c1, ARRAY_SIZE(c1), 3, &rs1);
  int *d2 = decrypt(c2, ARRAY_SIZE(c2), 0, &rs2);
  int *d3 = decrypt(c3, ARRAY_SIZE(c3), -2, &rs3);
  for (int i = 0; i < rs1; i++)
    printf("%d ", d1[i]); // expect: 12 10 16 13
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", d2[i]); // expect: 0 0 0 0
  printf("\n");
  for (int i = 0; i < rs3; i++)
    printf("%d ", d3[i]); // expect: 12 5 6 13
  printf("\n");
  free(d1), free(d2), free(d3);
}
