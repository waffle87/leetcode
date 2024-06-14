// 1138. Alphabet Board Path
#include "leetcode.h"

/*
 * on an alphabet board, we start position [0,0], corresponding to character
 * 'board[0][0]'. here, 'board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy",
 * "z"]' as show in the diagram (see page). return a sequence of moves that
 * makes our answer equal to 'target' in the minimum numbe of moves. (in any
 * order/path)
 */

class Solution {
public:
  string alphabetBoardPath(string target) {
    unordered_map<char, pair<int, int>> mp;
    for (int i = 0; i < 26; ++i)
      mp[i + 'a'] = {i / 5, i % 5};
    target = 'a' + target;
    string path;
    int dx = 0, dy = 0;
    for (int i = 1; i < target.size(); ++i) {
      auto curr = mp[target[i]];
      auto prev = mp[target[i - 1]];
      dx = curr.first - prev.first;
      dy = curr.second - prev.second;
      if (dy < 0)
        path += string(-dy, 'L');
      if (dx < 0)
        path += string(-dx, 'U');
      if (dy > 0)
        path += string(dy, 'R');
      if (dx > 0)
        path += string(dx, 'D');
      path += '!';
    }
    return path;
  }
};

int main() {
  Solution boj;
  cout << boj.alphabetBoardPath("leet") << endl; // expect: DDR!UURRR!!DDD!
  cout << boj.alphabetBoardPath("code") << endl; // expect: RR!DDRR!UUL!R!
}
