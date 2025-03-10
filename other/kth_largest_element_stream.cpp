// 703. Kth Largest Element in a Stream
#include "leetcode.h"

/*
 * design a class to find the k'th largest element in a stream. note that it is
 * the k'th largest element in the sorted order, not the k'th distinct element.
 * implement 'KthLargest' class:
 * - KthLargest(int k, int[] nums) initialises the objct with the integer 'k'
 * and the stream of integers 'nums' int add(int val) appends the integer 'val'
 * to the stream and returns the element representing the k'th largest stream
 * element
 */

class KthLargest {
  priority_queue<int, vector<int>, greater<int>> pq;
  int size;

public:
  KthLargest(int k, vector<int> &nums) {
    size = k;
    for (int i = 0; i < nums.size(); i++) {
      pq.push(nums[i]);
      if (pq.size() > k)
        pq.pop();
    }
  }
  int add(int val) {
    pq.push(val);
    if (pq.size() > size)
      pq.pop();
    return pq.top();
  }
};

int main() {
  vector<int> nums = {4, 5, 8, 2};
  KthLargest *obj = new KthLargest(3, nums);
  printf("%d\n", obj->add(3));  // expect: 4
  printf("%d\n", obj->add(5));  // expect: 5
  printf("%d\n", obj->add(10)); // expect: 5
  printf("%d\n", obj->add(9));  // expect: 8
  printf("%d\n", obj->add(4));  // expect: 8
}
