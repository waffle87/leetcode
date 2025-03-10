// 386. Lexicographical Numbers
#include "leetcode.h"

/*
 * given an integer 'n', return all the numbers in the range '[1, n]' sorted in
 * lexicographical order. you must write an algorithm that runs in O(n) time
 * complexity and uses O(1) extra space.
 */

class Solution {
public:
  vector<int> ans;
  vector<int> lexicalOrder(int n) {
    ans.resize(n);
    int pos = 0;
    for (int i = 1; i <= 9 && i <= n; i++)
      helper(i, n, pos);
    return ans;
  }

private:
  void helper(int i, int n, int pos) {
    ans[pos++] = i;
    int tmp;
    for (int j = 0; j <= 9; j++) {
      tmp = i * 10 + j;
      if (tmp > n)
        break;
      helper(tmp, n, pos);
    }
  }
};

int main() {
  Solution obj;
  vector<int> lo1 = obj.lexicalOrder(13), lo2 = obj.lexicalOrder(2);
  for (int i = 0; i < lo1.size(); i++)
    printf("%d ", lo1[i]); // expect: [1,10,11,12,13,2,3,4,5,6,7,8,9]
  printf("\n");
  for (int i = 0; i < lo2.size(); i++)
    printf("%d ", lo2[i]); // expect: [1,2]
  printf("\n");
}
