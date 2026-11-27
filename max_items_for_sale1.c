// 3946. Maximum Number of Items From Sale I
#include "leetcode.h"

int maximumSaleItems(int **items, int itemsSize, int *itemsColSize,
                     int budget) {
  int *f = (int *)calloc(budget + 1, sizeof(int));
  int min = items[0][1];
  for (int i = 0; i < itemsSize; i++) {
    int factor = items[i][0], price = items[i][1];
    min = fmin(min, price);
    int cnt = 0;
    for (int k = 0; k < itemsSize; k++)
      if (!(items[k][0] % factor))
        cnt++;
    for (int j = budget; j >= price; j--)
      if (f[j - price] + cnt > f[j])
        f[j] = f[j - price] + cnt;
  }
  int ans = 0;
  for (int j = 0; j <= budget; j++) {
    int curr = f[j] + (budget - j) / min;
    ans = fmax(ans, curr);
  }
  free(f);
  return ans;
}

int main() {
  int i1i[3][2] = {{6, 2}, {2, 6}, {3, 4}};
  int i2i[5][2] = {{2, 4}, {3, 2}, {4, 1}, {6, 4}, {12, 4}};
  struct two_d_arr *i1 =
      two_d_arr_init(ARRAY_SIZE(i1i), ARRAY_SIZE(i1i[0]), i1i);
  struct two_d_arr *i2 =
      two_d_arr_init(ARRAY_SIZE(i2i), ARRAY_SIZE(i2i[0]), i2i);
  int r1 = maximumSaleItems(i1->arr, i1->row_size, i1->col_size, 9);
  int r2 = maximumSaleItems(i2->arr, i2->row_size, i2->col_size, 8);
  printf("%d\n", r1);
  assert(r1 == 4);
  printf("%d\n", r2);
  assert(r2 == 10);
  two_d_arr_free(i1);
  two_d_arr_free(i2);
}
