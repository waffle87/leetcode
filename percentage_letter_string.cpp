#include "leetcode.h"

class Solution {
public:
  int percentageLetter(string s, char letter) {
    int n = s.size();
    int freq = 0;
    for (int i = 0; i < n; i++)
      if (s[i] == letter)
        freq++;
    return (freq * 100) / n;
  }
};

int main() {
  string s = "foobar";
  char letter = 'o';
  Solution obj;
  cout << obj.percentageLetter(s, letter);
}
