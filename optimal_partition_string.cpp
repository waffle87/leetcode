// 2405. Optimal Partition of String
#include "leetcode.h"

/*
 * given a string 's', partition the string into one or more substrings such
 * that the characters in each substring are unique. that is, no letter appears
 * in a single substring more than once. return the minimum number of substrings
 * in such a partition note that each character should belong to exactly one
 * substring in a partition
 */

class Solution {
public:
  int partitionString(string s) {
    int cnt[26] = {}, ans = 1;
    for (int i = 0; i < s.size(); ++i) {
      if (cnt[s[i] - 'a']) {
        ++ans;
        fill(begin(cnt), end(cnt), 0);
      }
      ++cnt[s[i] - 'a'];
    }
    return ans;
  }
};

int main() {
  Solution obj;
  printf("%d\n", obj.partitionString("abacaba")); // expect: 4
  printf("%d\n", obj.partitionString("ssssss"));  // expect: 6
}
