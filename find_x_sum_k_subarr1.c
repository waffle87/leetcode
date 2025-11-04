// 3318. Find X-Sum of All K-Long Subarrays I
#include "leetcode.h"

/*
 * you are given an array 'nums' of 'n' integers and two integers 'k' and 'x'.
 * the x-sum of an array is calcluated by the follow procedure: count the
 * occurences of all elements in the array, keep only the occurences of the top
 * 'x' most frequent elements. if two elements have the same number of
 * occurences, the element with the bigger value is considered more frequent.
 * calcluate the sum of the resulting array. note tht if an array has less than
 * 'x' distinct eleents, its x-sum is the sum of the array. return an integer
 * array 'ans' of length 'n - k + 1' where 'ans[i]' is the x-sum of the subarray
 * 'nums[i .. i + k - 1]'
 */

struct pair {
  int num;
  int freq;
};

int cmp(const void *a, const void *b) {
  struct pair *p1 = (struct pair *)a;
  struct pair *p2 = (struct pair *)b;
  if (p2->freq != p1->freq)
    return p2->freq - p1->freq;
  return p2->num - p1->num;
}

int *findXSum(int *nums, int numsSize, int k, int x, int *returnSize) {
  *returnSize = numsSize - k + 1;
  int *ans = (int *)malloc(*returnSize * sizeof(int));
  for (int i = 0; i <= numsSize - k; i++) {
    int freq[51] = {0}, cnt = 0;
    struct pair kvp[51];
    for (int j = i; j < i + k; j++)
      freq[nums[j]]++;
    for (int j = 1; j <= 50; j++)
      if (freq[j] > 0) {
        kvp[cnt].num = j;
        kvp[cnt].freq = freq[j];
        cnt++;
      }
    qsort(kvp, cnt, sizeof(struct pair), cmp);
    int sum = 0;
    for (int j = 0; j < cnt && j < x; j++)
      sum += kvp[j].num * kvp[j].freq;
    ans[i] = sum;
  }
  return ans;
}

int main() {
  int n1[] = {1, 1, 2, 2, 3, 4, 3, 2, 3}, n2[] = {3, 8, 7, 8, 7, 5};
  int rs1, *fxs1 = findXSum(n1, ARRAY_SIZE(n1), 6, 2, &rs1);
  int rs2, *fxs2 = findXSum(n2, ARRAY_SIZE(n2), 2, 2, &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", fxs1[i]); // expect: 6 10 12
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", fxs2[i]); // expect: 11 15 15 15 12
  printf("\n");
  free(fxs1);
  free(fxs2);
}
