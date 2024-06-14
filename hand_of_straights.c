// 846. Hand of Straights
#include "leetcode.h"

/*
 * alice has some number of cards and she wants to rearrange the cards into
 * groups so that each group is of size 'groupSize' and consists of 'groupSize'
 * consecutive cards. given an integer array 'hand' where 'hand[i]' is the value
 * written on the i'th card and an integer 'groupSize', return true if she can
 * rearrange the cards or false otherwise.
 */

struct pair {
  int num;
  int cnt;
};

int cmp(const void *a, const void *b) {
  return *(const int *)a - *(const int *)b;
}

bool isNStraightHand(int *hand, int handSize, int groupSize) {
  if (handSize % groupSize)
    return false;
  if (groupSize == 1)
    return true;
  qsort(hand, handSize, sizeof(int), cmp);
  struct pair *arr = (struct pair *)calloc(handSize, sizeof(struct pair));
  arr[0].num = hand[0];
  arr[0].cnt = 1;
  int idx = 0;
  for (int i = 1; i < handSize; i++) {
    if (hand[i] != arr[idx].num)
      idx++;
    arr[idx].num = hand[i];
    arr[idx].cnt++;
  }
  int pos = 0;
  for (int i = 0; i < handSize; i++) {
    while (pos < idx && !arr[pos].cnt)
      pos++;
    if (arr[pos].num == hand[i] && arr[pos].cnt)
      for (int j = 0; j < groupSize; j++) {
        int tar = hand[i] + j;
        if (arr[pos + j].cnt && arr[pos + j].num == tar)
          arr[pos + j].cnt--;
        else {
          free(arr);
          return false;
        }
      }
  }
  free(arr);
  return true;
}

int main() {
  int h1[] = {1, 2, 3, 6, 2, 3, 4, 7, 8}, h2[] = {1, 2, 3, 4, 5};
  printf("%d\n", isNStraightHand(h1, ARRAY_SIZE(h1), 3)); // expect: 1
  printf("%d\n", isNStraightHand(h2, ARRAY_SIZE(h2), 4)); // expect: 0
}
