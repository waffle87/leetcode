// 875. Koko Eating Bananas
#include "leetcode.h"

// return minimum integer 'k' such that koko can eat all bananas within 'h'
// hours

class Solution {
public:
  int minEatingSpeed(vector<int> &piles, int h) {
    int l = 1, r = 1000000000;
    while (l < r) {
      int m = (l + r) / 2, total = 0;
      for (int p : piles)
        total += (p + m - 1) / m;
      if (total > h)
        l = m + 1;
      else
        r = m;
    }
    return l;
  }
};

int main() {
  Solution obj;
  vector<int> p1 = {3, 6, 7, 11}, p2_3 = {30, 11, 23, 4, 20};
  printf("%d\n", obj.minEatingSpeed(p1, 8));   // expect: 4
  printf("%d\n", obj.minEatingSpeed(p2_3, 5)); // expect: 30
  printf("%d\n", obj.minEatingSpeed(p2_3, 6)); // expect: 23
}
