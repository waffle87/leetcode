// 1233. Remove Sub-Folders from the Filesystem
#include "leetcode.h"

/*
 * given a list of folders 'folder', return the folders after removing all the
 * sub-folders in those folders. you may return the answer in any order. if a
 * 'folder[i]' is located within another 'folder[j]', it is called a sub-folder
 * of it. a sub-folder of 'folder[j]' must start with 'folder[j]', followed by
 * '/'. the format of a path is one ormore concatenated strings of the form: '/'
 * followed by one or more lowercase english letters.
 */

class Solution {
public:
  vector<string> removeSubfolders(vector<string> &folder) {
    sort(folder.begin(), folder.end());
    vector<string> ans;
    for (auto i : folder) {
      if (!ans.size()) {
        ans.push_back(i);
        continue;
      }
      string parent = ans[ans.size() - 1];
      if (i.substr(0, parent.size() + 1) != parent + '/')
        ans.push_back(i);
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<string> f1 = {"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"},
                 rsf1 = obj.removeSubfolders(f1);
  vector<string> f2 = {"/a", "/a/b/c", "/a/b/d"},
                 rsf2 = obj.removeSubfolders(f2);
  vector<string> f3 = {"/a/b/c", "/a/b/ca", "/a/b/d"},
                 rsf3 = obj.removeSubfolders(f3);
  for (int i = 0; i < rsf1.size(); i++)
    cout << rsf1[i] << ' '; // expect: ["/a","/c/d","/c/f"]
  printf("\n");
  for (int i = 0; i < rsf2.size(); i++)
    cout << rsf2[i] << ' '; // expect: ["/a"]
  printf("\n");
  for (int i = 0; i < rsf3.size(); i++)
    cout << rsf3[i] << ' '; // expect: ["/a/b/c","/a/b/ca","/a/b/d"]
  printf("\n");
}
