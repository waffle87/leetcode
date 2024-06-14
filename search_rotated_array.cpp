// 33. Search in Rotated Sorted Array
#include "leetcode.h"

/*
 * there is an integer array 'nums' sorted in ascending order (with distinct
 * values). prior to being passed to your function, 'nums' is possibly rotated
 * at an unknown pivot index 'k(1 <= k < nums.length)' such tht the resulting
 * array is '[nums[k], nums[k + 1], ..., nums[n - 1], nums[0], nums[1], ...,
 * nums[k - 1]]' (0-indxed). for example, '[0,1,2,4,5,6,7]' might be rotated at
 * pivot index 3 and become '[4,5,6,7,0,1,2]'. given the array 'nums' after the
 * possible rotation and an integer 'target', return the index of 'target' if it
 * is in 'nums', or -1 otherwise. you must write an algorithm with 'O(log n)'
 * runtime complexity
 */

class Solution {
public:
  int search(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
      int mid = (left + right) / 2;
      if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
        left = mid + 1;
      else
        right = mid;
    }
    return left == right && nums[left] == target ? left : -1;
  }
};

int main() {
  Solution obj;
  vector<int> n1 = {4, 5, 6, 7, 0, 1, 2}, n2 = {4, 5, 6, 7, 0, 1, 2}, n3 = {1};
  printf("%d\n", obj.search(n1, 0)); // expect: 4
  printf("%d\n", obj.search(n2, 3)); // expect: -1
  printf("%d\n", obj.search(n3, 0)); // expect: -1
}
