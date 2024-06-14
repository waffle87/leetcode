// 1675. Minimize Deviation in Array
#include <stdio.h>

#define SWAP(x, y) (x ^= y ^= x ^= y)
#define MIN(a, b) ((a < b) ? a : b)

/*
 * the deviation of the array is the maximum difference between any two elements
 * in the array. return minimum deviation the array can have after performing
 * 'nums' ops.
 */

void check_larger(int *h, int posi) {
  for (int cmp; posi >= 4; posi = cmp) {
    cmp = (posi >> 2 << 1) + 1;
    if (h[posi] > h[cmp])
      SWAP(h[posi], h[cmp]);
    else
      break;
  }
}

void check_smaller(int *h, int posi) {
  for (int cmp; posi >= 4; posi = cmp) {
    cmp = posi >> 2 << 1;
    if (h[posi] < h[cmp])
      SWAP(h[posi], h[cmp]);
    else
      break;
  }
}

void insert(int *h, int top, int data) {
  h[top] = data;
  if (!(top & 1)) {
    if (h[top] > h[top >> 1])
      check_larger(h, top);
    else
      check_smaller(h, top);
  } else {
    if (h[top] < h[top - 1]) {
      SWAP(h[top], h[top - 1]);
      check_smaller(h, top - 1);
    } else
      check_larger(h, top);
  }
}

void delete_max(int *h, int *top) {
  h[3] = h[(*top)--];
  int par = 3, chi = 5;
  while (chi <= (*top)) {
    if (chi + 2 <= (*top) && h[chi + 2] > h[chi])
      chi += 2;
    if (h[chi] > h[par]) {
      SWAP(h[chi], h[par]);
      par = chi;
      chi = (chi << 1) - 1;
    } else
      break;
  }
  if (h[par] < h[par - 1])
    SWAP(h[par], h[par - 1]);
}

int minimumDeviation(int *nums, int numsSize) {
  int h[numsSize + 2], top = 1, ans;
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] & 1)
      nums[i] <<= 1;
    insert(h, ++top, nums[i]);
  }
  ans = h[3] - h[2];
  while (!(h[3] & 1)) {
    int t = h[3] >> 1;
    delete_max(h, &top);
    insert(h, ++top, t);
    ans = MIN(ans, h[3] - h[2]);
  }
  return ans;
}

int main() {
  int n1[] = {1, 2, 3, 4}, n2[] = {4, 1, 5, 20, 3}, n3[] = {2, 10, 8};
  printf("%d\n", minimumDeviation(n1, 4)); // expect: 1
  printf("%d\n", minimumDeviation(n2, 5)); // expect: 3
  printf("%d\n", minimumDeviation(n3, 3)); // expect: 3
}
