// 781. Rabbits in Forest
#include "leetcode.h"

/*
 * there is a forest with an unknown number of rabbits. we asked 'n' rabbits
 * "how many rabbithave the same colour as you?" and collected the answers in an
 * integer array 'answers' where 'answers[i]' is the answer of the i'th rabbit.
 * given the array 'answers', return the minimum number of rabbits that could be
 * in the forest.
 */

int numRabbits(int *answers, int answersSize) {
  int ans = 0;
  for (int i = 0; i < answersSize - 1; i++) {
    int freq = 0;
    if (answers[i] != -1 && answers[i])
      for (int j = i + 1; j < answersSize; j++) {
        if (answers[i] == answers[j]) {
          answers[j] = -1;
          freq++;
        }
        if (freq == answers[i])
          break;
      }
  }
  for (int i = 0; i < answersSize; i++)
    if (answers[i] != -1)
      ans += (answers[i] + 1);
  return ans;
}

int main() {
  int a1[] = {1, 1, 2}, a2[] = {10, 10, 10};
  printf("%d\n", numRabbits(a1, ARRAY_SIZE(a1))); // expect: 5
  printf("%d\n", numRabbits(a2, ARRAY_SIZE(a2))); // expect: 11
}
