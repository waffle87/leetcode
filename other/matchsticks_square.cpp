#include "leetcode.h"

class Solution {
public:
  bool makesquare(vector<int> &matchsticks) {
    sort(matchsticks.begin(), matchsticks.end(), greater<int>());
    int total = accumulate(matchsticks.begin(), matchsticks.end(), 0);
    side = total;
    if ((float)total / 4 > side || matchsticks[0] > side)
      return false;
    return helper(0, side, 0, matchsticks);
  }

private:
  int side;
  bool helper(int i, int space, int done, vector<int> &matchsticks) {
    if (done == 3)
      return true;
    for (; i < matchsticks.size(); i++) {
      int num = matchsticks[i];
      bool ans;
      if (num > space)
        continue;
      matchsticks[i] = side + 1;
      if (num == space)
        ans = helper(1, side, done + 1, matchsticks);
      else
        ans = helper(i + 1, space - num, done, matchsticks);
      if (ans)
        return true;
      matchsticks[i] = num;
      while (i < matchsticks.size() && matchsticks[i + 1] == num)
        i++;
    }
    return false;
  }
};

int main() {
  Solution obj;
  vector<int> matchsticks = {1, 1, 2, 2, 2};
  if (obj.makesquare(matchsticks))
    cout << "true";
  else
    cout << "false";
}
