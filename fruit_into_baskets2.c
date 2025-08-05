// 3477. Fruits Into Baskets II
#include "leetcode.h"

/*
 * you are given two arrays of integers 'fruits' and 'baskets' each of length
 * 'n', where 'fruits[i]' represents the quantity of the i'th type of fruit, and
 * 'baskets[j]' represents the capacity of the 'j'th basket. from left to right,
 * place the fruits according to these rules: each fruit type must be place in
 * the leftmost available basket with a capacity greater than or equal to the
 * quantity of that fruit type. return the number of fruit types that remain
 * unplaced after all possible allocations are made.
 */

int numOfUnplacedFruits(int *fruits, int fruitsSize, int *baskets,
                        int basketsSize) {
  bool *used = (bool *)calloc(fruitsSize, sizeof(bool));
  int unplaced = 0;
  for (int i = 0; i < fruitsSize; i++) {
    bool placed = false;
    for (int j = 0; j < fruitsSize; j++) {
      if (!used[j] && baskets[j] >= fruits[i]) {
        used[j] = true;
        placed = true;
        break;
      }
    }
    if (!placed)
      unplaced++;
  }
  free(used);
  return unplaced;
}

int main() {
  int f1[] = {4, 2, 5}, b1[] = {3, 5, 4};
  int f2[] = {3, 6, 1}, b2[] = {6, 4, 7};
  printf("%d\n", numOfUnplacedFruits(f1, ARRAY_SIZE(f1), b1,
                                     ARRAY_SIZE(b1))); // expect: 1
  printf("%d\n", numOfUnplacedFruits(f2, ARRAY_SIZE(f2), b2,
                                     ARRAY_SIZE(b2))); // expect: 0
}
