// 514. Freedom Trail
#include "leetcode.h"

/*
 * in the video game fallout 4, the quest "road to freeom" requires players to
 * reach a metal dial call the "freedom trail ring" and use the dial to spell a
 * specific keyword to open the door. given a string 'rint' that represents the
 * code engraved on the outer ring and another string 'key' that represents the
 * keyword that needs to be spelled, return the minimum number of steps to spell
 * all of the characters in the keyword. initially, the first character of the
 * ring is aligned at "12:00" diretion. you should spell all the characters in
 * 'key' one by rotating 'ring' clockwise or anticlockwise to make each
 * character of the string aligned at the "12:00" direction and then by pressing
 * the center button. at the stage of rotating the ring to spell the key
 * character 'key[i]' you can rotate the ring clockwise or anticlockwise by one
 * place, which counts as one step. the final purpose of the rotation is to
 * align one of 'ring's characters at "12:00" direction, where this character
 * must equal 'key[i]'
 */

class Solution {
public:
  int findRotateSteps(string ring, string key) {
    int n = ring.size();
    unordered_map<char, vector<int>> idx_map;
    for (int i = 0; i < n; ++i)
      idx_map[ring[i]].push_back(i);
    vector<vector<pair<int, int>>> dp(key.size());
    for (int i : idx_map[key[0]]) {
      int dist = min(i, n - i);
      dp[0].push_back({i, dist});
    }
    int min_sum = INT_MAX;
    for (int i = 1; i < key.size(); ++i) {
      for (int idx : idx_map[key[i]]) {
        int min_dist = INT_MAX;
        for (auto &pair : dp[i - 1]) {
          int abs_dist = abs(pair.first - idx);
          int dist = min(abs_dist, n - abs_dist);
          min_dist = min(min_dist, dist + pair.second);
        }
        dp[i].push_back({idx, min_dist});
        if (i == key.size() - 1)
          min_sum = min(min_dist, min_sum);
      }
    }
    return min_sum + key.size();
  }
};

int main() {
  Solution obj;
  printf("%d\n", obj.findRotateSteps("godding", "gd"));      // expect: 4
  printf("%d\n", obj.findRotateSteps("godding", "godding")); // expect: 13
}
