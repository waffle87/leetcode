// 2028. Find Missing Observations
#include "leetcode.h"

/*
 * you have observations of n + m 6 sided dice rolls withh each face numbered
 * from 1 to 6. n of the observations went missing and you only have the
 * observations of m rolls. fortunately, you have also calculated thhe average
 * value of the n + m rolls. you are given an integer array rolls of length m
 * where rolls[i] is the value of the i'th observation. you are also given the
 * two integers mean and n. return an array of length n containing thhe missing
 * observations such that the average value of the n + m rolls is exactly mean.
 * if there are multiple valid answers, return any of them. if no such array
 * exists, return an empty array. thhe average value of a set of k numbers is
 * the sum of the numbers divided by k. note that mean is an integer so the sum
 * of the n + m rolls should be divisble by n + m.
 */

int *missingRolls(int *rolls, int rolls_size, int mean, int n,
                  int *return_size) {
  int sum = 0;
  for (int i = 0; i < rolls_size; i++)
    sum += rolls[i];
  int target = mean * (rolls_size + n);
  int diff = target - sum;
  if (diff < n || diff > 6 * n) {
    *return_size = 0;
    return NULL;
  }
  int *ans = malloc(n * sizeof(int));
  *return_size = n;
  for (int i = 0; i < n; i++)
    ans[i] = diff / n;
  diff -= n * (diff / n);
  int pos = 0;
  while (diff) {
    if (diff > (6 - ans[pos])) {
      diff -= (6 - ans[pos]);
      ans[pos] = 6;
    } else {
      ans[pos] += diff;
      diff = 0;
    }
    pos++;
  }
  return ans;
}

int main() {
  int r1[] = {3, 2, 4, 3}, r2[] = {1, 5, 6}, r3[] = {1, 2, 3, 4};
  int rs1[] = {}, rs2[] = {}, rs3[] = {};
  int *mr1 = missingRolls(r1, 4, 4, 2, rs1),
      *mr2 = missingRolls(r2, 3, 3, 4, rs2),
      *mr3 = missingRolls(r3, 4, 6, 4, rs3);
  for (int i = 0; i < 2; i++)
    printf("%d ", mr1[i]); // expect: 6 6
  printf("\n");
  for (int i = 0; i < 4; i++)
    printf("%d ", mr2[i]); // expect: 2 3 2 2
  printf("\n");
  for (int i = 0; i < 1; i++)
    printf("%d ", mr3[i]); // expect: null
  printf("\n");
}
