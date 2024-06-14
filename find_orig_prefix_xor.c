// 2433. Find The Original Array of Prefix Xor
#include <stdio.h>
#include <stdlib.h>

/*
 * given an integer array 'pref' of size 'n'. find and return the array 'arr' of
 * size 'n' that satisfies 'pref[i] = arr[0] ^ arr[1] ^ ... ^ arr[i]'. note that
 * '^' denotes the bitwise xor operator. it can be proven that the answer is
 * unique
 */

int *findArray(int *pref, int pref_size, int *return_size) {
  int *ans = malloc(pref_size * sizeof(int));
  *return_size = pref_size;
  ans[0] = pref[0];
  for (int i = 1; i < pref_size; i++)
    ans[i] = pref[i - 1] ^ pref[i];
  return ans;
}

int main() {
  int p1[] = {5, 2, 0, 3, 1}, p2[] = {13};
  int rs1[] = {}, rs2[] = {};
  int *fa1 = findArray(p1, 5, rs1), *fa2 = findArray(p2, 1, rs2);
  for (int i = 0; i < 5; i++)
    printf("%d ", fa1[i]); // expect: 5 7 2 3 2
  printf("\n");
  for (int i = 0; i < 1; i++)
    printf("%d ", fa2[i]); // expect: 13
  printf("\n");
}
