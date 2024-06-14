#include "leetcode.h"

class Solution {
public:
  int guessNumber(int n) {
    int left = 1, right = n, mid = n / 2;
    while (left <= right) {
      int ans = guess(mid); // guess is api call
      if (!ans)
        return mid;
      left = ans < 0 ? left : mid + 1;
      right = ans < 0 ? mid - 1 : right;
      mid = left + (right - left) / 2;
    }
    return -1;
  }
};

int main() {
  Solution obj;
  cout << obj.guessNumber(10);
}
