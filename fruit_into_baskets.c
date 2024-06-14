// 904. Fruit Into Baskets
#include <stdio.h>
#include <stdlib.h>

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
  int n = fruitsSize, type = 0, left = 0, right = 0;
  int *hash = calloc(n, sizeof(int));
  while (right < fruitsSize) {
    if (hash[fruits[right]] == 0)
      type++;
    hash[fruits[right]]++;
    right++;
    if (type > 2) {
      if (hash[fruits[left]] == 1)
        type--;
      hash[fruits[left]]--;
      left++;
    }
  }
  free(hash);
  return right - left;
}

int main() {
  int fruits1[] = {1, 2, 1}, fs1 = 3;
  int fruits2[] = {0, 1, 2, 2}, fs2 = 4;
  int fruits3[] = {1, 2, 3, 2, 2}, fs3 = 5;
  printf("%d\n", totalFruit(fruits1, fs1)); // expect: 3
  printf("%d\n", totalFruit(fruits2, fs2)); // expect: 3
  printf("%d\n", totalFruit(fruits3, fs3)); // expect: 4
}
