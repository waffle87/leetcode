// 953. Verifying an Alien Dictionary
#include "leetcode.h"

/*
 * in an alien language, they also use english lowercase letters but in
 * different 'order'. the 'order' of the alphabet is some permutation of
 * lowercase letters. given a sequence of 'words' written in the alien language,
 * and the 'order' of the alphabet, return 1 if and only if the given 'words'
 * are sorted lexicographically in this alien language.
 */

class Solution {
public:
  bool isAlienSorted(vector<string> &words, string order) {
    size_t indices[26]{};
    for (size_t i = 0; i < order.size(); ++i)
      indices[order[i] - 'a'] = i;
    return is_sorted(words.begin(), words.end(),
                     [&indices](const string &w1, const string &w2) {
                       auto l1 = w1.size(), l2 = w2.size();
                       for (auto i = 0; i < min(l1, l2); ++i) {
                         auto c1 = w1[i], c2 = w2[i];
                         if (c1 != c2)
                           return indices[c1 - 'a'] < indices[c2 - 'a'];
                       }
                       return l1 < l2;
                     });
  }
};

int main() {
  Solution obj;
  vector<string> words1 = {"hello", "leetcode"};
  vector<string> words2 = {"word", "world", "row"};
  vector<string> words3 = {"apple", "app"};
  cout << obj.isAlienSorted(words1, "hlabcdefgijkmnopqrstuvwxyz")
       << endl; // expect: 1
  cout << obj.isAlienSorted(words2, "worldabcefghijkmnpqstuvxyz")
       << endl; // expect: 0
  cout << obj.isAlienSorted(words3, "abcdefghijklmnopqrstuvwxyz")
       << endl; // expect: 0
}
