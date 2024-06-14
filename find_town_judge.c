// 997. Find the Town Judge
#include "leetcode.h"

/*
 * in a town, there are 'n' people labeled from 1 to 'n'. there is a rumor that
 * one of these people is secretly the town judge. if the town judge exists,
 * then: the town judge trusts nobody. everybody (except the judge) trusts the
 * judge. given: array 'trust' where 'trust[i]' = [ai, bi] representing the the
 * person labeled ai trusts the person labeled bi. return label of judge, if
 * they exist.
 */

int findJudge(int n, int **trust, int trustSize, int *trustColSize) {
  int candidate = -1;
  bool arr[n + 1];
  for (int i = 0; i <= n; i++)
    arr[i] = false;
  for (int i = 0; i < trustSize; i++)
    arr[trust[i][0]] = true;
  for (int i = 1; i <= n; i++)
    if (!arr[i]) {
      candidate = i;
      break;
    }
  if (candidate == -1)
    return -1;
  for (int i = 1; i <= n; i++)
    arr[i] = false;
  for (int i = 0; i < trustSize; i++)
    if (trust[i][1] == candidate)
      arr[trust[i][0]] = true;
  bool ans = true;
  for (int i = 1; i <= n; i++) {
    if (i == candidate)
      continue;
    ans &= arr[i];
  }
  return ans ? candidate : -1;
}

int main() {
  int trust1[][2] = {{1, 2}}, trustColSize1[] = {1};
  int trust2[][2] = {{1, 3}, {2, 3}}, trustColSize2[] = {2};
  int trust3[][2] = {{1, 3}, {2, 3}, {3, 1}}, trustColSize3[] = {3};
  printf("%d\n", findJudge(2, trust1, 1, trustColSize1)); // expect: 2
  printf("%d\n", findJudge(3, trust2, 2, trustColSize1)); // expect: 3
  printf("%d\n", findJudge(3, trust3, 3, trustColSize1)); // expect: -1
}
