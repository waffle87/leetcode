// 1187. Make Array Strictly Increasing
#include <algorithm>
#include <limits.h>
#include <stdio.h>
#include <unordered_map>
#include <vector>
using namespace std;

/*
 * given two integer arrays 'arr1' and 'arr2', return the minimum number of
 * operations (possibly zero) needed to make 'arr1' strictly Increasing in one
 * opration, you can choose two indices '0 <= i <= arr1.len' and '0 <= j <
 * arr2.len' and do the assignment 'arr1[i] = arr2[j]' if there is no way to
 * make 'arr1' strictly increasing, return -1
 */

class Solution {
  int check(int curr, int left, vector<int> &arr1, vector<int> &arr2,
            vector<unordered_map<int, int>> &dp) {
    if (curr == arr1.size())
      return 0;
    if (dp[curr].find(left) != dp[curr].end())
      return dp[curr][left];
    int exclude, include;
    if (arr1[curr] > left)
      exclude = check(curr + 1, arr1[curr], arr1, arr2, dp);
    else
      exclude = INT_MAX;
    int rep = upper_bound(arr2.begin(), arr2.end(), left) - arr2.begin();
    if (rep == arr2.size())
      include = INT_MAX;
    else
      include = check(curr + 1, arr2[rep], arr1, arr2, dp);
    if (include == INT_MAX)
      dp[curr][left] = exclude;
    else
      dp[curr][left] = min(exclude, include + 1);
    return dp[curr][left];
  }

public:
  int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2) {
    sort(arr2.begin(), arr2.end());
    vector<unordered_map<int, int>> dp(2001);
    int val = check(0, INT_MIN, arr1, arr2, dp);
    if (val == INT_MAX)
      return -1;
    return val;
  }
};

int main() {
  Solution obj;
  vector<int> a1123 = {1, 5, 3, 6, 7};
  vector<int> a21 = {1, 3, 2, 4}, a22 = {4, 3, 1}, a23 = {1, 6, 3, 3};
  printf("%d\n", obj.makeArrayIncreasing(a1123, a21)); // expect: 1
  printf("%d\n", obj.makeArrayIncreasing(a1123, a22)); // expect: 1
  printf("%d\n", obj.makeArrayIncreasing(a1123, a23)); // expect: 1
}
