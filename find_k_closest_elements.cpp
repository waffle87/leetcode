// 658. Find K Closest Elements
#include "leetcode.h"

/*
 * given a sorted integer array 'arr', two integers 'k' and 'x', return the 'k'
 * closest integers to 'x' in the array. the result should also be sorted in
 * ascending order. an integer 'a' is closer to 'x' than an integer 'b' if '|a -
 * x| < |b - x|' or '|a - x| == |b - x|' and 'a < b'.
 */

class Solution {
public:
  vector<int> findClosestElements(vector<int> &arr, int k, int x) {
    int l = 0, r = arr.size() - k;
    while (l < r) {
      int m = (l + r) / 2;
      if (x - arr[m] > arr[m + k] - x)
        l = m + 1;
      else
        r = m;
    }
    return vector<int>(arr.begin() + l, arr.begin() + l + k);
  }
};

int main() {
  Solution obj;
  vector<int> a1 = {1, 2, 3, 4, 5}, a2 = {1, 2, 3, 4, 5};
  vector<int> fce1 = obj.findClosestElements(a1, 4, 3);
  vector<int> fce2 = obj.findClosestElements(a2, 4, -1);
  for (int i = 0; i < fce1.size(); i++)
    printf("%d ", fce1[i]); // expect: 1 2 3 4
  printf("\n");
  for (int i = 0; i < fce2.size(); i++)
    printf("%d ", fce2[i]); // expect: 1 2 3 4
  printf("\n");
}
