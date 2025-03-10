#include "leetcode.h"

class MedianFinder {
public:
  void addNum(int num) {
    small.push(num);
    large.push(-small.top());
    small.pop();
    if (small.size() < large.size()) {
      small.push(-large.top());
      large.pop();
    }
  }
  double findMedian() {
    if (small.size() > large.size())
      return small.top();
    else
      return (small.top() - large.top()) / 2.0;
  }

private:
  priority_queue<long> small, large;
};

int main() {
  MedianFinder *obj = new MedianFinder();
  obj->addNum(69);
  double param_2 = obj->findMedian();
}
