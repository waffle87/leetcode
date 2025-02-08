// 2349. Design a Number Container System
#include "leetcode.h"

/*
 * design a number container system that can do the following: insert or replace
 * a number at the given index in the system or return the smallest index for
 * the given number in the system. implement the 'NumberContainers' class.
 */

class NumberContainers {
private:
  unordered_map<int, int> idxs;
  unordered_map<int, set<int>> nums;

public:
  void change(int index, int number) {
    auto i = idxs.find(index);
    if (i != end(idxs))
      nums[i->second].erase(index);
    idxs[index] = number;
    nums[number].insert(index);
  }
  int find(int number) {
    auto i = nums.find(number);
    return i == end(nums) || i->second.empty() ? -1 : *begin(i->second);
  }
};

int main() {
  NumberContainers *obj = new NumberContainers();
  printf("%d\n", obj->find(10)); // expect: -1
  obj->change(2, 10);
  obj->change(1, 10);
  obj->change(3, 10);
  obj->change(5, 10);
  printf("%d\n", obj->find(10)); // expect: 1
  obj->change(1, 20);
  printf("%d\n", obj->find(10)); // expect: 2
}
