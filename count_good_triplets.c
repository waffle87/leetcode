// 1534. Count Good Triplets
#include "leetcode.h"

/*
 * given an array of integers 'arr', and three integers 'a, b, c', yo need to
 * find the number of good triplets. a triplet '(arr[i], arr[j], arr[k])' is
 * good if the following conditions are met: '0 <= i < j < k < arr.len, |arr[i]
 * - arr[j]| <= (a, b, c)' where '|x|' denotes the absolute value of 'x'. return
 * the number of good triplets.
 */

int countGoodTriplets(int *arr, int arrSize, int a, int b, int c) {
  int cnt = 0;
  for (int i = 0; i < arrSize - 2; i++)
    for (int k = i + 2; k < arrSize; k++) {
      if (abs(arr[k] - arr[i]) > c)
        continue;
      for (int j = i + 1; j < k; j++)
        if (abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b)
          ++cnt;
    }
  return cnt;
}

int main() {
  int a1[] = {3, 0, 1, 1, 9, 7}, a2[] = {1, 1, 2, 2, 3};
  printf("%d\n", countGoodTriplets(a1, ARRAY_SIZE(a1), 7, 2, 3)); // expect: 4
  printf("%d\n", countGoodTriplets(a2, ARRAY_SIZE(a2), 0, 0, 1)); // expect: 0
}
