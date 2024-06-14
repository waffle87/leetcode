#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int unionFind(int *u, int val) {
  if (u[val] == val)
    return val;
  return unionFind(u, u[val]);
}

bool unionSet(int *u, int a, int b) {
  int findA = unionFind(u, a), findB = unionFind(u, b);
  if (findA == findB)
    return false;
  if (findA < findB)
    u[findB] = u[findA];
  else
    u[findA] = u[findB];
  return true;
}

char *smallestEquivalentString(char *s1, char *s2, char *baseStr) {
  int *table = malloc(26 * sizeof(int));
  for (int i = 0; i < 26; i++)
    table[i] = i;
  for (int i = 0; i < strlen(s1); i++)
    unionSet(table, s1[i] - 'a', s2[i] - 'a');
  int ansLen = strlen(baseStr);
  char *ans = malloc((ansLen + 1) * sizeof(int));
  ans[ansLen] = '\0';
  for (int i = 0; i < ansLen; i++)
    ans[i] = unionFind(table, baseStr[i] - 'a') + 'a';
  return ans;
}

int main() {
  printf("%s\n", smallestEquivalentString("parker", "morris",
                                          "parser")); // expect: makkek
  printf("%s\n",
         smallestEquivalentString("hello", "world", "hold")); // expect: hdld
  printf("%s\n", smallestEquivalentString("leetcode", "programs",
                                          "sourcecode")); // expect: aauaaaaada
}
