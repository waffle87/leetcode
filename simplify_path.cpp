// 71. Simplify Path
#include "leetcode.h"

// given a string 'path', which is an absolute path (starting with a slash) to a
// file or directory in a unix-style file system, convert it to the simplified
// canonical path

class Solution {
public:
  string simplifyPath(string path) {
    vector<string> stack;
    string ans, tmp;
    stringstream p(path);
    while (getline(p, tmp, '/')) {
      if (tmp == "" || tmp == ".")
        continue;
      if (!stack.empty() && tmp == "..")
        stack.pop_back();
      else if (tmp != "..")
        stack.push_back(tmp);
    }
    for (auto s : stack)
      ans += "/" + s;
    return stack.empty() ? "/" : ans;
  }
};

int main() {
  Solution obj;
  cout << obj.simplifyPath("/home/") << endl;      // expect: /home/
  cout << obj.simplifyPath("/../") << endl;        // expect: /
  cout << obj.simplifyPath("/home//foo/") << endl; // expect: /home/foo
}
