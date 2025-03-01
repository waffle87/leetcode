// 3265. Count Almost Equal Pairs I
#include "leetcode.h"

/*
 * you are given an array 'nums' consisting of positive integers. we call two
 * integers 'x' and 'y' in this problem almost equal if both integers can become
 * equal after performing the following operation at most once: choose either
 * 'x' or 'y' and swap any two digits within the chosen number. return the
 * number of indices 'i' and 'j' in 'nums' where 'i < j' such that 'nums[i]' and
 * 'nums[j]' are almost equal. note that it is allowed for an integer to have
 * leading zeros after performing an operation.
 */

struct hash {
  int num;
  int8_t count;
  UT_hash_handle hh;
};

int countPairs(int *nums, int numsSize) {
  int ans = 0, swapped, pow10[7] = {1000000, 100000, 10000, 1000, 100, 10, 1};
  struct hash *table = NULL, *item;
  for (int i = 0; i < numsSize; i++) {
    swapped = nums[i];
    HASH_FIND_INT(table, &swapped, item);
    if (item)
      ans += item->count++;
    else {
      item = (struct hash *)malloc(sizeof(struct hash));
      item->num = swapped;
      item->count = 1;
      HASH_ADD_INT(table, num, item);
    }
    for (int j = 0; j < 6; j++)
      for (int k = j + 1; k < 7; k++) {
        int n = swapped / pow10[j] % 10;
        int m = swapped / pow10[k] % 10;
        if (n != m) {
          swapped -= n * pow10[j];
          swapped += m * pow10[j];
          swapped -= m * pow10[k];
          swapped += n * pow10[k];
          HASH_FIND_INT(table, &swapped, item);
          ans += item ? item->count : 0;
          swapped -= n * pow10[k];
          swapped += m * pow10[k];
          swapped -= m * pow10[j];
          swapped += n * pow10[j];
        }
      }
  }
  HASH_CLEAR(hh, table);
  return ans;
}

int main() {
  int n1[] = {3, 12, 30, 17, 21}, n2[] = {1, 1, 1, 1, 1}, n3[] = {123, 231};
  printf("%d\n", countPairs(n1, ARRAY_SIZE(n1))); // expect: 2
  printf("%d\n", countPairs(n2, ARRAY_SIZE(n2))); // expect: 10
  printf("%d\n", countPairs(n3, ARRAY_SIZE(n3))); // expect: 0
}
