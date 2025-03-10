// 93. Restore IP Addresses
#include "leetcode.h"

/*
 * a valid ip address consists of exactly 4 integers separated by single dots
 * each integer is between 0 and 255 (inclusive) and cannot have leading 0's
 * given: string 's' containing only digits, return all possible valid ip
 * addresses that can be formed by insert dots into 's'. digits cannot be
 * reordered or removed. return addresses in any order.
 */

class Solution {
public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> ans;
    string ip;
    dfs(s, 0, 0, ip, ans);
    return ans;
  }

private:
  void dfs(string s, int start, int step, string ip, vector<string> &res) {
    if (start == s.size() && step == 4) {
      ip.erase(ip.end() - 1);
      res.push_back(ip);
      return;
    }
    if (s.size() - start > (4 - step) * 3)
      return;
    if (s.size() - start < (4 - step))
      return;
    int num = 0;
    for (int i = start; i < start + 3; i++) {
      num = num * 10 + (s[i] - '0');
      if (num <= 255) {
        ip += s[i];
        dfs(s, i + 1, step + 1, ip + '.', res);
      }
      if (num == 0)
        break;
    }
  }
};

int main() {
  Solution obj;
  for (auto i : obj.restoreIpAddresses("25525511135"))
    cout << i; // expect: 255.255.11.135","255.255.111.35
  cout << endl;
  for (auto i : obj.restoreIpAddresses("0000"))
    cout << i; // expect: 0.0.0.0
  cout << endl;
  for (auto i : obj.restoreIpAddresses("101023"))
    cout << i; // expect: 1.0.10.23,1.0.102.3,10.1.0.23,10.10.2.3,101.0.2.3
  cout << endl;
}
