#include "leetcode.h"

class Solution {
public:
  bool isPossible(vector<int> &target) {
    long total = 0;
    int i;
    priority_queue<int> pq(target.begin(), target.end());
    for (int i : target)
      total += i;
    while (true) {
      i = pq.top();
      pq.pop();
      total -= i;
      if (i == 1 || total == 1)
        return true;
      if (i < total || total == 0 || i % total == 0)
        return false;
      i %= total;
      total += i;
      pq.push(i);
    }
  }
};

int main() {
  Solution obj;
  vector<int> target = {9, 3, 5};
  cout << obj.isPossible(target);
}
