// 808. Soup Servings
#include "leetcode.h"

/*
 * there are two types of soup: type a, and type b. initially, we have 'n' ml of
 * each type of soup. there are four kinds of operations:
 * 1. serve 100 ml of soup a and 0ml of soup b
 * 2. serve 75ml of soup a and 25ml of soup b
 * 3. serve 50ml of soup a and 50ml of soup b
 * 4. serve 25ml of soup a and 75ml of soup b
 * when we serve some soup, we give it to someone, and we no longer have it.
 * each turn, we will choose from the four operations with an equal probability
 * of '0.25'. if the remaining volume of soup is not enough to complete the
 * operation, we will serve as much as possible. we stop once we no longer have
 * some quantity of both types of soup. note that we do not have an operation
 * where all 100 ml's of soup b are used first. return the probability that soup
 * a will be empty first, plus half the probability that a and b become empty at
 * the same time. answers within '10^-5' of the actual answer will be accepted.
 */

class Solution {
  unordered_map<int, unordered_map<int, double>> store;
  double helper(int a, int b) {
    if (!a && b)
      return 1;
    else if (!a && !b)
      return 0.5;
    else if (a && !b)
      return 0;
    if (store[a][b])
      return store[a][b];
    double prob = 0;
    prob += 0.25 * helper(a - min(a, 100), b);
    prob += 0.25 * helper(a - min(a, 75), b - min(b, 25));
    prob += 0.25 * helper(a - min(a, 50), b - min(b, 50));
    prob += 0.25 * helper(a - min(a, 25), b - min(b, 75));
    store[a][b] = prob;
    return prob;
  }

public:
  double soupServings(int n) {
    if (n >= 5000)
      return 1.0;
    else
      return helper(n, n);
  }
};

int main() {
  Solution obj;
  printf("%f\n", obj.soupServings(50));  // expect: 0.62500
  printf("%f\n", obj.soupServings(100)); // expect: 0.71875
}
