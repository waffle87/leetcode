// 852. Peak Index in a Mountain Array
#include "leetcode.h"

class Solution {
public:
  int peakIndexInMountainArray(vector<int> &arr) {
    int left = 1, right = arr.size() - 1;
    while (left < right) {
      int mid = (left + right) / 2;
      if (arr[mid] < arr[mid + 1])
        left = mid + 1;
      else
        right = mid;
    }
    return left;
  }
};

int main() {
  Solution obj;
  vector<int> a1 = {0, 1, 0}, a2 = {0, 2, 1, 0}, a3 = {0, 10, 5, 2};
  printf("%d\n", obj.peakIndexInMountainArray(a1)); // expect: 1
  printf("%d\n", obj.peakIndexInMountainArray(a2)); // expect: 1
  printf("%d\n", obj.peakIndexInMountainArray(a3)); // expect: 1
}
