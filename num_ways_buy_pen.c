// 2240. Number of Ways to Buy Pens and Pencils
#include "leetcode.h"

/*
 * given an integer 'total' indicating the amount of money you have. you are
 * also given two inegers 'cost1' and 'cost2' indicating the price of a pen and
 * pencil respectively. you can spend part or all of your money to buy multiple
 * quantities (or none) of each kind of writing utensil. return the number of
 * distinct ways you can buy some number of pens and pencils
 */

long long waysToBuyPensPencils(int total, int cost1, int cost2) {
  long long ans = 0;
  int val = total + cost1;
  for (int i = 0; i <= total / cost1; i++) {
    val -= cost1;
    ans += (val / cost2 + 1);
  }
  return ans;
}

int main() {
  printf("%lld\n", waysToBuyPensPencils(20, 10, 5)); // expect: 9
  printf("%lld\n", waysToBuyPensPencils(5, 10, 10)); // expect: 1
}
