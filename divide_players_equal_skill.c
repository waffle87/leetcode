// 2491. Divide Players Into Teams of Equal Skill
#include "leetcode.h"

/*
 * you are given a positive integer array 'skill' of even length 'n' where
 * 'skill[i]' denotes the skill of the i'th player. divide the players into 'n /
 * 2' teams of size '2' such that the total skill of each team is equal. the
 * chemistry of  team is equal to the product of the skills of the players on
 * that team. return the sum of the chemistry of all the teams, or return -1 if
 * there is no way to divide the players into teams such that the total skill of
 * each team is equal
 */

int cmp(const void *a, const void *b) { return *((int *)a) - *((int *)b); }

long long dividePlayers(int *skill, int skillSize) {
  long long ans = 0, team;
  qsort(skill, skillSize, sizeof(int), cmp);
  team = skill[0] + skill[skillSize - 1];
  for (int i = 0, j = skillSize - 1; i < j; i++, j--) {
    if (skill[i] + skill[j] != team)
      return -1;
    else
      ans += skill[i] * skill[j];
  }
  return ans;
}

int main() {
  int s1[] = {3, 2, 5, 1, 3, 4}, s2[] = {3, 4}, s3[] = {1, 1, 2, 3};
  printf("%lld\n", dividePlayers(s1, ARRAY_SIZE(s1))); // expect: 22
  printf("%lld\n", dividePlayers(s2, ARRAY_SIZE(s2))); // expect: 12
  printf("%lld\n", dividePlayers(s3, ARRAY_SIZE(s3))); // expect: -1
}
