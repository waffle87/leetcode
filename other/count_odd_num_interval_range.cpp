// 1523. Count Odd Numbers in an Interval Range
#include "leetcode.h"

// given two non-negative integers 'low' and 'high' return the
// count of odd numbers  * between 'low' and 'high' (incusively)

class Solution {
public:
  int countOdds(int low, int high) {
    int ans = 0;
    if (low % 2) {
      ans += (high - low) / 2;
      ans++;
    } else
      ans += ceil(double(high - low) / 2.0);
    return ans;
  }
};

int main() {
  Solution obj;
  cout << obj.countOdds(3, 7) << endl;  // expect: 3
  cout << obj.countOdds(8, 10) << endl; // expect: 1
}
