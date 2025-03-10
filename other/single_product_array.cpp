// 1822. Sign of the Product of an Array
#include "leetcode.h"

/*
 * there is a function signFunc(x) that returns
 * 1 if x is positive
 * -1 if x is negative
 *  0 if x is equal to 0
 *  given an integer array 'nums', let 'product' be the product
 *  of all values in the array 'nums' return signFunc(product)
 */

class Solution {
public:
  int arraySign(vector<int> &nums) {
    int sign = 1;
    for (auto n : nums) {
      if (!n)
        return 0;
      else if (n < 0)
        sign = -sign;
    }
    return sign;
  }
};

int main() {
  Solution obj;
  vector<int> n1 = {-1, -2, -3, -4, 3, 2, 1};
  vector<int> n2 = {1, 5, 0, 2, -3};
  vector<int> n3 = {-1, 1, -1, 1, -1};
  printf("%d\n", obj.arraySign(n1)); // expect:  1
  printf("%d\n", obj.arraySign(n2)); // expect:  0
  printf("%d\n", obj.arraySign(n3)); // expect: -1
}
