#include "leetcode.h"

class Solution {
public:
  int numFactoredBinaryTrees(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    long ans = 0;
    unordered_map<int, long> um;
    for (int num : arr) {
      long ways = 1;
      double lim = sqrt(num);
      for (int i = 0, fA = arr[0]; fA <= lim; fA = arr[++i]) {
        if (num % fA != 0)
          continue;
        int fB = num / fA;
        if (um.find(fB) != um.end())
          ways += um[fA] * um[fB] * (fA == fB ? 1 : 2);
      }
      um[num] = ways;
      ans = (ans + ways) % 1000000007;
    }
    return (int)ans;
  }
};

int main() {
  Solution obj;
  vector<int> arr = {2, 4};
  cout << obj.numFactoredBinaryTrees(arr);
}
