// 1312. Minimum Insertion Steps to Make a String Palindrome
#include "leetcode.h"

/*
 * given string 's'. in one step you can insert any character at any index of
 * the string. return the minimum number of steps to make 's' palindrome. a
 * palindrome string is one that reads the same backward as well as forward.
 */

class Solution {
public:
  int minInsertions(string s) {
    vector<int> memo(s.size(), 0);
    int prv, tmp;
    for (int i = s.size() - 2; i >= 0; i--) {
      prv = 0;
      for (int j = i; j < s.size(); j++) {
        tmp = memo[j];
        memo[j] = s[i] == s[j] ? prv : 1 + min(memo[j], memo[j - 1]);
        prv = tmp;
      }
    }
    return memo[s.size() - 1];
  }
};

int main() {
  Solution obj;
  printf("%d\n", obj.minInsertions("zzazz"));    // expect: 0
  printf("%d\n", obj.minInsertions("mbadm"));    // expect: 2
  printf("%d\n", obj.minInsertions("leetcode")); // expect: 5
}
