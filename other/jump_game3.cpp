#include "leetcode.h"

class Solution {
public:
  bool canReach(vector<int> &arr, int start) {
    vector<bool> visited(arr.size(), false);
    return dfs(arr, start, visited);
  }

private:
  bool dfs(vector<int> &arr, int curr, vector<bool> &k) {
    if ((curr < 0) || (curr >= arr.size()) || k[curr])
      return false;
    if (arr[curr] == 0)
      return true;
    k[curr] = true;
    return dfs(arr, curr + arr[curr], k) || dfs(arr, curr - arr[curr], k);
  }
};

int main() {
  Solution obj;
  vector<int> arr1 = {4, 2, 3, 0, 3, 1, 2}, arr2 = {3, 0, 2, 1, 2};
  testBool(obj.canReach(arr1, 5)); // true
  testBool(obj.canReach(arr1, 0)); // true
  testBool(obj.canReach(arr2, 2)); // false
}
