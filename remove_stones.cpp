#include "leetcode.h"

class Solution {
public:
  int minStoneSum(vector<int> &piles, int k) {
    priority_queue<int> pq(piles.begin(), piles.end());
    int ans = accumulate(piles.begin(), piles.end(), 0);
    while (k--) {
      int i = pq.top();
      pq.pop();
      pq.push(i - i / 2);
      ans -= i / 2;
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> piles1 = {5, 4, 9}, piles2 = {4, 3, 6, 7};
  cout << obj.minStoneSum(piles1, 2); // expect: 12
  cout << endl;
  cout << obj.minStoneSum(piles2, 3); // expect: 12
}
