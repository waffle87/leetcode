// 67. Add Binary
#include "leetcode.h"

class Solution {
public:
  string addBinary(string a, string b) {
    int i = a.size() - 1, j = b.size() - 1, carry = 0;
    string ans;
    while (i >= 0 || j >= 0 || carry) {
      if (i >= 0) {
        carry += a[i] - '0';
        i--;
      }
      if (j >= 0) {
        carry += b[j] - '0';
        j--;
      }
      ans += (carry % 2 + '0');
      carry /= 2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

int main() {
  Solution obj;
  cout << obj.addBinary("11", "1") << endl;      // expect: 100
  cout << obj.addBinary("1010", "1011") << endl; // expect: 10101
}
