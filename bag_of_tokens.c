// 948. Bag of Tokens
#include "leetcode.h"

/*
 * you have an initial power of 'power', an initial score of 0, and a bag of
 * 'tokens' where 'tokens[i]' is the value of the i'th token (0-indexed). your
 * goal is to maximise your total score by potentially playing each token in one
 * of two ways: -if your current power is at least 'tokens[i]', you may play the
 * i'th token face up, losing 'tokens[i]' power and gaining one score
 * - if your current score is at least one, you may play the i'th token face
 * down, gaining 'tokens[i]' power and losing score 1 each token may be played
 * at most once and in any order. you do not have to play all the tokens. return
 * the largest possible score you can achieve after playing any number of token.
 */

int cmp(const void *a, const void *b) {
  return *(const int *)a - *(const int *)b;
}

int bagOfTokensScore(int *tokens, int tokens_size, int power) {
  if (!tokens_size)
    return 0;
  qsort(tokens, tokens_size, sizeof(int), cmp);
  int left = 0, right = tokens_size - 1, cnt = 0;
  while (left < right) {
    if (tokens[left] <= power) {
      power -= tokens[left++];
      cnt++;
    } else {
      if (!cnt)
        break;
      power += tokens[right--];
      cnt--;
    }
  }
  if (tokens[left] <= power)
    cnt++;
  return cnt;
}

int main() {
  int t1[] = {100}, t2[] = {100, 200};
  printf("%d\n", bagOfTokensScore(t1, 1, 50));  // expect: 0
  printf("%d\n", bagOfTokensScore(t2, 2, 200)); // expect: 2
}
