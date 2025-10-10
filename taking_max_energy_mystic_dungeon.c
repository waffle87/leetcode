// 3147. Taking Maximum Energy From the Mystic Dungeon
#include "leetcode.h"

/*
 * in a mystic dungeon, 'n' magicians are standing in a line. each magician has
 * an attribute that gives you energe. some magicians can give you negative
 * energy, which means taking energy from you. you have been cursed in such a
 * way that after absorbing energy from magician 'i', you will be instantly
 * transported to magician '(i + k)'. this process will be repeated until you
 * reach the magician where '(i + k)' does not exist. in other words, you will
 * choose a starting point until you reach the end of the magicians sequence,
 * absorbing all the energy during the journey. you are given an array 'energy'
 * and an integer 'k'. return the maximum possible energy you can gain. note
 * that when you are reach a magician, you must take energy from them, whether
 * it is positive or negative.
 */

int maximumEnergy(int *energy, int energySize, int k) {
  int *dp = (int *)malloc(energySize * sizeof(int));
  int ans = INT_MIN;
  for (int i = energySize - 1; i >= 0; --i) {
    int next = (i + k < energySize) ? dp[i + k] : 0;
    dp[i] = energy[i] + next;
    if (dp[i] > ans)
      ans = dp[i];
  }
  free(dp);
  return ans;
}

int main() {
  int e1[] = {5, 2, -10, -5, -1}, e2[] = {-2, -3, -1};
  printf("%d\n", maximumEnergy(e1, ARRAY_SIZE(e1), 3)); // expect: 3
  printf("%d\n", maximumEnergy(e2, ARRAY_SIZE(e2), 2)); // expect: -1
}
