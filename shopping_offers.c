// 638. Shopping Offers
#include "leetcode.h"

/*
 * in leetcode store, there are 'n' items to sell. each item has a price.
 * however, there are some special offers, and a special offer consists of one
 * or more different kinds of items with a sale price. you are given an integer
 * array 'price' where 'price[i]' is the price of the i'th item, and an integer
 * array 'needs' where 'needs[i]' is the number of pieces the i'th item you want
 * to buy. you are also given an array 'special', where 'special[i]' is of size
 * 'n + 1' where 'special[i][j]' is the number of pieces of the j'th item in the
 * i'th other. return the lowest price you have to pay for exactly certain items
 * as given, where you could make optimal use of the special offers. you are not
 * allowed to buy more items that you want, even if that would lower the overall
 * price.
 */

#define MOD 1009

struct node {
  struct node *next;
  int key;
  int val;
};

struct node *hash[MOD];

void hash_init(void) { memset((void *)hash, 0, sizeof(hash)); }

void hash_push(int key, int val) {
  int idx = key % MOD;
  struct node *tmp = (struct node *)malloc(sizeof(struct node));
  tmp->key = key;
  tmp->val = val;
  tmp->next = hash[idx];
  hash[idx] = tmp;
}

int hash_pop(int key) {
  int idx = key % MOD;
  struct node *tmp = hash[idx];
  for (; tmp; tmp = tmp->next)
    if (tmp->key == key)
      return tmp->val;
  return -1;
}

void hash_free(void) {
  for (int i = 0; i < MOD; i++)
    for (struct node *tmp = hash[i], *del; tmp;) {
      del = tmp;
      tmp = tmp->next;
      free(del);
    }
}

int lowest_price(int n, int need, int *prices, int **special, int specialSize,
                 int *specialColSize) {
  int min = INT_MAX, price = 0, tmp;
  bool accept = true;
  if (!need)
    return 0;
  price = hash_pop(need);
  if (price >= 0)
    return price;
  price = 0;
  tmp = need;
  for (int i = 0; i < n; i++) {
    price += prices[i] * (tmp & 0x0F);
    tmp >>= 4;
  }
  min = fmin(min, price);
  for (int i = 0; i < specialSize; i++) {
    tmp = need;
    accept = true;
    for (int j = 0; j < n; j++) {
      int quantity = (tmp >> (j * 4)) & 0x0F;
      if (quantity >= special[i][j]) {
        quantity -= special[i][j];
        tmp &= ~(0x0F << (j * 4));
        tmp |= (quantity << (j * 4));
      } else {
        accept = false;
        break;
      }
    }
    if (accept) {
      price = special[i][n] + lowest_price(n, tmp, prices, special, specialSize,
                                           specialColSize);
      min = fmin(min, price);
    }
  }
  hash_push(need, min);
  return min;
}

int shoppingOffers(int *price, int priceSize, int **special, int specialSize,
                   int *specialColSize, int *needs, int needsSize) {
  int need = 0, ans;
  hash_init();
  for (int i = 0; i < needsSize; i++)
    need |= (needs[i] << (i * 4));
  ans = lowest_price(priceSize, need, price, special, specialSize,
                     specialColSize);
  hash_free();
  return ans;
}

int main() {
  int p1[] = {2, 5}, s1i[2][3] = {{3, 0, 5}, {1, 2, 10}}, n1[] = {3, 2};
  int p2[] = {2, 3, 4}, s2i[2][4] = {{1, 1, 0, 4}, {2, 2, 1, 9}},
      n2[] = {1, 2, 1};
  struct two_d_arr *s1 =
      two_d_arr_init(ARRAY_SIZE(s1i), ARRAY_SIZE(s1i[0]), s1i);
  struct two_d_arr *s2 =
      two_d_arr_init(ARRAY_SIZE(s2i), ARRAY_SIZE(s2i[0]), s2i);
  printf("%d\n",
         shoppingOffers(p1, ARRAY_SIZE(p1), s1->arr, s1->row_size, s1->col_size,
                        n1, ARRAY_SIZE(n1))); // expect: 14
  printf("%d\n",
         shoppingOffers(p2, ARRAY_SIZE(p2), s2->arr, s2->row_size, s2->col_size,
                        n2, ARRAY_SIZE(n2))); // expect: 11
  two_d_arr_free(s1);
  two_d_arr_free(s2);
}
