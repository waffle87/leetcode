// 135. Candy
#include "leetcode.h"

/*
 * there are 'n' children standing in a line. each child is assigned a rating
 * value. given in the integer array 'ratings'. you are giving candies to these
 * children subjected to the following requirements
 * - each child must have at least one candy
 * - children with a higher rating get more candies than their neighbours
 * return the maximum number of candies you need to have to distribute the
 * candies to the children
 */

int candy(int *ratings, int ratingsSize) {
  int candy = ratingsSize, i = 1;
  while (i < ratingsSize) {
    if (ratings[i] == ratings[i - 1]) {
      i++;
      continue;
    }
    int peak = 0;
    while (ratings[i] > ratings[i - 1]) {
      peak++;
      candy += peak;
      i++;
      if (i == ratingsSize)
        return candy;
    }
    int valley = 0;
    while (i < ratingsSize && ratings[i] < ratings[i - 1]) {
      valley++;
      candy += valley;
      i++;
    }
    candy -= fmin(peak, valley);
  }
  return candy;
}

int main() {
  int r1[] = {1, 0, 2}, r2[] = {1, 2, 2};
  printf("%d\n", candy(r1, ARRAY_SIZE(r1))); // expect: 5
  printf("%d\n", candy(r2, ARRAY_SIZE(r2))); // expect: 4
}
