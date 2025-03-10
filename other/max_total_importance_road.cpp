// 2285. Maximum Total Importance of Roads
#include "leetcode.h"

/*
 * given an integer 'n' denoting the number of cities in a country. the cities
 * are numbered from 0 to 'n - 1'. you are also given a 2d integer array 'roads'
 * where 'roads{i} = {ai, bi}', where each value can only be used once. the
 * importance of a road is then defined as the sum of the values of the two
 * cities it connects. return the maximum total importance of all roads possible
 * after assigning the values optimally.
 */

class Solution {
public:
  long long maximumImportance(int n, vector<vector<int>> &roads) {
    long long cnt[50001] = {}, ans = 0;
    for (auto &i : roads) {
      ++cnt[i[0]];
      ++cnt[i[1]];
    }
    sort(begin(cnt), begin(cnt) + n);
    for (int i = 0; i < n; i++)
      ans += cnt[i] * (i + 1);
    return ans;
  }
};

int main() {
  Solution obj;
  vvd r1 = {{0, 1}, {1, 2}, {2, 3}, {0, 2}, {1, 3}, {2, 4}};
  vvd r2 = {{0, 3}, {2, 4}, {1, 3}};
  printf("%lld\n", obj.maximumImportance(5, r1)); // expect: 43
  printf("%lld\n", obj.maximumImportance(5, r2)); // expect: 20
}
