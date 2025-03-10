#include "leetcode.h"
#include <vector>

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    vector<int> ans;
    for (int i = 0; i < numbers.size(); i++) {
      int low = 0, high = numbers.size() - 1;
      while (low <= high) {
        int mid = low + (high - low) / 2;
        if (numbers[mid] == target - numbers[i]) {
          if (mid == i)
            low = mid + 1;
          else
            return {i + 1, mid + 1};
        } else if (numbers[mid] < target - numbers[i])
          low = mid + 1;
        else
          high = mid - 1;
      }
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> numbers = {2, 7, 11, 15};
  int target = 9;
  // expected output: 1,2
  obj.twoSum(numbers, target);
}
