// 503. Next Greater Element II
#include "leetcode.h"

/*
 * given a circular integer array 'nums' (ie. the next element 'nums[nums.length
 * - 1]' is 'nums[0]') return the next greater number for every element in
 * 'nums'. the next greater number of a number 'x' is the first greater number
 * to its traversing-order next in the array, which means you could search
 * circularly to find its next greater number. if it doesn't exist, return -1
 */

class Solution {
public:
  vector<int> nextGreatestElements(vector<int> &nums) {
    int n = nums.size();
    nums.resize(n * 2);
    for (int i = n; i < n * 2; i++)
      nums[i] = nums[i - n];
    vector<int> ans(n, -1);
    stack<int> s;
    for (int i = 0; i < n * 2; i++) {
      int elem = nums[i];
      while (!s.empty() && elem > nums[s.top()]) {
        if (s.top() >= n)
          s.top() = s.top() - n;
        ans[s.top()] = elem;
        s.pop();
      }
      s.push(i);
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> n1 = {1, 2, 1}, n2 = {1, 2, 3, 4, 3};
  for (auto i : obj.nextGreatestElements(n1))
    printf("%d ", i); // expect: 2 -1 2
  printf("\n");
  for (auto i : obj.nextGreatestElements(n2))
    printf("%d ", i); // expect: 2 3 4 -1 4
}
