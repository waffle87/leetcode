// 1539. Kth Missing Positive Number
#include "leetcode.h"

/*
 * given array 'arr' of positive integers sorted in a strictly increasing order,
 * and an integer 'k', return 'kth' positive integer missing from array -- o(log
 * n)
 */

class Solution {
public:
  int findKthPositive(vector<int> &arr, int k) {
    int l = 0, r = arr.size(), m;
    while (l < r) {
      m = (l + r) / 2;
      if (arr[m] - 1 - m < k)
        l = m + 1;
      else
        r = m;
    }
    return l + k;
  }
};

int main() {
  Solution obj;
  vector<int> a1 = {2, 3, 4, 7, 11}, a2 = {1, 2, 3, 4};
  cout << obj.findKthPositive(a1, 5) << endl; // expect: 9
  cout << obj.findKthPositive(a2, 2) << endl; // expect: 6
}
