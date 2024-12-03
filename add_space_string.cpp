// 2109. Adding Spaces to a String
#include "leetcode.h"

/*
 * given a 0-indexed string 's' and a 0-indexed integer array 'spaces' that
 * describes the indices in the original string where spaces will be added. each
 * space should be inserted before the character at the given index. return the
 * modified string after the spaces have been added
 */

class Solution {
public:
  string addSpaces(string s, vector<int> &spaces) {
    int n = spaces.size(), m = s.size(), i = 0, j = 0;
    string ans = "";
    while (i < m) {
      if (j < n && i == spaces[j]) {
        ans += ' ';
        j++;
      }
      ans += s[i];
      i++;
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> s1 = {8, 13, 15}, s2 = {1, 5, 7, 9}, s3 = {0, 1, 2, 3, 4, 5, 6};
  cout << obj.addSpaces("LeetcodeHelpsMeLearn", s1)
       << endl; // expect: Leetcode Helps Me Learn
  cout << obj.addSpaces("icodeinpython", s2)
       << endl;                                 // expect: i code in py thon
  cout << obj.addSpaces("spacing", s3) << endl; // expect:  s p a c i n g
}
