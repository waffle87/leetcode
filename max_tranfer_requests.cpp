// 1601. Maximum Number of Achievable Transfer Requests
#include "leetcode.h"

/*
 * we have 'n' buildings numbered from 0 to 'n - 1'. each building has a number
 * of employees. it's transfer season and some employees want to change the
 * building they reside in. you are an an array 'requests' where 'requests[i] =
 * [fromi, toi]' represents an employee's request to transfer from building
 * 'fromi' to building 'toi'. all buildings are full. so a list of requests is
 * achievable only if for each building, the net change in emplyee transfers is
 * zero. this means the number of emplyees leaving is equal to the number of
 * employees moving in. return the maximum number of achievable requests
 */

class Solution {
public:
  int maximumRequests(int n, vvd(int) & requests) {
    int ans = 0, k = requests.size(), r = 1 << k, x;
    for (int i = 1; i < r; i++) {
      int *a = (int *)calloc(n, sizeof(int));
      int curr = 0;
      for (int j = 0; j < k; j++) {
        if (int(i >> j) & 1) {
          a[requests[j][0]]++;
          a[requests[j][1]]--;
          curr++;
        }
      }
      for (x = 0; x < n; x++)
        if (a[x])
          break;
      if (x == n)
        ans = max(ans, curr);
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vvd(int) r1 = {{0, 1}, {1, 0}, {0, 1}, {1, 2}, {2, 0}, {3, 4}};
  vvd(int) r2 = {{0, 0}, {1, 2}, {2, 1}}, r3 = {{0, 3}, {3, 1}, {1, 2}, {2, 0}};
  printf("%d\n", obj.maximumRequests(5, r1)); // expect: 5
  printf("%d\n", obj.maximumRequests(3, r2)); // expect: 3
  printf("%d\n", obj.maximumRequests(4, r3)); // expect: 4
}
