// 1910. Remove All Occurrences of a Substring
#include "leetcode.h"

/*
 * given two strings 's' and 'part', perform the following operation on 's'
 * until all occurrences of the substring 'part' are removed; find the leftmost
 * occurrence of the substring 'part' and remove it from 's'. return 's' after
 * removing all occurrences of 'part'. a substring is a contiguous sequence of
 * characters in a string
 */

class Solution {
  bool check(stack<char> stk, string part) {
    int n = part.size(), j = n - 1;
    while (j >= 0 && stk.top() == part[j])
      stk.pop(), j--;
    return j == -1;
  }

public:
  string removeOccurrences(string s, string part) {
    int n1 = s.size(), n2 = part.size();
    stack<char> stk;
    string str = "";
    for (int i = 0; i < n1; i++) {
      stk.push(s[i]);
      if (stk.size() >= n2)
        if (check(stk, part)) {
          int cnt = n2;
          while (cnt--)
            stk.pop();
        }
    }
    string ans = "";
    while (!stk.empty()) {
      ans += stk.top();
      stk.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

int main() {
  Solution obj;
  cout << obj.removeOccurrences("daabcbaabcbc", "abc") << endl; // expect: dab
  cout << obj.removeOccurrences("axxxxyyyyb", "xy") << endl;    // expect: ab
}
