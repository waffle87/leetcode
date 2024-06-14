// 373. Find K Pairs with Smallest Sums
#include "leetcode.h"

/*
 * given two integer arrays 'nums1 nums2' sorted in ascending order and an
 * integer k. define a pair '(u, v)' which consists of one element from the
 * first array and one element from the second array. return the 'k' pairs '(u1,
 * v1), (u2, v2), ..., (uk, vk)' with the smallest sums
 */

class Solution {
public:
  vvd(int) kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        pq;
    int n = nums1.size(), m = nums2.size();
    vvd(int) ans;
    for (int i = 0; i < n; i++)
      pq.push({nums1[i] + nums2[0], {i, 0}});
    while (!pq.empty() && k--) {
      pair<int, pair<int, int>> tp = pq.top();
      int x = tp.second.first, y = tp.second.second;
      pq.pop();
      ans.push_back({nums1[x], nums2[y]});
      if (y != m - 1)
        pq.push({nums1[x] + nums2[y + 1], {x, y + 1}});
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> n11 = {1, 7, 11}, n21 = {2, 4, 6};
  vector<int> n12 = {1, 1, 2}, n22 = {1, 2, 3};
  vector<int> n13 = {1, 2}, n23 = {3};
  for (auto i : obj.kSmallestPairs(n11, n21, 3))
    for (auto j : i)
      printf("%d ", j);
  printf("\n");
  for (auto i : obj.kSmallestPairs(n12, n22, 2))
    for (auto j : i)
      printf("%d ", j);
  printf("\n");
  for (auto i : obj.kSmallestPairs(n13, n23, 3))
    for (auto j : i)
      printf("%d ", j);
  printf("\n");
}
