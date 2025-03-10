// 2542. Maximum Subsequence Score
#include "leetcode.h"

/*
 * given two 0-indexed integer arrays 'num1' and 'nums2' of equal length 'n' and
 * a positive integer 'k'. you must choose a subsequence of indices from 'nums1'
 * of length 'k'. for chosen indices 'i0, i1, ..., ik-1', your score is defined
 * as
 * - the sum of the selected elements from 'nums1' multiplied with the minimum
 * of the selected elements from 'nums2'
 * - it can defined simply as '(num1[i0] + nums1[i1] + ... + nums1[ik - 1]) *
 * min(nums2[i0], nums2[i1], ..., nums2[ik - 1])' return the maximum possible
 * score. a subseqnce of indices of an array is a set that can be derived from
 * the set '{0, 1, ..., n - 1}' by deleting no elements
 */

class Solution {
public:
  long long maxScore(vector<int> &nums1, vector<int> &nums2, int k) {
    int n = nums1.size();
    vector<pair<int, int>> ess(n);
    for (int i = 0; i < n; ++i)
      ess[i] = {nums2[i], nums1[i]};
    sort(rbegin(ess), rend(ess));
    long long sum_s = 0, ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto &[e, s] : ess) {
      pq.emplace(s);
      sum_s += s;
      if (pq.size() > k) {
        sum_s -= pq.top();
        pq.pop();
      }
      if (pq.size() == k)
        ans = max(ans, sum_s * e);
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> n11 = {1, 3, 3, 2}, n21 = {2, 1, 3, 4};
  vector<int> n12 = {4, 2, 3, 1, 1}, n22 = {7, 5, 10, 9, 6};
  printf("%lld\n", obj.maxScore(n11, n21, 3)); // expect: 12
  printf("%lld\n", obj.maxScore(n12, n22, 1)); // expect: 30
}
