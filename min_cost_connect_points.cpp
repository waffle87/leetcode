#include "leetcode.h"

class Solution {
public:
  int minCostConnectPoints(vector<vector<int>> &points) {
    int n = points.size();
    vector<vector<int>> cost(n, vector<int>(n));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        cost[i][j] =
            abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
    int ans = solve(n, cost);
    return ans;
  }

private:
  int minNode(int n, int keyVal[], bool mstSet[]) {
    int mini = INT_MAX;
    int miniIdx = -1;
    for (int i = 0; i < n; i++)
      if (mstSet[i] == false && keyVal[i] < mini)
        mini = keyVal[i], miniIdx = i;
    return miniIdx;
  }
  int solve(int n, vector<vector<int>> &city) {
    int parent[n], keyVal[n];
    bool mstSet[n];
    for (int i = 0; i < n; i++) {
      keyVal[i] = numeric_limits<int>::max();
      mstSet[i] = false;
    }
    parent[0] = -1;
    keyVal[0] = 0;
    for (int i = 0; i < n - 1; i++) {
      int u = minNode(n, keyVal, mstSet);
      mstSet[u] = true;
      for (int j = 0; j < n; j++) {
        if (city[u][j] && mstSet[j] == false && city[u][j] < keyVal[j]) {
          keyVal[j] = city[u][j];
          parent[j] = u;
        }
      }
    }
    int cost = 0;
    for (int i = 1; i < n; i++)
      cost += city[parent[i]][i];
    return cost;
  }
};

int main() {}
