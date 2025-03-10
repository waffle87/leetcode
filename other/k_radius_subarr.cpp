// 2090. K Radius Subarray Averages
#include "leetcode.h"

/*
 * given a 0-indexed array 'nums' of 'n' integers, and an integer 'k'. the
 * k-radius average for a subarray of 'nums' centered at some index 'i' with the
 * radius 'k' is the average of all elements in 'nums' between the indices 'i -
 * k' and 'i + k' (inclusive). if there are less than 'k' elements before or
 * after the index 'i', then the k-radius average is -1. build and return 'avgs'
 * of length 'n' where 'avgs[i]' is the k-radius average for the subarray
 * centered at index 'i'. the average of 'x' elements is the sum of the 'x'
 * elements divided by 'x', using integer division. the integer division
 * truncates toward zero, which means losing its fractional part.
 */

class Solution {
public:
  vector<int> getAverages(vector<int> &nums, int k) {
    vector<int> ans(nums.size(), -1);
    long long sum = 0, d = k * 2 + 1;
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      if (i + 1 >= d) {
        if (i >= d)
          sum -= nums[i - d];
        ans[i - d / 2] = sum / d;
      }
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> n1 = {7, 4, 3, 9, 1, 8, 5, 2, 6}, n2 = {100000}, n3 = {8};
  for (auto i : obj.getAverages(n1, 3))
    printf("%d ", i); // expect: -1,-1,-1,5,4,4,-1,-1,-1
  printf("\n");
  for (auto i : obj.getAverages(n2, 0))
    printf("%d ", i); // expect: 100000
  printf("\n");
  for (auto i : obj.getAverages(n3, 100000))
    printf("%d ", i); // expect: -1
  printf("\n");
}
