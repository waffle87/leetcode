// 909. Snakes and Ladders
#include "leetcode.h"

typedef pair<int, int> pii;
class Solution {
public:
  int snakesAndLadders(vvd & board) {
    int rows = board.size(), cols = board[0].size();
    int target = rows * cols, r, c, p;
    vector<int> visited(rows * cols + 1); // cells on board starting from 1
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(0, 1));
    visited[1] = true;
    while (pq.size()) {
      auto stepPos = pq.top();
      pq.pop();
      int s = stepPos.first / 1000 + 1;
      for (int i = 1; i <= 6; i++) {
        auto p = stepPos.second + i;
        if (visited[p])
          continue;
        visited[p] = true;
        r = rows - (p - 1) / cols - 1;
        c = (p - 1) % cols;
        if ((rows - r - 1) % 2)
          c = cols - c - 1;
        int ladder = board[r][c];
        if (ladder > 0 && ladder <= target)
          p = ladder;
        if (p == target)
          return s;
        pq.push(make_pair(s * 1000 + 500 - p, p));
      }
    }
    return -1;
  }
};

int main() {
  Solution obj;
  vvd board1 = {{-1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1},
                     {-1, -1, -1, -1, -1, -1}, {-1, 35, -1, -1, 13, -1},
                     {-1, -1, -1, -1, -1, -1}, {-1, 15, -1, -1, -1, -1}};
  vvd board2 = {{-1, -1}, {-1, 3}};
  cout << obj.snakesAndLadders(board1) << endl; // expect: 4
  cout << obj.snakesAndLadders(board2) << endl; // expect: 1
}
