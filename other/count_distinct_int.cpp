// 2442. Count Number of Distinct Integers After Reverse Operations
#include "leetcode.h"

/*
 * array nums contains positive integers
 * take each integer in array and reverse its digits (eg. 13 -> 31)
 * then *add* it to end of array. return number of distinct integers.
 * [1,13,10,12,31] becomes [1,13,10,12,31,1,31,1,21,13]
 * and total num of distinct ints = 6
 */

class Solution {
public:
  int countDistinctIntegers(vector<int> &nums) {
    // unordered set constructor to insert 'nums'
    // note: a set only maintains unique values in it
    unordered_set<int> us(nums.begin(), nums.end());
    // find reverse of every num
    for (auto i : nums) {
      int n = 0;
      while (i) {
        int rem = i % 10;
        n = n * 10 + rem;
        i /= 10;
      }
      // insert (to end) reverse
      us.insert(n);
    }
    // we can simply return the size since
    // every element in a set is unique
    return us.size();
  }
};

int main() {
  Solution obj;
  vector<int> nums1 = {1, 13, 10, 12, 31}, nums2 = {2, 2, 2};
  cout << obj.countDistinctIntegers(nums1) << endl; // expect: 6
  cout << obj.countDistinctIntegers(nums2) << endl; // expect: 1
}
