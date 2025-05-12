// 2094. Finding 3-Digit Even Numbers
#include "leetcode.h"

/*
 * you are given an integer 'digits' where each element is a digit. the array
 * may contain duplicates. you need to find all the unique integers that follow
 * the given requirements: the integer consists of the concatenation of three
 * elements from 'digits' in any arbitrary order, the integer does not have
 * leading zeros, and the integer is even. for example, if the given 'digits'
 * were '[1, 2, 3]' integers '132' and '312' follow the requirments. return a
 * sorted array of the unique integers.
 */

int *findEvenNumbers(int *digits, int digitsSize, int *returnSize) {
  int hash[10] = {0};
  for (int i = 0; i < digitsSize; i++)
    hash[digits[i]]++;
  int *ans = (int *)malloc(sizeof(int));
  *returnSize = 0;
  int idx = 0;
  for (int i = 100; i < 999; i += 2) {
    int cnt[10] = {0}, tmp = i;
    bool flag = true;
    while (tmp) {
      cnt[tmp % 10]++;
      tmp /= 10;
    }
    for (int j = 0; j < 10; j++)
      if (cnt[j] > hash[j]) {
        flag = false;
        break;
      }
    if (flag) {
      (*returnSize)++;
      ans = (int *)realloc(ans, (*returnSize) * sizeof(int));
      ans[idx++] = i;
    }
  }
  return ans;
}

int main() {
  int d1[] = {2, 1, 3, 0}, d2[] = {2, 2, 8, 8, 2}, d3[] = {3, 7, 5};
  int rs1, *fen1 = findEvenNumbers(d1, ARRAY_SIZE(d1), &rs1);
  int rs2, *fen2 = findEvenNumbers(d2, ARRAY_SIZE(d2), &rs2);
  int rs3, *fen3 = findEvenNumbers(d3, ARRAY_SIZE(d3), &rs3);
  for (int i = 0; i < rs1; i++)
    printf("%d ", fen1[i]); // expect: 102,120,130,132,210,230,302,310,312,320
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", fen2[i]); // expect: 222,228,282,288,822,828,882
  printf("\n");
  for (int i = 0; i < rs3; i++)
    printf("%d ", fen3[i]); // expect: null
  printf("\n");
  free(fen1);
  free(fen2);
  free(fen3);
}
