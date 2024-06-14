// 1203. Sort Items by Groups Respecting Dependencies
#include "leetcode.h"

/*
 * there are 'n' items in each belonging to zero or one of 'm' groups where
 * 'group[i]' is the group that the i'th item beglons to and it's equal to '-1'
 * if the i'th item beglongs to no group. the items and the groups are zero
 * indexed. a group can have no item belonging to it. return a sorted list of
 * the items such that
 * - the items that belong to the same group are next to each other in the
 * sorted list
 * - there are some relations between these items where 'beforeItems[i]' is a
 * list containing all the items that should come before the i'th item in the
 * sorted array (to the left of the i'th item) return any solution if there is
 * more than one solution and return an empty list if there is no solution.
 */

class Solution {
  bool top_sort(vector<unordered_set<int>> &al, int i, vector<int> &res,
                vector<int> &stat) {
    if (stat[i])
      return stat[i] == 2;
    stat[i] = 1;
    for (auto n : al[i])
      if (!top_sort(al, n, res, stat))
        return false;
    stat[i] = 2;
    res.push_back(i);
    return true;
  }

public:
  vector<int> sortItems(int n, int m, vector<int> &group,
                        vvd(int) & beforeItems) {
    vector<int> ans(n), stat(n + 2 * m), ans_tmp;
    vector<unordered_set<int>> al(n + 2 * m);
    for (auto i = 0; i < n; ++i) {
      if (group[i] != -1) {
        al[n + group[i]].insert(i);
        al[i].insert(n + m + group[i]);
      }
      for (auto j : beforeItems[i]) {
        if (group[i] != -1 && group[i] == group[j])
          al[j].insert(i);
        else {
          auto ig = group[i] == -1 ? i : n + group[i];
          auto jg = group[j] == -1 ? j : n + m + group[j];
          al[jg].insert(ig);
        }
      }
    }
    for (int n = al.size() - 1; n >= 0; --n)
      if (!top_sort(al, n, ans_tmp, stat))
        return {};
    reverse(begin(ans_tmp), end(ans_tmp));
    copy_if(begin(ans_tmp), end(ans_tmp), ans.begin(),
            [&](int i) { return i < n; });
    return ans;
  }
};

int main() {
  Solution obj;
  vector<int> g1 = {-1, -1, 1, 0, 0, 1, 0, -1},
              g2 = {-1, -1, 1, 0, 0, 1, 0, -1};
  vvd(int) bi1 = {{}, {6}, {5}, {6}, {3, 6}, {}, {}, {}},
           bi2 = {{}, {6}, {5}, {6}, {3}, {}, {4}, {}};
  for (auto i : obj.sortItems(8, 2, g1, bi1))
    printf("%d ", i); // expect: [6,3,4,1,5,2,0,7]
  printf("\n");
  for (auto i : obj.sortItems(8, 2, g2, bi2))
    printf("%d ", i); // expect: []
  printf("\n");
}
