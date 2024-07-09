// 1701. Average Waiting Time
#include "leetcode.h"

/*
 * there is a restaurant with a single chef. you are given an array 'customers'
 * where 'customers[i] = [arrivali, timei]'. where 'arrivali' is the arrival
 * time of the i'th customer. the arrival times are sorted in non decreasing
 * order, and 'timei' is the time needed to prepare the order of the i'th
 * customer. when a customer arrives, he gives the chef his order and the chef
 * prepares it. return the average waiting time of all customers. solutions
 * within 10^-5 from actually answer are considered accepted
 */

double averageWaitingTime(int **customers, int customersSize,
                          int *customersColSize) {
  double wait = 0;
  int curr = 0;
  for (int i = 0; i < customersSize; i++) {
    curr = fmax(curr, customers[i][0]);
    wait += curr + customers[i][1] - customers[i][0];
    curr += customers[i][1];
  }
  return wait / customersSize;
}

int main() {
  int c1[3][2] = {{1, 2}, {2, 5}, {4, 3}},
      c2[4][2] = {{5, 2}, {5, 4}, {10, 3}, {20, 1}};
  int ccs1[] = {2, 2, 2}, ccs2[] = {2, 2, 2, 2};
  printf("%f\n", averageWaitingTime((int **)c1, ARRAY_SIZE(c1),
                                    ccs1)); // expect: 5.0000
  printf("%f\n", averageWaitingTime((int **)c2, ARRAY_SIZE(c2),
                                    ccs2)); // expect: 3.25000
}
