// 7. Reverse Integer
#include "leetcode.h"

/*
 * given a signed 32-bit integer 'x', return 'x' with its digits reversed. if
 * reversing 'x' causes the value to go outside the signed 32-bit integer range,
 * then return 0
 */

class Solution {
public:
  int reverse(int x) {
    int ans = 0;
    while (x) {
      int tmp = ans * 10 + x % 10;
      if (tmp / 10 != ans)
        return 0;
      ans = tmp;
      x /= 10;
    }
    return ans;
  }
};

int main() {
  Solution obj;
  printf("%d --> %d\n", 123, obj.reverse(123));
  printf("%d --> %d\n", -123, obj.reverse(-123));
  printf("%d --> %d\n", 120, obj.reverse(120));
}
