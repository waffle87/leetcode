// 258. Add Digits
#include "leetcode.h"

// given an integer 'num', repeatedly add all its digits until
// the result has onlye one digit and return it

class Solution {
public:
  int addDigits(int num) {
    int sum = 0;
    while (num) {
      sum += num % 10;
      num /= 10;
    }
    if (sum < 10)
      return sum;
    else
      return addDigits(sum);
  }
};

int main() {
  Solution obj;
  printf("%d\n", obj.addDigits(38)); // expect: 2
  printf("%d\n", obj.addDigits(0));  // expect: 0
}
