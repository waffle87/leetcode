#include "leetcode.h"

class KthLargest {
private:
  int k;
  priority_queue<int, vector<int>, greater<int>> pq;

public:
  KthLargest(int k, vector<int> &nums) {
    this->k = k;
    auto endPointer = nums.begin() + min(k, nums.size());
    pq = priority_queue<int, vector<int>, greater<int>>(nums.begin(),
                                                        endPointer);
    for (int i = k; i < nums.size(); ++i) {
      pq.push(nums[i]);
      pq.pop();
    }
  }
  int add(int val) {
    pq.push(val);
    if (pq.size() > k)
      pq.pop();
    return pq.top();
  }
};

int main() {
  vector<int> nums({4, 5, 8, 2}), stream({3, 5, 10, 9, 4});
  KthLargest *obj = new KthLargest(3, nums);
  for (auto num : stream)
    cout << obj->add(num) << ' ';
}
