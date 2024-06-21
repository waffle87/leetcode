// 1052. Grumpy Bookstore Owner
#include "leetcode.h"

/*
 * there is a bookstore owner that has a store open for 'n' miniutes. every
 * minute some number of customers entre the store. you are given an integer
 * array 'customers' of size 'n' where 'customers[i]' is the number of the
 * customer that entres the store at the start of the i'th minute and all those
 * customers leave after the end of that minute. on some minutes, the bookstore
 * owner is grumpy. you are given an binary array 'grumpy' where 'grumpy[i]' is
 * 1 if the bookstore owner is grumpy and zero otherwise. return the maximum
 * number of customers that can be satisfied throughout the day.
 */

int maxSatisfied(int *customers, int customersSize, int *grumpy, int grumpySize,
                 int minutes) {
  int total_satsified = 0, additional_satisfied = 0, curr = 0;
  for (int i = 0; i < customersSize; i++)
    if (!grumpy[i])
      total_satsified += customers[i];
  for (int i = 0; i < minutes; i++)
    if (grumpy[i])
      curr += customers[i];
  additional_satisfied = curr;
  for (int i = minutes; i < customersSize; i++) {
    if (grumpy[i])
      curr += customers[i];
    if (grumpy[i - minutes])
      curr -= customers[i - minutes];
    if (curr > additional_satisfied)
      additional_satisfied = curr;
  }
  return total_satsified + additional_satisfied;
}

int main() {
  int c1[] = {1, 0, 1, 2, 1, 1, 7, 5}, g1[] = {0, 1, 0, 1, 0, 1, 0, 1},
      c2[] = {1}, g2[] = {0};
  printf("%d\n",
         maxSatisfied(c1, ARRAY_SIZE(c1), g1, ARRAY_SIZE(c1), 3)); // expect: 16
  printf("%d\n",
         maxSatisfied(c2, ARRAY_SIZE(c2), g2, ARRAY_SIZE(c2), 1)); // expect: 1
}
