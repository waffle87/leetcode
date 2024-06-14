#include "leetcode.h"

class Solution {
public:
  int minimumRounds(vector<int> &tasks) {
    unordered_map<int, int> um;
    for (auto i : tasks)
      um[i]++;
    int count = 0;
    for (auto i : um) {
      int t = i.second;
      if (t == 1)
        return -1;
      count += t / 3;
      if (t % 3 != 0)
        count++;
    }
    return count;
  }
};

int main() {
  Solution obj;
  vector<int> tasks1 = {2, 2, 3, 3, 2, 4, 4, 4, 4, 4}, tasks2 = {2, 3, 3};
  cout << obj.minimumRounds(tasks1) << endl;
  cout << obj.minimumRounds(tasks2) << endl;
}
