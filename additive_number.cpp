// 306. Additive Number
#include "leetcode.h"

/*
 * an additive number is a string whose digits can form an additive sequence. a
 * valid additive seuqnece should contain at least three numbers. except for the
 * firs ttwo numbers each subsequent number in the sequence must be the sum of
 * the preceding two. given a string containing only digits, return 'true' if it
 * is an additive number, or 'false' otherwise. note, numbers in the additive
 * sequence cannot have leading zeros, so sequence, 1,2,03, or 1,02,3 is invalid
 */

class Solution {
  string add(string n, string m) {
    string res;
    int i = n.size() - 1, j = m.size() - 1, carry = 0;
    while (i >= 0 || j >= 0) {
      int sum =
          carry + (i >= 0 ? (n[i--] - '0') : 0) + (j >= 0 ? (m[j--] - '0') : 0);
      res.push_back(sum % 10 + '0');
      carry = sum / 10;
    }
    if (carry)
      res.push_back(carry + '0');
    reverse(res.begin(), res.end());
    return res;
  }
  bool check(string n1, string n2, string n) {
    if (n1.size() > 1 && n1[0] == '0' || n2.size() > 1 && n2[0] == '0')
      return false;
    string sum = add(n1, n2);
    if (n == sum)
      return true;
    if (n.size() <= sum.size() || !sum.compare(n.substr(0, sum.size())))
      return false;
    else
      return check(n1, sum, n.substr(sum.size()));
  }

public:
  bool isAdditiveNumber(string num) {
    for (int i = 1; i <= num.size() / 2; i++)
      for (int j = 1; j <= (num.size() - i) / 2; j++)
        if (check(num.substr(0, i), num.substr(i, j), num.substr(i + j)))
          return true;
    return false;
  }
};

int main() {
  Solution obj;
  printf("%d\n", obj.isAdditiveNumber("112358"));    // expect: 1
  printf("%d\n", obj.isAdditiveNumber("199100199")); // expect: 1
};
