// 3494. Find the Minimum Amount of Time to Brew Potions
#include "leetcode.h"

/*
 * you are given two integer arrays 'skill' and 'mana' of length 'n' and 'm'
 * respectively. in a laboratory, 'n' wizards must brew 'm' potions in order.
 * each potion has a mana capacity 'mana[j]' and must pass through all the
 * wizards sequentially to be brewed properly. the time taken by the i'th wizard
 * on the j'th potion is 'time_ij = skill[i] * mana[j]'. since the brewing
 * process is delicate, a potion must be passed to the next wizard immediately
 * after the current wizard completes their work. this means the timing must be
 * synchronised so that each wizard begins working on a potion exactly when it
 * arrives. return the minimum amount of time required for the potions to be
 * brewed properly.
 */

long long minTime(int *skill, int skillSize, int *mana, int manaSize) {
  long long *pre = (long long *)calloc(skillSize + 1, sizeof(long long));
  for (int i = 1; i < skillSize; i++)
    pre[i] = pre[i - 1] + skill[i];
  long long sum = (long long)skill[0] * mana[0];
  for (int j = 1; j < manaSize; j++) {
    long long max = (long long)skill[0] * mana[j];
    for (int i = 1; i < skillSize; i++) {
      long long diff = pre[i] * mana[j - 1] - pre[i - 1] * mana[j];
      if (diff > max)
        max = diff;
    }
    sum += max;
  }
  int ans = pre[skillSize - 1] * mana[manaSize - 1];
  free(pre);
  return sum + ans;
}

int main() {
  int s1[] = {1, 5, 2, 4}, m1[] = {5, 1, 4, 2};
  int s2[] = {1, 1, 1}, m2[] = {1, 1, 1};
  int s3[] = {1, 2, 3, 4}, m3[] = {1, 2};
  printf("%lld\n",
         minTime(s1, ARRAY_SIZE(s1), m1, ARRAY_SIZE(m1))); // expect: 110
  printf("%lld\n", minTime(s2, ARRAY_SIZE(s2), m2, ARRAY_SIZE(m2))); // expect:
                                                                     // 5
  printf("%lld\n",
         minTime(s3, ARRAY_SIZE(s3), m3, ARRAY_SIZE(m3))); // expect: 21
}
