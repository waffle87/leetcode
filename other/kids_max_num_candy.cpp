// 1431. Kids With the Greatest Number of Candies
#include "leetcode.h"

/*
 * there are 'n' kids with candies. you are given an integer array 'candies',
 * where each 'candies[i]' represents the number of candies the i'th kid has,
 * and an integer 'extra' denoting the number of extra candies that you have.
 * return a boolean array 'result' of length 'n' where 'result[i]' is 1 if,
 * after giving the i'th kid all the 'extra', they will have the greatest number
 * of candies among all the kids, or 0 otherwise.
 */

class Solution {
public:
  vector<bool> kidsWithCandies(vector<int> &candies, int extra) {
    int m = 0;
    vector<bool> ans;
    for (int c : candies)
      m = max(m, c);
    for (int c : candies) {
      if (c + extra >= m)
        ans.push_back(1);
      else
        ans.push_back(0);
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> c1 = {2, 3, 5, 1, 3}, c2 = {4, 2, 1, 1, 2}, c3 = {12, 1, 12};
  for (auto i : obj.kidsWithCandies(c1, 3))
    cout << i << ' '; // expect: 1 1 1 0 1
  cout << endl;
  for (auto i : obj.kidsWithCandies(c2, 1))
    cout << i << ' '; // expect: 1 0 0 0 0
  cout << endl;
  for (auto i : obj.kidsWithCandies(c3, 10))
    cout << i << ' '; // expect: 1 0 1
  cout << endl;
}
