// 1535. Find the Winner of an Array Game
#include "leetcode.h"

/*
 * given an integer array 'arr' of distinct integers and an integer 'k', a game
 * will be played between the first two elements of the array (ie. 'arr[0]' and
 * 'arr[1]'). in eah round of the game, we compare 'arr[0]' with 'arr[1]', the
 * larger integer wins and remains at position 0, and the smaller integer moves
 * to the end of the array. the game ends when an integer wins 'k' consecutive
 * rounds. return the integer which will win the game. it is guaranteed that
 * there will be a winner of the game.
 */

int getWinner(int *arr, int arr_size, int k) {
  int max = arr[0], cnt = 0;
  for (int i = 1; i < arr_size; i++) {
    if (arr[i] < max)
      cnt++;
    else {
      cnt = 1;
      max = arr[i];
    }
    if (cnt == k)
      return max;
  }
  return max;
}

int main() {
  int a1[] = {2, 1, 3, 5, 4, 6, 7}, a2[] = {3, 2, 1};
  printf("%d\n", getWinner(a1, ARRAY_SIZE(a1), 2));  // expect: 5
  printf("%d\n", getWinner(a2, ARRAY_SIZE(a2), 10)); // expect: 3
}
