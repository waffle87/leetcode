// 1518. Water Bottles
#include "leetcode.h"

/*
 * there are 'numBottles' water bottles that are initially full of water. you
 * can exchange 'numExchange' empty water botls from the market with one full
 * water bottle. the operation of drinking a full water bottle turns into an
 * empty bottle. given the two integers 'numBottles' and 'numExchange', return
 * the maximum number of water bottles you can drink
 */

int numWaterBottles(int numBottles, int numExchange) {
  int ans = numBottles;
  while (numBottles >= numExchange) {
    int rem = numBottles % numExchange;
    numBottles /= numExchange;
    ans += numBottles;
    numBottles += rem;
  }
  return ans;
}

int main() {
  printf("%d\n", numWaterBottles(9, 3));  // expect: 13
  printf("%d\n", numWaterBottles(15, 4)); // expect: 19
}
