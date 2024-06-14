// 6. Zigzag Conversion
#include "leetcode.h"

/*
 * the string "PAYPALISHIRING" is written in zigzag pattern on a given number
 * of rows like this:
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * and then read line by line: "PAHNAPLSIIGYIR". write function that will take
 * a string and mak this conversion give a number of rows.
 */

class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows <= 1)
      return s;
    const int len = (int)s.size();
    string *str = new string[numRows];
    int row = 0, step = 1;
    for (int i = 0; i < len; ++i) {
      str[row].push_back(s[i]);
      if (row == 0)
        step = 1;
      else if (row == numRows - 1)
        step = -1;
      row += step;
    }
    s.clear();
    for (int i = 0; i < numRows; ++i)
      s.append(str[i]);
    delete[] str;
    return s;
  }
};

int main() {
  Solution obj;
  cout << obj.convert("PAYPALISHIRING", 3) << endl; // expect: PAHNAPLSIIGYIR
  cout << obj.convert("PAYPALISHIRING", 4) << endl; // expect: PINALSIGYAHRPI
  cout << obj.convert("A", 1) << endl;              // expect: A
}
