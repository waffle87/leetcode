#include "leetcode.h"

class Solution {
public:
  bool validUtf8(vector<int> &data) {
    int m1 = 0x80, m2 = 0x20, m3 = 0x10, m4 = 0x08, m5 = 0xC0;
    for (int i = 0; i < data.size(); i++) {
      if ((m5 & data[i]) == m1)
        return false;
      int bytes{0};
      if ((m1 & data[i]) == 0)
        continue;
      else if ((m2 & data[i]) == 0)
        bytes = 1;
      else if ((m3 & data[i]) == 0)
        bytes = 2;
      else if ((m4 & data[i]) == 0)
        bytes = 3;
      else
        return false;
      while (bytes--) {
        i++;
        if (i >= data.size() || ((m5 & data[i]) != m1))
          return false;
      }
    }
    return true;
  }
};

int main() {
  Solution obj;
  vector<int> data = {197, 130, 1};
  if (obj.validUtf8(data))
    cout << "true";
  else
    cout << "false";
}
