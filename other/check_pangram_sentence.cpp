#include "leetcode.h"

class Solution {
public:
  bool checkIfPangram(string sentence) {
    set<int> s;
    for (auto &i : sentence)
      s.insert(i);
    return s.size() == 26;
  }
};

int main() {
  Solution obj;
  if (obj.checkIfPangram("thequickbrownfoxjumpsoverthelazydog"))
    cout << "true";
  else
    cout << "false";
}
