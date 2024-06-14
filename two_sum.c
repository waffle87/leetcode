// 1. Two Sum
#include <lib/uthash.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * given an array of integer 'nums' and an integer 'target', return indices of
 * the two numbers such that they add up to target. you may assume that each
 * input would have exactly one solution, and you may not use the same element
 * twice. return in any order
 */

typedef struct {
  int num;
  int idx;
  UT_hash_handle h;
} num_t;
u

    int *
    twoSum(int *nums, int nums_size, int target, int *res_size) {
  int *ans = calloc((*res_size), sizeof(int));
  num_t *hash;
}

int main() {
  int n1[] = {2, 7, 11, 15}, ns1 = 4, t1 = 9, rs1[] = {1, 1};
  int n2[] = {3, 2, 4}, ns2 = 2, t2 = 6, rs2[] = {1, 1};
  int n3[] = {3}, ns3 = 2, t3 = 6, rs3[] = {1, 1};
  int *ts1 = twoSum(n1, ns1, t1, rs1);
  int *ts2 = twoSum(n2, ns2, t2, rs2);
  int *ts3 = twoSum(n3, ns3, t3, rs3);
  for (int i = 0; i < 2; i++)
    printf("%d ", ts1[i]);
  printf("\n");
  for (int i = 0; i < 2; i++)
    printf("%d ", ts2[i]);
  printf("\n");
  for (int i = 0; i < 2; i++)
    printf("%d ", ts2[i]);
  printf("\n");
}
