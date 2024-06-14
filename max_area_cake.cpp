#include "leetcode.h"

class Solution {
public:
  int maxArea(int h, int w, vector<int> &horizontalCuts,
              vector<int> &verticalCuts) {
    sort(horizontalCuts.begin(), horizontalCuts.end());
    sort(verticalCuts.begin(), verticalCuts.end());
    int maxH = max(horizontalCuts[0], h - horizontalCuts.back());
    int maxV = max(verticalCuts[0], w - verticalCuts.back());
    for (int i = 1; i < horizontalCuts.size(); i++)
      maxH = max(maxH, horizontalCuts[i] - horizontalCuts[i - 1]);
    for (int i = 1; i < verticalCuts.size(); i++)
      maxV = max(maxV, verticalCuts[i] - verticalCuts[i - 1]);
    return (int)((long)maxH * maxV % 1000000007);
  }
};

int main() {
  Solution obj;
  int h = 5, w = 4;
  vector<int> horizontalCuts = {1, 2, 4};
  vector<int> verticalCuts = {1, 3};
  cout << obj.maxArea(h, w, horizontalCuts, verticalCuts);
}
