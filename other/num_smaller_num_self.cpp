#include "leetcode.h"

class Solution {
public:
  vector<int> countSmaller(vector<int> &nums) {
    int n = nums.size();
    vector<pair<int, int>> vp(n);
    vector<int> count(n, 0);
    for (int i = 0; i < n; i++)
      vp[i] = make_pair(nums[i], i);
    sort(count, vp, 0, n - 1);
    return count;
  }

private:
  void merge(vector<int> &count, vector<pair<int, int>> &vp, int left, int mid,
             int right) {
    vector<pair<int, int>> tmp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
      if (vp[i].first <= vp[j].first)
        tmp[k++] = vp[j++];
      else {
        count[vp[i].second] += right - j + 1;
        tmp[k++] = vp[i++];
      }
    }
    while (i <= mid)
      tmp[k++] = vp[i++];
    while (j <= right)
      tmp[k++] = vp[j++];
    for (int i = left; i <= right; i++)
      vp[i] = tmp[i - left];
  }
  void sort(vector<int> &count, vector<pair<int, int>> &vp, int left,
            int right) {
    if (left >= right)
      return;
    int mid = left + (right - left) / 2;
    sort(count, vp, left, mid);
    sort(count, vp, mid + 1, right);
    merge(count, vp, left, mid, right);
  }
};
