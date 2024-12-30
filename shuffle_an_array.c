// 384. Shuffle an Array
#include "leetcode.h"

/*
 * given an integer array 'nums', design an algorithm to randomly shuffle the
 * array. all permutations of the array should be equally likely as a result of
 * the shuffling. implement the 'Solution' class: 'Solution(int[] nums)'
 * initialises the object with the integer array 'nums' 'int[] reset()' resets
 * the array to its original configuration and returns it 'int[] shuffle()'
 * return a random shuffling of the array
 */

typedef struct {
  int *original;
  int *nums;
  int size;
} Solution;

Solution *solutionCreate(int *nums, int numsSize) {
  Solution *obj = (Solution *)malloc(sizeof(Solution));
  obj->original = (int *)malloc(numsSize * sizeof(int));
  obj->nums = (int *)malloc(numsSize * sizeof(int));
  obj->size = numsSize;
  memcpy(obj->original, nums, numsSize * sizeof(int));
  memcpy(obj->nums, nums, numsSize * sizeof(int));
  return obj;
}

int *solutionReset(Solution *obj, int *retSize) {
  *retSize = obj->size;
  memcpy(obj->nums, obj->original, obj->size * sizeof(int));
  return obj->original;
}

int *solutionShuffle(Solution *obj, int *retSize) {
  *retSize = obj->size;
  for (int i = 0; i < obj->size; i++) {
    int tmp = obj->nums[i];
    int pos = rand() % obj->size;
    obj->nums[i] = obj->nums[pos];
    obj->nums[pos] = tmp;
  }
  return obj->nums;
}

void solutionFree(Solution *obj) {
  free(obj->nums);
  free(obj->original);
  free(obj);
}

int main() {
  int n1[] = {1, 2, 3}, rs1, rs2, rs3;
  Solution *obj = solutionCreate(n1, ARRAY_SIZE(n1));
  int *ss1 = solutionShuffle(obj, &rs1);
  int *sr1 = solutionReset(obj, &rs2);
  int *ss2 = solutionShuffle(obj, &rs3);
  for (int i = 0; i < rs1; i++)
    printf("%d ", ss1[i]); // expect: 3 1 2
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", sr1[i]); // expect: 1 2 3
  printf("\n");
  for (int i = 0; i < rs3; i++)
    printf("%d ", ss2[i]); // expect: 1 3 2
  printf("\n");
  free(ss1), free(sr1), free(ss2);
  solutionFree(obj);
}
