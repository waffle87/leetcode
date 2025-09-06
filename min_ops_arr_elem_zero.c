// 3495. Minimum Operations to Make Array Elements Zero
#include "leetcode.h"

/*
 * you are given a 2d array 'queries' where 'queries[i]' is of the form '[l,
 * r]'. each 'queries[i]' defines an array of integers 'nums' consisting of
 * elements ranging from 'l' to 'r' both inclusive. in one operation you can
 * select two integers 'a' and 'b' from the array and replace them with 'floor(a
 * / 4)' and 'floor(b / 4)'. your task is to determine the minimum number of
 * operations required to reduce all the elements of the array to zero for each
 * query. return the sum of the results for all queries.
 */

long long count(long long a) {
  long long res = 0, k = 1, v = 1;
  while (a >= v * 4) {
    res += (v * 4 - v) * k;
    k++;
    v *= 4;
  }
  return res + (a - v + 1) * k;
}

long long minOperations(int **queries, int queriesSize, int *queriesColSize) {
  long long ans = 0;
  for (int i = 0; i < queriesSize; i++)
    ans += (count(queries[i][1]) - count(queries[i][0] - 1) + 1) / 2;
  return ans;
}

int main() {
  int q1i[2][2] = {{1, 2}, {2, 4}}, q2i[][2] = {{2, 6}};
  struct two_d_arr *q1 =
      two_d_arr_init(ARRAY_SIZE(q1i), ARRAY_SIZE(q1i[0]), q1i);
  struct two_d_arr *q2 =
      two_d_arr_init(ARRAY_SIZE(q2i), ARRAY_SIZE(q2i[0]), q2i);
  printf("%lld\n",
         minOperations(q1->arr, q1->row_size, q1->col_size)); // expect: 3
  printf("%lld\n",
         minOperations(q2->arr, q2->row_size, q2->col_size)); // expect: 4
  two_d_arr_free(q1);
  two_d_arr_free(q2);
}
