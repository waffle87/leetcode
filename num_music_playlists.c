// 920. Number of Music Playlists
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * your music player contains 'n' different songs. you want to listen to 'goal'
 * songs (not necessarily different) during your trip. to avoid boredom, you
 * will create a playlist so that:
 * - every song is played at least once
 * - a song can only be played again only if 'k' other songs have been played
 * given 'n, goal, k', return the number of possible playlists that you can
 * create. since the answer can be very large, return it modulo 10^9+7
 */

int numMusicPlaylists(int n, int goal, int k) {
  const int mod = 1e9 + 7;
  long **dp = (long **)calloc(goal + 1, sizeof(long *));
  for (int i = 0; i < goal + 1; i++)
    dp[i] = (long *)calloc(n + 1, sizeof(long));
  dp[0][0] = 1;
  for (int i = 1; i <= goal; i++)
    for (int j = 1; j <= n; j++) {
      dp[i][j] += (dp[i - 1][j - 1] * (n - (j - 1))) % mod;
      dp[i][j] += (dp[i - 1][j] * (long)fmax(0, j - k)) % mod;
      dp[i][j] %= mod;
    }
  int ans = dp[goal][n];
  for (int i = 0; i < goal + 1; i++)
    free(dp[i]);
  free(dp);
  return ans;
}

int main() {
  printf("%d\n", numMusicPlaylists(3, 3, 1)); // expect: 6
  printf("%d\n", numMusicPlaylists(2, 3, 0)); // expect: 6
  printf("%d\n", numMusicPlaylists(2, 3, 1)); // expect: 2
}
