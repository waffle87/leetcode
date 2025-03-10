#include "leetcode.h"

class Solution {
public:
  bool uniqueOccurrences(vector<int> &arr) {
    short m[2001] = {};
    for (auto n : arr)
      ++m[n + 1000];
    sort(begin(m), end(m));
    for (auto i = 1; i < 2001; ++i)
      if (m[i] && m[i] == m[i - 1])
        return false;
    return true;
  }
};

int main() {
  Solution obj;
  vector<int> arr = {1, 2, 2, 1, 1, 3};
  if (obj.uniqueOccurrences(arr))
    cout << "true";
  else
    cout << "false";
}
