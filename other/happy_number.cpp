#include "leetcode.h"

class Solution {
public:
  bool isHappy(int n) {
    int slow, fast;
    slow = fast = n;
    do {
      slow = square(slow);
      for (int i = 0; i < 2; i++)
        fast = square(fast);
    } while (slow != fast);
    if (slow == 1)
      return 1;
    else
      return 0;
  }

private:
  int square(int n) {
    int num = 0, tmp;
    while (n) {
      tmp = n % 10;
      num += tmp * tmp;
      n /= 10;
    }
    return num;
  }
};

int main() {
  Solution obj;
  if (obj.isHappy(19))
    cout << "true";
  else
    cout << "false";
}
