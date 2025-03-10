#include "leetcode.h"

class Solution {
public:
  int sumSubarrayMins(vector<int> &arr) {
    vector<long> s, sums(arr.size(), 0);
    long j, ans = 0, mod = 1000000007;
    for (int i = 0; i < arr.size(); ++i) {
      while (!s.empty() && arr[s.back()] > arr[i])
        s.pop_back();
      j = !s.empty() ? s.back() : -1;
      sums[i] = ((j >= 0 ? sums[j] : 0) + (i - j) * arr[i]) % mod;
      s.push_back(i);
    }
    for (int i = 0; i < sums.size(); ++i)
      ans = (ans + sums[i]) % mod;
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> arr = {
      117,   1315,  1336,  4213,  5634,  6288,  7640,  8533,  9688,  10186,
      10593, 11896, 13673, 14707, 15484, 17429, 19639, 20416, 21375, 23601,
      25800, 26485, 27893, 28026, 28695, 29121, 28642, 28023, 27642, 26324,
      23844, 22069, 21124, 20181, 18957, 15736, 15364, 13749, 13612, 11062,
      10319, 9755,  9367,  7977,  6463,  6049,  4886,  3071,  1331,  865};
  cout << obj.sumSubarrayMins(arr);
}
