#include "leetcode.h"

class Solution {
public:
  string largestMultipleOfThree(vector<int> &digits) {
    int n = digits.size(), d[10] = {}, sum = 0;
    int r1[] = {1, 4, 7, 2, 5, 8}, r2[] = {2, 5, 8, 1, 4, 7};
    string ans = "";
    for (int i = 0; i < n; i++) {
      ++d[digits[i]];
      sum += digits[i];
    }
    while (sum % 3 != 0) {
      for (int i = 0; i < 6; i++) {
        if (sum % 3 == 1 && d[r1[i]]) {
          sum -= r1[i];
          d[r1[i]]--;
          break;
        } else if (sum % 3 == 2 && d[r2[i]]) {
          sum -= r2[i];
          d[r2[i]]--;
          break;
        }
      }
    }
    for (int i = 9; i >= 0; i--)
      for (int j = 1; j <= d[i]; j++)
        ans += to_string(i);
    return ans[0] == '0' ? "0" : ans;
  }
};

int main() {
  Solution obj;
  vector<int> digits = {8, 1, 9};
  cout << obj.largestMultipleOfThree(digits);
}
