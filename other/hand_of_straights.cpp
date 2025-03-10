#include "leetcode.h"

class Solution {
public:
  bool isNStraightHand(vector<int> &hand, int groupSize) {
    if (hand.size() % groupSize != 0)
      return false;
    map<int, int> m;
    for (auto &card : hand)
      m[card]++;
    for (int i = 0; i < groupSize; i++) {
      int curr = m.begin()->first;
      if (m[curr + i] == 0)
        return false;
      else if (--m[curr + i] < 1)
        m.erase(curr + i);
    }
    return true;
  }
};

int main() {
  Solution obj;
  vector<int> hand = {1, 2, 3, 6, 2, 3, 4, 7, 8};
  int groupSize = 3;
  if (obj.isNStraightHand(hand, groupSize))
    cout << "true";
  else
    cout << "false";
}
