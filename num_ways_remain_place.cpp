// 1269. Number of Ways to Stay in the Same Place After Some Steps
#include "leetcode.h"

/*
 * you have a pointer at index 0 in an array of size 'arr_len'. at each step,
 * you can move 1 position to the left, 1 position to the right in the array, or
 * stay in the same plae. given two integers 'steps' and 'arr_len' return the
 * number of ways such that your pointer is still at index 0 after exactly
 * 'steps' steps. since the answer may be too large, return it modulo 10e9+7
 */

class Solution {
public:
  int numWays(int steps, int arr_len) {
    int n = min(steps / 2 + 1, arr_len);
    vector<int> v1(n + 2), v2(n + 2);
    v1[1] = 1;
    while (steps--) {
      for (auto i = 1; i <= n; ++i)
        v2[i] = ((long)v1[i] + v1[i - 1] + v1[i + 1]) % 1000000007;
      swap(v1, v2);
    }
    return v1[1];
  }
};

int main() {
  Solution obj;
  printf("%d\n", obj.numWays(3, 2)); // expect: 4
  printf("%d\n", obj.numWays(2, 4)); // expect: 2
  printf("%d\n", obj.numWays(4, 2)); // expect: 8
}
