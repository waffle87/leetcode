// 1. Two Sum
#include "leetcode.h"

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> ans;
    unordered_map<int, int> um;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      int search_num = target - nums[i];
      if (um.find(search_num) != um.end()) {
        ans.push_back(um[search_num]);
        ans.push_back(i);
        break;
      }
      um[nums[i]] = i;
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> n1 = {2, 7, 11, 15}, n2 = {3, 2, 4}, n3 = {3, 3};
  for (auto i : obj.twoSum(n1, 9))
    printf("%d ", i);
  printf("\n");
  for (auto i : obj.twoSum(n2, 6))
    printf("%d ", i);
  printf("\n");
  for (auto i : obj.twoSum(n3, 6))
    printf("%d ", i);
  printf("\n");
}
