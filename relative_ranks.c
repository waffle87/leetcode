// 506. Relative Ranks
#include "leetcode.h"

/*
 * given an integer array score of size 'n' where 'score[i]' is the score of the
 * i'th athlete in a competition. all the scores are guaranteed to be unique.
 * the athletes are placed based on their scores where the first place athlete
 * has the highest score, the second place athlet has the second highest score,
 * and so on. return an array 'ans' of size 'n' where 'ans[i]' is the rank of
 * the i'th athlete.
 */

struct pair {
  int idx;
  int score;
};

int cmp(const void *a, const void *b) {
  struct pair aa = *(const struct pair *)a;
  struct pair bb = *(const struct pair *)b;
  return bb.score - aa.score;
}

char **findRelativeRanks(int *score, int scoreSize, int *returnSize) {
  struct pair *arr = (struct pair *)calloc(scoreSize, sizeof(struct pair));
  for (int i = 0; i < scoreSize; i++) {
    arr[i].idx = i;
    arr[i].score = score[i];
  }
  qsort(arr, scoreSize, sizeof(struct pair), cmp);
  *returnSize = scoreSize;
  char **ans = (char **)malloc(*returnSize * sizeof(char *));
  for (int i = 0; i < *returnSize; i++)
    ans[i] = (char *)malloc(13);
  for (int i = 0; i < scoreSize; i++) {
    switch (i) {
    case 0:
      ans[arr[0].idx] = "Gold Medal";
      break;
    case 1:
      ans[arr[1].idx] = "Silver Medal";
      break;
    case 2:
      ans[arr[2].idx] = "Bronze Medal";
      break;
    default:
      sprintf(ans[arr[i].idx], "%d", i + 1);
    }
  }
  free(arr);
  return ans;
}

int main() {
  int s1[] = {5, 4, 3, 2, 1}, s2[] = {10, 3, 8, 9, 4}, rs1, rs2;
  char **frr1 = findRelativeRanks(s1, ARRAY_SIZE(s1), &rs1);
  char **frr2 = findRelativeRanks(s2, ARRAY_SIZE(s2), &rs2);
  for (int i = 0; i < rs1; i++)
    printf(
        "%s ",
        frr1[i]); // expect: "Gold Medal","Silver Medal","Bronze Medal","4","5"
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf(
        "%s ",
        frr2[i]); // expect: "Gold Medal","5","Bronze Medal","Silver Medal","4"
  printf("\n");
  free(frr1), free(frr2);
}
