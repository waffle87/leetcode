// 1346. Check If N and Its Double Exist

#include "leetcode.h"

/*
 * given an array 'arr' of integers, check if there exists two indices 'i' and
 * 'j' such that 'i != j', '0 <= i, j < arr.length', and 'arr[i] == 2 * arr[j]'
 */

bool checkIfExist(int *arr, int arrSize) {
  for (int i = 0; i < arrSize; i++) {
    int n = arr[i];
    for (int j = i + 1; j < arrSize; j++) {
      int m = arr[j];
      if (n == (2 * m) || m == (2 * n))
        return true;
    }
  }
  return false;
}

int main() {
  int a1[] = {10, 2, 5, 3}, a2[] = {3, 1, 7, 11};
  printf("%d\n", checkIfExist(a1, ARRAY_SIZE(a1))); // expect: 1
  printf("%d\n", checkIfExist(a2, ARRAY_SIZE(a2))); // expect: 0
}
