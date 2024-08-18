// 398. Random Pick Index
#include "leetcode.h"

/*
 * given an integer array 'nums' with possible duplicates, randomly output the
 * index of a given 'target' numbber. you can assume that the given target
 * number must exist in the array. implement the 'Solution' class: 'Solution(int
 * [] nums)' initiliases the object with the array 'nums', 'int pick(int
 * target)' picks a random index 'i' from 'nums' where 'nums[i] == target'. if
 * there are multiple valid 'i's, then each index should have an equal
 * probability
 */

typedef struct {
  int *nums;
  int numsSize;
} Solution;

Solution *solutionCreate(int *nums, int numsSize) {
  size_t arr_size = numsSize * sizeof(int);
  Solution *obj = (Solution *)malloc(sizeof(*obj));
  obj->nums = (int *)malloc(arr_size);
  obj->numsSize = numsSize;
  memcpy(obj->nums, nums, arr_size);
  return obj;
}

int solutionPick(Solution *obj, int target) {
  int cnt = 0, res = -1;
  for (int i = 0; i < obj->numsSize; i++)
    if (obj->nums[i] == target) {
      cnt++;
      if (!(rand() % cnt))
        res = i;
    }
  return res;
}

void solutionFree(Solution *obj) {
  free(obj->nums);
  free(obj);
}

int main() {
  int nums[] = {1, 2, 3, 3, 3, 3};
  Solution *obj = solutionCreate(nums, ARRAY_SIZE(nums));
  printf("%d\n", solutionPick(obj, 3)); // expect: 4
  printf("%d\n", solutionPick(obj, 1)); // expect: 0
  printf("%d\n", solutionPick(obj, 3)); // expect: 2
}
