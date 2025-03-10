// 904. Fruit Into Baskets
#include "leetcode.h"

/*
 * you are visiting a farm that has a single row of fruit trees arranged from
 * left t oright. the trees are represented by an integer array 'fruits' where
 * 'fruits[i]' is the type of fruit the i'th tree produces. you want to collect
 * as much fruit as possible. however, the owner has some strict rules that you
 * must follow: you can only have two baskets and each can only hoold a single
 * type of fruit (unlimited quantity). starting from any tree, you must pick
 * exacty one fruit from every tree while moving to the right. once you reach a
 * tree with fruit that cannot fit in your baskets, you must stop. given the int
 * array 'fruits', return the maximum number of fruits you can pick
 */

class Solution {
public:
  int totalFruit(vector<int> &fruits) {
    int n = fruits.size(), ans = 0;
    unordered_map<int, int> cnt;
    for (int l = 0, r = 0; r < n; ++r) {
      cnt[fruits[r]]++;
      while (cnt.size() > 2) {
        if (--cnt[fruits[l]] == 0)
          cnt.erase(fruits[l]);
        ++l;
      }
      ans = max(ans, r - l + 1);
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> fruits1 = {1, 2, 1}, fruits2 = {0, 1, 2, 2},
              fruits3 = {1, 2, 3, 2, 2};
  cout << obj.totalFruit(fruits1) << endl; // expect: 3
  cout << obj.totalFruit(fruits2) << endl; // expect: 3
  cout << obj.totalFruit(fruits3) << endl; // expect: 4
}
