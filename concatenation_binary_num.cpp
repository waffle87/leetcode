#include "leetcode.h"

class Solution {
public:
  int concatenatedBinary(int n) {
    string s = decimalToBinary(n);
    return binaryToDecimal(s);
  }

private:
  int mod = 1000000007;
  string decimalToBinary(int n) {
    string str = "";
    for (int i = n; i >= 1; --i) {
      int j = i;
      while (j) {
        str += (j % 2) + '0';
        j /= 2;
      }
    }
    return str;
  }
  int binaryToDecimal(string n) {
    long long ans = 0, p = 1;
    for (int i = 0; i < n.size(); ++i) {
      long long curr = (n[i] - '0') * p;
      p *= 2;
      p %= mod;
      ans += curr;
    }
    return ans % mod;
  }
};

int main() {
  Solution obj;
  cout << obj.concatenatedBinary(3);
}
