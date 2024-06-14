// 135. Candy
#include <stdio.h>
#include <stdlib.h>

/*
 * there are 'n' children standing in a line. each child is assigned a rating
 * value. given in the integer array 'ratings'. you are giving candies to these
 * children subjected to the following requirements
 * - each child must have at least one candy
 * - children with a higher rating get more candies than their neighbours
 * return the maximum number of candies you need to have to distribute the
 * candies to the children
 */

int candy(int *ratings, int ratings_size) {
  if (!ratings_size)
    return 0;
  int *a = (int *)malloc(sizeof(int) * ratings_size);
  a[0] = 1;
  for (int i = 1; i < ratings_size; i++) {
    if (ratings[i - 1] < ratings[i])
      a[i] = a[i - 1] + 1;
    else if (ratings[i - 1] == ratings[i])
      a[i] = 1;
    else {
      int j = i - 1, k = 1, n;
      while (j < ratings_size - 1 && ratings[j] > ratings[j + 1])
        k++, j++;
      if (a[i - 1] >= k) {
        n = k - 1;
        j = i;
        while (j < i + k - 1) {
          a[j] = n;
          n--;
          j++;
        }
      } else {
        n = k;
        j = i - 1;
        while (j < i + k - 1) {
          a[j] = n;
          n--;
          j++;
        }
      }
      i = j - 1;
    }
  }
  int ans = 0;
  for (int i = 0; i < ratings_size; i++)
    ans += a[i];
  return ans;
}

int main() {
  int r1[] = {1, 0, 2}, r2[] = {1, 2, 2};
  printf("%d\n", candy(r1, 3)); // expect: 5
  printf("%d\n", candy(r2, 3)); // expect: 4
}
