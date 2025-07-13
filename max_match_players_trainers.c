// 2410. Maximum Matching of Players With Trainers
#include "leetcode.h"

/*
 * you are given a 0-indexed integer array 'players' where 'players[i]'
 * represents the ability of the i'th player. you are also given a 0-indexed
 * integer array 'trainers', where 'trainers[j]' represents the j'th  capacity
 * of the trainer. the i'th player can match with the j'th trainer if the
 * players ability is less than or equal to the trainers training capacity.
 * additionally, the i'th player can matchedwith at most one trainer, and the
 * j'th trainer can be matched with at most one player. return the maximum
 * number of matchings between 'players' and 'trainers' that satisfy these
 * conditions.
 */

int cmp(const void *a, const void *b) { return (*(int *)a) - (*(int *)b); }

int matchPlayersAndTrainers(int *players, int playersSize, int *trainers,
                            int trainersSize) {
  qsort(players, playersSize, sizeof(int), cmp);
  qsort(trainers, trainersSize, sizeof(int), cmp);
  int cnt = 0;
  for (int i = 0; i < trainersSize && cnt < playersSize; ++i)
    cnt += players[cnt] <= trainers[i];
  return cnt;
}

int main() {
  int p1[] = {4, 7, 9}, t1[] = {8, 2, 5, 8};
  int p2[] = {1, 1, 1}, t2[] = {10};
  printf("%d\n", matchPlayersAndTrainers(p1, ARRAY_SIZE(p1), t1,
                                         ARRAY_SIZE(t1))); // expect: 2
  printf("%d\n", matchPlayersAndTrainers(p2, ARRAY_SIZE(p2), t2,
                                         ARRAY_SIZE(t2))); // expect: 1
}
