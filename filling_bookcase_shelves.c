// 1105. Filling Bookcase Shelves
#include "leetcode.h"

/*
 * you are given an array 'books' where 'books[i] = [thinkness, height]'
 * indicates the thickness and height of the i'th book. you are also given an
 * integer 'shelfWidth'. we want to place these books in order onto bookcase
 * shelves that have a total width 'shelfWidth'. we chose some of the books to
 * place on this shelf such that the sum of their thickness is less than or
 * equal to 'shelfWidth' then build another level of the shelf of the bookcase
 * so that the total height of the bookcase has increased by the maximum height
 * of the books we just put down. we repeat this process until there are no more
 * books to place.
 */

int minHeightShelves(int **books, int booksSize, int *booksColSize,
                     int shelfWidth) {
  int *dp = (int *)malloc((booksSize + 1) * sizeof(int));
  dp[0] = 0;
  for (int i = 1; i <= booksSize; i++) {
    int min = dp[i - 1] + books[i - 1][1];
    int height = books[i - 1][1];
    int width = books[i - 1][0];
    int j = i - 2;
    while (j >= 0 && width + books[j][0] <= shelfWidth) {
      width += books[j][0];
      height = (height > books[j][1]) ? height : books[j][1];
      min = (min < height + dp[j]) ? min : height + dp[j];
      --j;
    }
    dp[i] = min;
  }
  int ans = dp[booksSize];
  free(dp);
  return ans;
}

int main() {
  int b1[7][2] = {{1, 1}, {2, 3}, {2, 3}, {1, 1}, {1, 1}, {1, 1}, {1, 2}},
      b2[3][2] = {{1, 3}, {2, 4}, {3, 2}}, bcs1 = 7, bcs2 = 3;
  printf("%d\n",
         minHeightShelves((int **)b1, ARRAY_SIZE(b1), &bcs1, 4)); // expect: 6
  printf("%d\n",
         minHeightShelves((int **)b2, ARRAY_SIZE(b2), &bcs2, 6)); // expect: 4
}
