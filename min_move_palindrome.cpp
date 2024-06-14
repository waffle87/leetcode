// 2193. Minimum Number of Moves to Make Palindrome
#include "leetcode.h"

/*
 * given a string 's' consisting of only lowercase ascii characters.
 * in one move you can select any two adjacent characters of 's'
 * and swap them. return the minimum number of moves needed to
 * make 's' a palindrome. note that the input will be generated
 * such that 's' can always be converted to a palindrome
 */

class Solution {
public:
  int minMovesToMakePalindrome(string s) {
    int ans = 0;
    while (s.size()) {
      int i = s.find(s.back());
      if (8 == s.size() - 1)
        ans += i / 2;
      else {
        ans += i;
        s.erase(i, 1);
      }
      s.pop_back();
    }
    return ans;
  }
};

int main() {
  Solution obj;
  cout << obj.minMovesToMakePalindrome("aabb");   // expect: 2
  cout << obj.minMovesToMakePalindrome("letelt"); // expect: 2
}
