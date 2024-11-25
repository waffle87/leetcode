// 773. Sliding Puzzle
#include "leetcode.h"

/*
 * on an empty 2 x 3 board there are five tiles labeled from 1 to 5 and an empty
 * square represented by 0. a move consists of choosing 0 and a 4-directionall
 * adjacent number and swapping it. the state of the board is solved if and only
 * if the board is '[[1,2,3],[4,5,0]]'. given the puzzle 'board', return the
 * least number of moves required so that the state of the board is solved. if
 * it is impossible for the state of the board to be solved, return -1
 */

class Solution {
public:
  int slidingPuzzle(vector<vector<int>> &board) {
    string begin = "", end = "123450";
    vector<vector<int>> moves = {{1, 3}, {0, 2, 4}, {1, 5},
                                 {0, 4}, {1, 3, 5}, {2, 4}};
    for (int i = 0; i < board.size(); i++)
      for (int j = 0; j < board[0].size(); j++)
        begin += to_string(board[i][j]);
    unordered_set<string> vis;
    vis.insert(begin);
    queue<pair<string, int>> qp;
    qp.push({begin, 0});
    while (!qp.empty()) {
      auto p = qp.front();
      qp.pop();
      string curr = p.first;
      int dist = p.second, idx = curr.find("0");
      if (curr == end)
        return dist;
      for (auto &i : moves[idx]) {
        string next = curr;
        swap(next[idx], next[i]);
        if (!vis.count(next)) {
          vis.insert(next);
          qp.push({next, dist + 1});
        }
      }
    }
    return -1;
  }
};

int main() {
  Solution obj;
  vvd(int) b1 = {{1, 2, 3}, {4, 0, 5}}, b2 = {{1, 2, 3}, {5, 4, 0}},
           b3 = {{4, 1, 2}, {5, 0, 3}};
  printf("%d\n", obj.slidingPuzzle(b1)); // expect 1
  printf("%d\n", obj.slidingPuzzle(b2)); // expect -1
  printf("%d\n", obj.slidingPuzzle(b3)); // expect 5
}
