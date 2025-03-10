// 2300. Successful Pairs of Spells and Potions
#include "leetcode.h"

/*
 * given two positive integer arrays 'spells' and 'potions', of length n and m
 * respectively where 'spells[i]' represents the strength of the i'th spell and
 * 'potions[j] represents the strength of the j'th potion. also given an integer
 * success. a spell and potion pair is considered successful if the product of
 * their strengths is at least 'success'. return an integer array 'pairs' of
 * lengthn where 'pairs[i]' is the number of potions that will form a successful
 * pair with the i'th spell.
 */

class Solution {
public:
  vector<int> successfulPairs(vector<int> &spells, vector<int> &potions,
                              long long success) {
    int m = potions.size();
    vector<int> ans;
    sort(potions.begin(), potions.end());
    for (auto i : spells) {
      int left = 0, right = m - 1, mid;
      while (left <= right) {
        mid = (left + right) >> 1;
        if ((long long)i * potions[mid] >= success)
          right = mid - 1;
        else
          left = mid + 1;
      }
      ans.push_back(m - left);
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> s1 = {5, 1, 3}, s2 = {3, 1, 2};
  vector<int> p1 = {1, 2, 4, 4, 5}, p2 = {8, 5, 8};
  for (auto i : obj.successfulPairs(s1, p1, 7))
    printf("%d ", i); // expec: 4 0 3
  printf("\n");
  for (auto i : obj.successfulPairs(s2, p2, 16))
    printf("%d ", i); // expec: 2 0 2
}
