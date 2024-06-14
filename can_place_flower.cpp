// 605. Can Place Flowers
#include "leetcode.h"

/*
 * you have long flowerbed in which some of the plots are
 * planted, and some are not. however, flowers cannot be planted
 * in adjacent plots. given an integer array 'flowerbed'
 * containing 0's and 1's, where 0 means empty and 1 means not empty
 * and an integer 'n', return if 'n' new flowers can be planted
 * in the 'flowerbed' without violating the no-adjacent rule
 */

class Solution {
public:
  bool canPlaceFlowers(vector<int> &flowerbed, int n) {
    flowerbed.insert(flowerbed.begin(), 0);
    flowerbed.push_back(0);
    int count = 0, s = flowerbed.size() - 1;
    for (int i = 1; i < s; i++)
      if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0 && flowerbed[i] == 0) {
        count++;
        flowerbed[i] = 1;
      }
    if (count >= n)
      return true;
    return false;
  }
};

int main() {
  Solution obj;
  vector<int> flowerbed = {1, 0, 0, 0, 1};
  printf("%d\n", obj.canPlaceFlowers(flowerbed, 1)); // expect: 1
  printf("%d\n", obj.canPlaceFlowers(flowerbed, 2)); // expect: 0
}
