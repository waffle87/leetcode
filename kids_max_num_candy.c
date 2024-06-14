// 1431. Kids With the Greatest Number of Candies
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * there are 'n' kids with candies. you are given an integer array 'candies',
 * where each 'candies[i]' represents the number of candies the i'th kid has,
 * and an integer 'extra' denoting the number of extra candies that you have.
 * return a boolean array 'result' of length 'n' where 'result[i]' is 1 if,
 * after giving the i'th kid all the 'extra', they will have the greatest number
 * of candies among all the kids, or 0 otherwise.
 */

bool *kidsWithCandies(int *candies, int candies_size, int extra,
                      int *return_size) {
  *return_size = candies_size;
  bool *ans = (bool *)malloc(candies_size * sizeof(bool));
  int max = candies[0];
  for (int i = 1; i < candies_size; i++)
    max = candies[i] > max ? candies[i] : max;
  for (int i = 0; i < candies_size; i++)
    ans[i] = (candies[i] + extra >= max) ? 1 : 0;
  return ans;
}

int main() {
  int c1[] = {2, 3, 5, 1, 3}, cs1 = 5, e1 = 3, rs1[] = {5};
  int c2[] = {4, 2, 1, 1, 2}, cs2 = 5, e2 = 1, rs2[] = {5};
  int c3[] = {12, 1, 12}, cs3 = 3, e3 = 10, rs3[] = {3};
  bool *kwc1 = kidsWithCandies(c1, cs1, e1, rs1);
  bool *kwc2 = kidsWithCandies(c2, cs2, e2, rs2);
  bool *kwc3 = kidsWithCandies(c3, cs3, e3, rs3);
  for (int i = 0; i < cs1; i++)
    printf("%d ", kwc1[i]); // expect: 1 1 1 0 1
  printf("\n");
  for (int i = 0; i < cs2; i++)
    printf("%d ", kwc2[i]); // expect: 1 0 0 0 0
  printf("\n");
  for (int i = 0; i < cs3; i++)
    printf("%d ", kwc3[i]); // expect: 1 0 1
  printf("\n");
}
