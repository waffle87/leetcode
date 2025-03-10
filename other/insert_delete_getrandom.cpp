#include "leetcode.h"

class RandomizedSet {
public:
  bool insert(int val) {
    if (data.count(val))
      return false;
    data[val] = idxs.size();
    idxs.push_back(val);
    return true;
  }
  bool remove(int val) {
    if (!data.count(val))
      return false;
    int lst = idxs.back(), pos = data[val];
    data[lst] = pos;
    idxs[pos] = lst;
    data.erase(val);
    idxs.pop_back();
    return true;
  }
  int getRandom() { return idxs[rand() % idxs.size()]; }

private:
  unordered_map<int, int> data;
  vector<int> idxs;
};

int main() {
  RandomizedSet *obj = new RandomizedSet();
  bool param_1 = obj->insert(2);
  bool param_2 = obj->remove(1);
  int param_3 = obj->getRandom();
  cout << "param_1 (insert 2): ";
  if (param_1)
    cout << "true\n";
  else
    cout << "false\n";
  cout << "param_2 (remove 1): ";
  if (param_2)
    cout << "true\n";
  else
    cout << "false\n";
  cout << "param_3 (getRandom): " << param_3;
}
