#include "leetcode.h"

class Solution {
public:
  string intToRoman(int num) {
    string ans;
    int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string sym[] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                    "XL", "X",  "IX", "V",  "IV", "I"};
    for (int i = 0; num != 0; i++)
      while (num >= val[i]) {
        ans += sym[i];
        num -= val[i];
      }
    return ans;
  }
};

int main() {
  Solution obj;
  cout << obj.intToRoman(1994);
}
