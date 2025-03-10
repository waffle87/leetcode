// 2390. Removing Stars From a String
#include "leetcode.h"

/*
 * given a string 's', which contains stars (*). in one operation
 * you can choose a start in 's', remove the closest non-star
 * character to its left, as well remove the star itself.
 * return string after all stars have been removed. note, the
 * input will be generated such that the operation is always
 * possible, and the resulting string will always be unique
 */

class Solution {
public:
  string removeStars(string s) {
    stack<char> stk;
    string ans;
    vector<char> vec;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] != '*')
        stk.emplace(s[i]);
      else
        stk.pop();
    }
    while (!stk.empty()) {
      vec.emplace_back(stk.top());
      stk.pop();
    }
    reverse(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); i++)
      ans += vec[i];
    return ans;
  }
};

int main() {
  Solution obj;
  cout << obj.removeStars("leet**cod*e") << endl; // expect: lecoe
  cout << obj.removeStars("erase*****") << endl;  // expect: null
}
