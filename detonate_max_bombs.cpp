// 2101. Detonate the Maximum Bombs
#include "leetcode.h"

/*
 * given a list of bombs. the range of a bomb is defined as the area where its
 * effect can be felt. this area is in the shape of a circle with the center as
 * the location of the bomb. the bombs are represented by a 0-indexed 2d integer
 * array 'bombs' where 'bombs[i] = [xi, yi, ri]'. 'xi' and 'yi' denote the x and
 * y coordinates of the location of the i'th bomb, whereas 'ri' denotes the
 * radius of its range. you may choose to detonate a single bomb. when a bomb is
 * detonated, it will detonate all the bombs that lie in its range. these bombs
 * will further detonate the bombs that lie in their ranges. given the list of
 * 'bombs', return the max number of bombs that can be detonated
 */

class Solution {
  void dfs(vvd(int) & graph, vector<bool> &visited, int c, int i) {
    visited[i] = true;
    c++;
    for (int j = 0; j < graph[i].size(); j++)
      if (!visited[graph[i][j]])
        dfs(graph, visited, c, graph[i][j]);
  }

public:
  int maximumDetonation(vvd(int) & bombs) {
    int n = bombs.size(), ans = INT_MIN;
    vvd(int) graph(n);
    for (int i = 0; i < n; i++) {
      long long int x1, y1, r1;
      x1 = bombs[i][0];
      y1 = bombs[i][1];
      r1 = bombs[i][2];
      for (int j = 0; j < n; j++)
        if (i != j) {
          long long int x2, y2, r2;
          x2 = abs(x1 - bombs[j][0]);
          y2 = abs(y1 - bombs[j][1]);
          if (x2 * x2 + y2 * y2 <= r1 * r1)
            graph[i].push_back(j);
        }
    }
    for (int i = 0; i < n; i++) {
      int c = 0;
      vector<bool> visited(n, false);
      dfs(graph, visited, c, i);
      ans = max(ans, c);
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vvd(int) b1 = {{2, 1, 3}, {6, 1, 4}};
  vvd(int) b2 = {{1, 1, 5}, {10, 10, 5}};
  vvd(int) b3 = {{1, 2, 3}, {2, 3, 1}, {3, 4, 2}, {4, 5, 3}, {5, 6, 4}};
  printf("%d\n", obj.maximumDetonation(b1)); // expect: 2
  printf("%d\n", obj.maximumDetonation(b2)); // expect: 1
  printf("%d\n", obj.maximumDetonation(b3)); // expect: 5
}
