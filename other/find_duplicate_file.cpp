#include "leetcode.h"

class Solution {
public:
  vvd(string) findDuplicate(vector<string> &paths) {
    unordered_map<string, vector<string>> files;
    vvd(string) ans;
    for (auto &path : paths) {
      int i = 0, j;
      while (path[i] != ' ')
        i++;
      string dir = path.substr(0, i), file, content;
      while (i++ < path.size()) {
        j = i;
        while (path[i] != '(')
          i++;
        file = path.substr(j, i - j);
        j = i;
        while (path[i++] != ')')
          ;
        content = path.substr(j, i - j);
        files[content].emplace_back(dir + '/' + file);
      }
    }
    for (auto &content : files)
      if (content.second.size() > 1)
        ans.push_back(move(content.second));
    return ans;
  }
};
