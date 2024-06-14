#include "leetcode.h"

class Solution {
public:
  int maximum69Number(int num) {
    if (num == 9999)
      return num;
    string n = to_string(num);
    for (auto &i : n)
      if (i == '6') {
        i = '9';
        break;
      }
    return stoi(n);
  }
};

int main() {
  Solution obj;
  cout << obj.maximum69Number(9669);
}
