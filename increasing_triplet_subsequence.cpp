#include "leetcode.h"

class Solution {
public:
  bool increasingTriplet(vector<int> &nums) {
    int one = INT_MAX, two = INT_MAX;
    for (auto n : nums) {
      if (n <= one)
        one = n;
      else if (n <= two)
        two = n;
      else
        return true;
    }
    return false;
  }
};

int main() {
  Solution obj;
  vector<int> nums = {1, 2, 3, 4, 5};
  if (obj.increasingTriplet(nums))
    cout << "true";
  else
    cout << "false";
}
