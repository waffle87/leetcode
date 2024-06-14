#include "leetcode.h"

class Solution {
public:
  string breakPalindrom(string palindrome) {
    int n = palindrome.size();
    if (n == 1)
      return "";
    for (int i = 0; i < n / 2; i++) {
      if (palindrome[i] != 'a') {
        palindrome[i] = 'a';
        return palindrome;
      }
    }
    palindrome[n - 1] = 'b';
    return palindrome;
  }
};

int main() {
  Solution obj;
  cout << obj.breakPalindrom("abccba");
}
