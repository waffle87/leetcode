// 904. Fruit Into Baskets
#include "leetcode.h"

/*
 * you are visiting a farm that has a single row of fruit trees arranged from
 * left t oright. the trees are represented by an integer array 'fruits' where
 * 'fruits[i]' is the type of fruit the i'th tree produces. you want to collect
 * as much fruit as possible. however, the owner has some strict rules that you
 * must follow: you can only have two baskets and each can only hoold a single
 * type of fruit (unlimited quantity). starting from any tree, you must pick
 * exacty one fruit from every tree while moving to the right. once you reach a
 * tree with fruit that cannot fit in your baskets, you must stop. given the int
 * array 'fruits', return the maximum number of fruits you can pick
 */

int totalFruit(int *fruits, int fruitsSize) {
  int max = 0, p1 = 0, p2 = 0, f1 = -1, f2 = -1, i, j = 0;
  for (i = 0; i < fruitsSize; ++i) {
    if (fruits[i] == f1)
      ++p1;
    else if (f1 < 0) {
      f1 = fruits[i];
      p1 = 1;
    } else {
      f2 = fruits[i];
      p2 = 1;
      break;
    }
  }
  while (++i < fruitsSize) {
    if (fruits[i] == f1)
      ++p1;
    else if (fruits[i] == f2)
      ++p2;
    else {
      if (i - j > max)
        max = i - j;
      while (p1 > 0 && p2 > 0) {
        if (fruits[j] == f1)
          --p1;
        else
          --p2;
        ++j;
      }
      if (!p1) {
        f1 = fruits[i];
        p1 = 1;
      } else {
        f2 = fruits[i];
        p2 = 1;
      }
    }
  }
  if (fruitsSize - j > max)
    return fruitsSize - j;
  return max;
}

int main() {
  int f1[] = {1, 2, 1}, f2[] = {0, 1, 2, 2}, f3[] = {1, 2, 3, 2, 2};
  printf("%d\n", totalFruit(f1, ARRAY_SIZE(f1))); // expect: 3
  printf("%d\n", totalFruit(f2, ARRAY_SIZE(f2))); // expect: 3
  printf("%d\n", totalFruit(f3, ARRAY_SIZE(f3))); // expect: 4
}
