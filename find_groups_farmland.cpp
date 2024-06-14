#include "leetcode.h"

class Solution {
public:
  vvd(int) findFarmland(vvd(int) & land) {
    int n = land.size(), m = land[0].size();
    vvd(int) ans;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (land[i][j] == 1) {
          if ((!i || !land[i - 1][j]) && (!j || !land[i][j - 1])) {
            int right = j, down = i;
            while (down + 1 < n && land[down + 1][j] == 1)
              down++;
            while (right + 1 < m && land[i][right + 1] == 1)
              right++;
            ans.push_back({i, j, down, right});
          }
        }
      }
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vvd(int) l1 = {{1, 0, 0},
                 {
                     0,
                     1,
                     1,
                 },
                 {0, 1, 1}};
  vvd(int) l2 = {{1, 1}, {1, 1}};
  for (auto i : obj.findFarmland(l1))
    for (auto j : i)
      printf("%d ", j); // expect: [[0,0,0,0],[1,1,2,2]]
  printf("\n");
  for (auto i : obj.findFarmland(l2))
    for (auto j : i)
      printf("%d ", j); // expect: [[0,0,1,1]]
}
