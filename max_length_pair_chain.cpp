// 646. Maximum Length of Pair Chain
#include "leetcode.h"

/*
 * given a n array of 'n' pairs, where 'pairs[i]= [lefti, righti]' and 'left[i]
 * < right[i]'. a pair 'p2 = [c, d]' follows a pair 'p1 = [a, b]' if 'b < c'. a
 * chain of pairs can be formed in this fashion. return the length of the
 * longest chain which can be formed. you do not need to use up all the given
 * intervals. you can select pairs in any order.
 */

class Solution {
  static bool cmp(vector<int> &a, vector<int> &b) { return a[1] < b[1]; }

public:
  int findLongestChain(vvd(int) & pairs) {
    sort(pairs.begin(), pairs.end(), cmp);
    int cnt = 0;
    for (int i = 0, j = 0; j < pairs.size(); j++)
      if (!j || pairs[i][1] < pairs[j][0]) {
        cnt++;
        i = j;
      }
    return cnt;
  }
};

int main() {
  Solution obj;
  vvd(int) p1 = {{1, 2}, {2, 3}, {3, 4}}, p2 = {{1, 2}, {7, 8}, {4, 5}};
  printf("%d\n", obj.findLongestChain(p1)); // expect: 2
  printf("%d\n", obj.findLongestChain(p2)); // expect: 3
}
