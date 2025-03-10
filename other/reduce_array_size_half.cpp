#include "leetcode.h"

class Solution {
public:
  int minSetSize(vector<int> &arr) {
    int ans = 0, n = arr.size(), n1 = 0;
    vector<int> j;
    unordered_map<int, int> um;
    for (int i = 0; i < n; i++)
      um[arr[i]]++;
    for (auto x : um)
      j.push_back(x.second);
    if (j.size() == 1)
      return 1;
    sort(j.begin(), j.end());
    for (int i = j.size() - 1; i >= 0; i--) {
      if (ans >= n / 2)
        return n1;
      n1++;
      ans = ans + j[i];
    }
    return 0;
  }
};

int main() {
  Solution obj;
  vector<int> arr = {3, 3, 3, 3, 5, 5, 5, 2, 2, 7};
  cout << obj.minSetSize(arr);
}
