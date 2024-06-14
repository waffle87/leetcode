// 168. Excel Sheet Column Title
#include "leetcode.h"

/*
 * given an integer 'column_number', return its corresponding column title as it
 * appears in an excel sheet. for example: A -> 1 B -> 2 C -> 3
 * ...
 * Z -> 26
 * AA -> 27
 * AB -> 28
 * ...
 */

class Solution {
public:
  string convertToTitle(int n) {
    if (n < 27)
      return string(1, 'A' + (n - 1) % 26);
    string ans = "";
    while (n > 0) {
      if (!(n % 26)) {
        ans += 'A' + 25;
        n--;
      } else {
        ans += 'A' + n % 26 - 1;
      }
      n /= 26;
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

int main() {
  Solution obj;
  cout << obj.convertToTitle(1) << endl;   // expect: A
  cout << obj.convertToTitle(28) << endl;  // expect: AB
  cout << obj.convertToTitle(701) << endl; // expect: ZY
}
