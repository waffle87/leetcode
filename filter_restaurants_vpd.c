// 1333. Filter Restaurants by Vegan-Friendly, Price and Distance
#include "leetcode.h"

/*
 * given the array 'restaurants' where 'restaurants[i] = [id_i, rating_i,
 * veganFriendly_i, price_i, distance_i]'. you have to filter the restaurants
 * using three filters. the 'veganFriendly' filter will either be true or false.
 * in addition, you have the filters 'maxPrice' and 'maxDistance' which are the
 * maximum value for price and distance of restaurants you should consider
 * respectively. return the array of restaurant id's after filtering, ordered by
 * rating from highest to lowest. for restaurants with the same rating, order
 * them by id from highest to lowest.
 */

int cmp(const void *a, const void *b) {
  int *aa = *(int **)a, *bb = *(int **)b;
  if (bb[1] == aa[1])
    return bb[0] - aa[0];
  return bb[1] - aa[1];
}

int *filterRestaurants(int **restaurants, int restaurantsSize,
                       int *restaurantsColSize, int veganFriendly, int maxPrice,
                       int maxDistance, int *returnSize) {
  int **map = (int **)malloc(restaurantsSize * sizeof(int)), idx = 0;
  for (int i = 0; i < restaurantsSize; i++) {
    if (restaurants[i][3] <= maxPrice && restaurants[i][4] <= maxDistance) {
      bool flag = false;
      if (!veganFriendly)
        flag = true;
      else if (restaurants[i][2] == veganFriendly)
        flag = true;
      if (flag) {
        map[idx] = (int *)malloc(2 * sizeof(int));
        map[idx][0] = restaurants[i][0];
        map[idx][1] = restaurants[i][1];
        idx++;
      }
    }
  }
  qsort(map, idx, sizeof(int **), cmp);
  int *ans = (int *)malloc(idx * sizeof(int));
  *returnSize = idx;
  for (int i = 0; i < idx; i++)
    ans[i] = map[i][0];
  for (int i = 0; i < idx; i++)
    free(map[i]);
  free(map);
  return ans;
}

int main() {
  int r1i[5][5] = {{1, 4, 1, 40, 10},
                   {2, 8, 0, 50, 5},
                   {3, 8, 1, 30, 4},
                   {4, 10, 0, 10, 3},
                   {5, 1, 1, 15, 1}};
  int r2i[5][5] = {{1, 4, 1, 40, 10},
                   {2, 8, 0, 50, 5},
                   {3, 8, 1, 30, 4},
                   {4, 10, 0, 10, 3},
                   {5, 1, 1, 15, 1}};
  int r3i[5][5] = {{1, 4, 1, 40, 10},
                   {2, 8, 0, 50, 5},
                   {3, 8, 1, 30, 4},
                   {4, 10, 0, 10, 3},
                   {5, 1, 1, 15, 1}};
  struct two_d_arr *r1 = two_d_arr_init(5, 5, r1i);
  struct two_d_arr *r2 = two_d_arr_init(5, 5, r2i);
  struct two_d_arr *r3 = two_d_arr_init(5, 5, r3i);
  int rs1, *fr1 = filterRestaurants(r1->arr, r1->row_size, r1->col_size, 1, 50,
                                    10, &rs1);
  int rs2, *fr2 = filterRestaurants(r2->arr, r2->row_size, r2->col_size, 0, 50,
                                    10, &rs2);
  int rs3, *fr3 = filterRestaurants(r3->arr, r3->row_size, r3->col_size, 0, 30,
                                    3, &rs3);
  for (int i = 0; i < rs1; i++)
    printf("%d", fr1[i]); // expect: 3 1 5
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d", fr2[i]); // expect: 4 3 2 1 5
  printf("\n");
  for (int i = 0; i < rs3; i++)
    printf("%d", fr3[i]); // expect: 4 5
  printf("\n");
  two_d_arr_free(r1), free(fr1);
  two_d_arr_free(r2), free(fr2);
  two_d_arr_free(r3), free(fr3);
}
