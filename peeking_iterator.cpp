#include "leetcode.h"

class Iterator {
  struct Data;
  Data *data;

public:
  Iterator(const vector<int> &nums);
  Iterator(const Iterator &iter);
  int next();
  bool hasNext() const;
};

class PeekingIterator : public Iterator {
public:
  int nextVal;
  PeekingIterator(const vector<int> &nums) : Iterator(nums) {
    nextVal = Iterator::next();
  }
  int peek() { return nextVal; }
  int next() {
    int tmp = nextVal;
    if (Iterator::hasNext())
      nextVal = Iterator::next();
    else
      nextVal = NULL;
    return tmp;
  }
  bool hasNext() const { return (nextVal != NULL); }
};

int main() {}
