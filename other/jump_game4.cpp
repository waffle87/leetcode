// 1345. Jump Game IV
#include "leetcode.h"

/*
 * given array of integers 'arr', you are initially positioned at first index of
 * array. in one step, you can jump from index 'i' to index 'j'. return minimum
 * number of steps to reach lat index of array. notice, you cannot jump outside
 * of array at any time.
 */

class Solution {
public:
  int minJumps(vector<int> &arr) {
    int n = arr.size(), step = 0;
    unordered_map<int, vector<int>> idx_val;
    for (int i = 0; i < n; i++)
      idx_val[arr[i]].push_back(i);
    vector<bool> visited(n);
    visited[0] = true;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
      for (int size = q.size(); size > 0; --size) {
        int i = q.front();
        q.pop();
        if (i == n - 1)
          return step; // end of arr
        vector<int> next = idx_val[arr[i]];
        next.push_back(i - 1);
        next.push_back(i + 1);
        for (int j : next) {
          if (j >= 0 && j < n && !visited[j]) {
            visited[j] = true;
            q.push(j);
          }
        }
        next.clear();
      }
      step++;
    }
    return 0;
  }
};

int main() {
  Solution obj;
  vector<int> a1 = {100, -23, -23, 404, 100, 23, 23, 23, 3, 404};
  vector<int> a2 = {7}, a3 = {7, 6, 9, 6, 9, 6, 9, 7};
  cout << obj.minJumps(a1) << endl; // expect: 3
  cout << obj.minJumps(a2) << endl; // expect: 0
  cout << obj.minJumps(a3) << endl; // expect: 1
}
