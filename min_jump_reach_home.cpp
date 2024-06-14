#include "leetcode.h"

class Solution {
public:
  int minimumJumps(vector<int> &forbidden, int a, int b, int x) {
    unordered_set<int> f(forbidden.begin(), forbidden.end());
    vvd(int) visited(2, vector<int>(5000));
    queue<pair<int, bool>> qp;
    qp.push({0, false});
    visited[0][0] = 1;
    visited[1][0] = 1;
    int ans = 0;
    while (!qp.empty()) {
      int len = qp.size();
      while (len > 0) {
        len--;
        int curr = qp.front().first;
        bool flag = qp.front().second;
        if (curr == x)
          return ans;
        qp.pop();
        int forward = curr + a, backward = curr - b;
        if (forward < 5000 && visited[0][forward] == 0 && !f.count(forward)) {
          qp.push({forward, false});
          visited[0][forward] = 1;
        }
        if (backward >= 0 && visited[1][backward] == 0 && !f.count(backward) &&
            !flag) {
          qp.push({backward, true});
          visited[1][backward] = 1;
        }
      }
      ans++;
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> forbidden = {14, 4, 18, 1, 15};
  int a = 3, b = 15, x = 9;
  cout << obj.minimumJumps(forbidden, a, b, x);
}
