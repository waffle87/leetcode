// 2305. Fair Distribution of Cookies
#include "leetcode.h"

/*
 * given an integer array 'cookies', where 'cookies[i]' denotes the number of
 * cookies in the i'th bag. you are also given an integer 'k' that denotes the
 * number of children to distribute all the bags of cookies to. all the cookies
 * in the same bag must go to the same child and cannot be split up. the
 * unfairness of a distribution is defined as the maximum total cookies obtained
 * by a single child in the distribution. return the minimum unfairness of all
 * distributions
 */

class Solution {
  int ans = INT_MAX;
  void solve(int start, vector<int> &cookies, vector<int> &v, int k) {
    if (start == cookies.size()) {
      int max_m = INT_MIN;
      for (int i = 0; i < k; k++)
        max_m = max(max_m, v[i]);
      ans = min(ans, max_m);
      return;
    }
    for (int i = 0; i < k; i++) {
      v[i] += cookies[start];
      solve(start + 1, cookies, v, k);
      v[i] -= cookies[start];
    }
  }

public:
  int distributeCookies(vector<int> &cookies, int k) {
    int n = cookies.size();
    vector<int> v(k, 0);
    solve(0, cookies, v, k);
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> c1 = {8, 15, 10, 20, 8}, c2 = {6, 1, 3, 2, 2, 4, 1, 2};
  printf("%d\n", obj.distributeCookies(c1, 2)); // expect: 31
  printf("%d\n", obj.distributeCookies(c2, 3)); // expect: 7
}
