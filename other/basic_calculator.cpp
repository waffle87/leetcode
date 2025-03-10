#include "leetcode.h"

class Solution {
public:
  int calculate(string s) {
    stack<pair<int, int>> sp;
    long long int ans = 0;
    int sign = +1;
    for (int i = 0; i < s.size(); ++i) {
      char ch = s[i];
      if (isdigit(ch)) {
        long long int num = 0;
        while (i < s.size() && isdigit(s[i])) {
          num = (num * 10) + s[i] - '0';
          i++;
        }
        i--;
        ans += (num * sign);
        sign = +1;
      } else if (ch == '(') {
        sp.push(make_pair(ans, sign));
        ans = 0;
        sign = +1;
      } else if (ch == ')') {
        ans = sp.top().first + (sp.top().second * ans);
        sp.pop();
      } else if (ch == '-')
        sign = (-1 * sign);
    }
    return ans;
  }
};

int main() {
  Solution obj;
  cout << obj.calculate("1 + 1");
}
