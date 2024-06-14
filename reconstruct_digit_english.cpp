#include "leetcode.h"

class Solution {
public:
  string originalDigits(string s) {
    int fMap[26] = {0}, ans[10] = {0};
    for (char c : s)
      fMap[c - 97]++;
    for (int i = 0; i < 10; i++) {
      int count = fMap[CHARS[i]];
      for (int remain : REM[i])
        fMap[remain] -= count;
      ans[DIGITS[i]] = count;
    }
    string ansStr;
    for (int i = 0; i < 10; i++) {
      char c = (char)(i + 48);
      for (int j = ans[i]; j; j--)
        ansStr += c;
    }
    return ansStr;
  }

private:
  const int DIGITS[10] = {0, 2, 4, 6, 8, 5, 7, 3, 9, 1},
            CHARS[10] = {25, 22, 20, 23, 6, 5, 18, 7, 8, 14};
  const vector<vector<int>> REM = {{14}, {14}, {5, 14}, {18, 8}, {8, 7},
                                   {8},  {},   {},      {},      {}};
};

int main() {}
