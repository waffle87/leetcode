#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    int start = 0, max = 0, end = height.size() - 1;
    while (start < end) {
      int x = end - start;
      int y = height[start] > height[end] ? height[end] : height[start];
      max = (x * y) > max ? (x * y) : max;
      if (height[start] > height[end])
        end--;
      else
        start++;
    }
    return max;
  }
};

int main() {}
