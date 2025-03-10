// 2336. Smallest Number in Infinite Set
#include "leetcode.h"

/*
 * you have a set which contains all positive integers [1,2,3,...]
 * implement the SmallestInfiniteSet class:
 * - SmallestInfiniteSet() initialises the SmallestInfiniteSet
 *   object to contain all positive integers
 * - int popSmallest() removes and returns the smallest integer
 *   contained in the infinite set
 * - void addBack(int num) adds a positive integer num back into
 *   the infinite set, if it is not already in the infinite set
 */

class SmallestInfiniteSet {
public:
  int k = 1;
  unordered_map<int, int> um;
  SmallestInfiniteSet() {
    for (int i = 1; i <= 1000; i++)
      um[i] = i;
  }
  int popSmallest() {
    int d = um[k];
    um.erase(k);
    for (int i = k + 1; i <= 1000; i++) {
      if (um.find(i) != um.end()) {
        k = i;
        break;
      }
    }
    return d;
  }
  void addBack(int num) {
    um[num] = num;
    if (num < k)
      k = num;
  }
};

int main() {
  SmallestInfiniteSet *obj = new SmallestInfiniteSet();
  int param_1 = obj->popSmallest();
  obj->addBack(2);
}
