#include "leetcode.h"

class Solution {
public:
  string largestOddNumber(string num) {
    if (num.back() == '0')
      num.pop_back();
    int back = stoi(num) % 10;
    if (back % 2 == 0) {
      for (int i = 0; i < num.size(); i++)
        if (num[i] % 2 == 0)
          num.erase(i, 1), i--;
      if (num.size() < 2)
        return num;
      else
        for (int i = 0; i < num.size(); i++)
          if (num[i] < num[i + 1])
            return num.substr(i + 2, 1);
    } else
      return num;
    return string();
  }
};

int main() {
  Solution obj;
  cout << endl << obj.largestOddNumber("10133890");
}
