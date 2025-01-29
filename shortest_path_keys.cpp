// 864. Shortest Path to Get All Keys
#include "leetcode.h"

/*
 * given an 'm x n' grid 'grid' where:
 * - '.' is an empty cell
 * - '#' is a wall
 * - '@' is the starting point
 * - lowercase letters represent keys
 * - uppercase letters represent locks
 * you start at the starting point and one move consists of walking one space in
 * one of the four cardinal directions. you cannot walk outside the grid, or
 * walk into a wall. if you walk over a key, you can pick it up and you cannot
 * walk over a lock unless you have its corresponding key. for some '1 <= k <=
 * 6', there is exactly one lowercase and one uppercase letter of the first 'k'
 * letters of the english alphabet in the grid. this means that there is exactly
 * one key for each lock, and one lock for each key; and also that the letters
 * used to represent the keys and locks were chosen in the same order as the
 * english alphabet. return the lowest number of moves to acquire all keys. if
 * it is impossible, return -1
 */

class Info {
public:
  pair<int, int> p;
  vector<int> keys;
  int cnt;
  Info(pair<int, int> p, vector<int> keys, int cnt) {
    this->p = p;
    this->keys = keys;
    this->cnt = cnt;
  }
  int get_state() {
    int state = 0;
    for (int i = 0; i < keys.size(); i++) {
      state <<= 1;
      state += keys[i];
    }
    return state;
  }
};

class Solution {
public:
  int shortestPathAllKeys(vector<string> &grid) {
    pair<int, int> start;
    int m = grid.size(), n = grid[0].size(), key_cnt = 0;
    if (!m)
      return -1;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '@')
          start = make_pair(i, j);
        else if (grid[i][j] >= 'a' && grid[i][j] <= 'f')
          key_cnt++;
      }
    queue<Info> q;
    vector<int> keys_start(key_cnt, 0);
    q.push(Info(start, keys_start, 0));
    int ans = -1;
    vector<vector<vector<int>>> vis;
    for (int i = 0; i < 1 << key_cnt; i++) {
      vvd tmp(m, vector<int>(n, 0));
      vis.push_back(tmp);
    }
    while (!q.empty()) {
      auto curr = q.front();
      q.pop();
      int state = curr.get_state();
      if (state == (1 << key_cnt) - 1) {
        ans = curr.cnt;
        break;
      }
      if (vis[state][curr.p.first][curr.p.second])
        continue;
      vis[state][curr.p.first][curr.p.second] = 1;
      int dx[] = {0, 1, 0, -1};
      int dy[] = {1, 0, -1, 0};
      for (int i = 0; i < 4; i++) {
        int xx = curr.p.first + dx[i];
        int yy = curr.p.second + dy[i];
        auto keys = curr.keys;
        auto cnt = curr.cnt + 1;
        if (xx >= 0 && xx < m && yy >= 0 && yy < n) {
          if (grid[xx][yy] >= 'a' && grid[xx][yy] <= 'f') {
            int no = grid[xx][yy] - 'a';
            keys[no] = 1;
          } else if (grid[xx][yy] >= 'A' && grid[xx][yy] <= 'F') {
            int no = grid[xx][yy] - 'A';
            if (!keys[no])
              continue;
          } else if (grid[xx][yy] == '#')
            continue;
          q.push(Info(make_pair(xx, yy), keys, cnt));
        }
      }
    }
    return ans;
  }
};

int main() {
  Solution obj;
  vector<string> g1 = {"@.a..", "###.#", "b.A.B"},
                 g2 = {"@..aA", "..B#.", "....b"}, g3 = {"@Aa"};
  printf("%d\n", obj.shortestPathAllKeys(g1)); // expect: 8
  printf("%d\n", obj.shortestPathAllKeys(g2)); // expect: 6
  printf("%d\n", obj.shortestPathAllKeys(g3)); // expect: -1
}
