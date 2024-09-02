// 1860. Incremental Memory Leak
#include "leetcode.h"

/*
 * you are given two integer 'memory1' and 'memory2' representing the available
 * memory in bits on two memory sticks. there is currently a faulty program
 * running that consumes an increasing amount of memory every second. at the
 * i'th second (starting from 1), 'i' bits of memory are allocated to the stick
 * with more available memory (or from the first memory stick if both have the
 * same available memory). if neither stick has at least 'i' bits of available
 * memory, the program crashes. return an array containing '[crash_time,
 * memory1_crash, memory2_crash]', where 'crash_time' is the time when the
 * program crashed and 'memory1_crash' and 'memory2_crash' are the available
 * bits of memory in the first and second sticks respectively
 */

int *memLeak(int memory1, int memory2, int *returnSize) {
  *returnSize = 3;
  int i = 1, *ans = (int *)malloc((*returnSize) * sizeof(int));
  while (memory1 >= i || memory2 >= i) {
    if (memory2 > memory1)
      memory2 -= i;
    else
      memory1 -= i;
    i++;
  }
  ans[0] = i;
  ans[1] = memory1;
  ans[2] = memory2;
  return ans;
}

int main() {
  int rs1, rs2, *ml1 = memLeak(2, 2, &rs1), *ml2 = memLeak(8, 11, &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", ml1[i]); // expect: 3 1 0
  printf("\n");
  free(ml1);
  for (int i = 0; i < rs2; i++)
    printf("%d ", ml2[i]); // expect: 6 0 4
  printf("\n");
  free(ml2);
}
