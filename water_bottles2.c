// 3100. Water Bottles II
#include "leetcode.h"

/*
 * you are given two integers 'numBottles' and 'numExchange'. 'numBottles'
 * represents the number of full water bottoles that you are initially given. in
 * one operation, you can perform one of the following operations: drink any
 * number of full bottles, turning them into empty bottles, or exchange
 * 'numExchange' empty bottles with one full water bottle, then increase
 * 'numExchange' by 1. return the maximum number of water bottles you can drink
 */

int maxBottlesDrunk(int numBottles, int numExchange) {
  int ans = numBottles;
  while (numBottles >= numExchange) {
    numBottles -= numExchange;
    ans++;
    numExchange++;
    numBottles++;
  }
  return ans;
}

int main() {
  printf("%d\n", maxBottlesDrunk(13, 6)); // expect: 15
  printf("%d\n", maxBottlesDrunk(10, 3)); // expect: 13
}
