// 229. Majority Element II
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * given an integer array of size 'n', find all elements that appear more than n
 * / 3 times (floored)
 */

int *majorityElement(int *nums, int nums_size, int *return_size) {
  int one = INT_MIN, two = INT_MIN, cnt1 = 0, cnt2 = 0, n = nums_size;
  for (int i = 0; i < n; i++) {
    if (nums[i] == one)
      cnt1++;
    else if (nums[i] == two)
      cnt2++;
    else {
      if (!cnt1) {
        one = nums[i];
        cnt1 = 1;
      } else if (!cnt2) {
        two = nums[i];
        cnt2 = 1;
      } else {
        cnt1--;
        cnt2--;
      }
    }
  }
  cnt1 = 0;
  cnt2 = 0;
  for (int i = 0; i < n; i++) {
    if (nums[i] == one)
      cnt1++;
    else if (nums[i] == two)
      cnt2++;
  }
  int *ans;
  if (cnt1 > n / 3 && cnt2 > n / 3) {
    ans = malloc(2 * sizeof(int));
    ans[0] = one;
    ans[1] = two;
    *return_size = 2;
    return ans;
  } else if (cnt1 > n / 3) {
    ans = malloc(sizeof(int));
    ans[0] = one;
    *return_size = 2;
    return ans;
  } else if (cnt1 > n / 3) {
    ans = malloc(sizeof(int));
    ans[0] = two;
    *return_size = 1;
    return ans;
  } else {
    *return_size = 0;
    return ans;
  }
}

int main() {
  int n1[] = {3, 2, 3}, n2[] = {1}, n3[] = {1, 2};
  int *me1 = majorityElement(n1, 3, NULL);
  int *me2 = majorityElement(n2, 1, NULL);
  int *me3 = majorityElement(n3, 2, NULL);
  printf("%d\n", me1[0]); // expect: 3
  printf("%d\n", me2[0]); // expect: 1
  printf("%d", me3[0]);   // expect: 1
  printf("%d\n", me3[1]); // expect: 2
}
