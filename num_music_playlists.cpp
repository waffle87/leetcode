// 920. Number of Music Playlists
#include "leetcode.h"

/*
 * your music player contains 'n' different songs. you want to listen to 'goal'
 * songs (not necessarily different) during your trip. to avoid boredom, you
 * will create a playlist so that:
 * - every song is played at least once
 * - a song can only be played again only if 'k' other songs have been played
 * given 'n, goal, k', return the number of possible playlists that you can
 * create. since the answer can be very large, return it modulo 10^9+7
 */

class Solution {
  const int mod = 1e9 + 7;
  long long solve(int n, int goal, int k, vvd(int) & dp) {
    if (!n && !goal)
      return 1;
    if (!n || !goal)
      return 0;
    if (dp[n][goal] != -1)
      return dp[n][goal];
    long long pick = solve(n - 1, goal - 1, k, dp) * n;
    long long skip = solve(n, goal - 1, k, dp) * max(n - k, 0);
    return dp[n][goal] = (pick + skip) % mod;
  }

public:
  int numMusicPlaylists(int n, int goal, int k) {
    vvd(int) dp(n + 1, vector<int>(goal + 1, -1));
    return solve(n, goal, k, dp);
  }
};

int main() {
  Solution obj;
  printf("%d\n", obj.numMusicPlaylists(3, 3, 1)); // expect: 6
  printf("%d\n", obj.numMusicPlaylists(2, 3, 0)); // expect: 6
  printf("%d\n", obj.numMusicPlaylists(2, 3, 1)); // expect: 2
}
