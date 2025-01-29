// 2215. Find the Difference of Two Arrays
#include "leetcode.h"

/*
 * given two zero-indexed arrays 'n1' and 'n2', return a list
 * 'ans' of size 2 where:
 * 'ans[0]' is a list of all distinct integers in 'n1' which
 * are not present in 'n2'
 * 'ans[1]' is a list of all distinct integers in 'n2' which
 * are not present in 'n1'
 * note that the integers in the lists may be returned in any order
 */

class Solution {
public:
  vvd findDifference(vector<int> &n1, vector<int> &n2) {
    unordered_set<int> us1(begin(n1), end(n1)), us2(begin(n2), end(n2));
    vvd ans(2);
    for (int i : us1)
      if (!us2.count(i))
        ans[0].push_back(i);
    for (int i : us2)
      if (!us1.count(i))
        ans[1].push_back(i);
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> n11 = {1, 2, 3}, n21 = {2, 4, 6};
  vector<int> n12 = {1, 2, 3, 3}, n22 = {1, 1, 2, 2};
  vvd fd1 = obj.findDifference(n11, n21);
  vvd fd2 = obj.findDifference(n12, n22);
}
