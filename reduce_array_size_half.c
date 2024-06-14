// 1338. Reduce Array Size to The Half
#include "leetcode.h"

/*
 * you are given an integer array 'arr'. you can choose a set of integers and
 * remove all the occurences of these integers in the array. return the minimum
 * size of the set so that at least half of the integers in the array are
 * removed.
 */

int minSetSize(int *arr, int arrSize) {
  int *hash = (int *)calloc(100001, sizeof(int));
  int *hash_cnt = (int *)calloc(arrSize + 1, sizeof(int));
  int max = 0, ans = 0, ans_cnt = 0;
  for (int i = 0; i < arrSize; i++) {
    if (hash[arr[i]])
      hash_cnt[hash[arr[i]]]--;
    hash_cnt[++hash[arr[i]]]++;
    if (hash[arr[i]] > max)
      max = hash[arr[i]];
  }
  while (ans_cnt < arrSize / 2) {
    while (!hash_cnt[max])
      max--;
    while (ans_cnt < arrSize / 2 && hash_cnt[max]) {
      ans_cnt += max;
      hash_cnt[max]--;
      ans++;
    }
  }
  return ans;
}

int main() {
  int a1[] = {3, 3, 3, 3, 5, 5, 5, 2, 2, 7}, a2[] = {7, 7, 7, 7, 7, 7};
  printf("%d\n", minSetSize(a1, ARRAY_SIZE(a1))); // expect: 2
  printf("%d\n", minSetSize(a2, ARRAY_SIZE(a2))); // expect: 1
}
