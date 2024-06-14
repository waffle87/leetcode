// 765. Couples Holding Hands
#include "leetcode.h"

/*
 * there are 'n' couples sitting '2n' seats arranged in a row and want to hold
 * hands. the people and seats are represented by an integer array 'row' where
 * 'row[i]' is the id of the person sitting in the i'th seat. the couples are
 * numbered in order, the first couple being '(0, 1)', the second couple being
 * '(2, 3)', and so on with the last couple being '(2n -2, 2n -1)'. return the
 * minimum number of swaps so that every couple is sitting side by side. a swap
 * consists of choosing any two people then they stand up and switch seats.
 */

class Solution {
public:
  int minSwapsCouples(vector<int> &row) {
    int ans = 0, n = row.size();
    vector<int> ptn(n, 0), pos(n, 0);
    for (int i = 0; i < n; i++) {
      ptn[i] = (!(i % 2) ? i + 1 : i - 1);
      pos[row[i]] = i;
    }
    for (int i = 0; i < n; i++)
      for (int j = ptn[pos[ptn[row[i]]]]; i != j; j = ptn[pos[ptn[row[i]]]]) {
        swap(row[i], row[j]);
        swap(pos[row[i]], pos[row[j]]);
        ans++;
      }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> r1 = {0, 2, 1, 3}, r2 = {3, 2, 0, 1};
  printf("%d\n", obj.minSwapsCouples(r1)); // expect: 1
  printf("%d\n", obj.minSwapsCouples(r2)); // expect: 0
}
