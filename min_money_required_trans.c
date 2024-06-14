// 2412. Minimum Money Required Before Transactions
#include "leetcode.h"

/*
 * given a 0-indexed 2d integer array 'transactions' where 'transactions[i] =
 * [cost_i, cashback_i]'. the array describes transactions where each
 * transaction must be completed exactly once in some order. atany given moment
 * you have a certain amoiunt of money in order to complete transaction 'i',
 * money must be greater than or equal to cost[i]. after performing a
 * transaction, 'money' becomes 'money - cost[i] + cashback[i]'. return the
 * minimum amount of 'money' required before any transaction so that all the
 * transactions can be completed regardless of the order of transactions.
 */

long long minimumMoney(int **transactions, int transactionsSize,
                       int *transactionsColSize) {
  long long ans = 0;
  int cashback = 0, money = -1;
  for (int i = 0; i < transactionsSize; i++)
    if (transactions[i][0] > transactions[i][1]) {
      ans += transactions[i][0] - transactions[i][1];
      if (cashback < transactions[i][1])
        cashback = transactions[i][1];
    } else {
      if (money < transactions[i][0])
        money = transactions[i][0];
    }
  ans += cashback < money ? money : cashback;
  return ans;
}

int main() {
  int t1[2][3], t2[2][2], tcs1[] = {2, 2, 2}, tcs2[] = {2, 2};
  t1[0][0] = 2, t1[0][1] = 5, t1[0][2] = 4;
  t1[1][0] = 1, t1[1][1] = 0, t1[1][2] = 2;
  t2[0][0] = 3, t2[0][1] = 0, t2[1][0] = 0, t2[1][1] = 3;
  printf("%lld\n", minimumMoney((int **)t1, ARRAY_SIZE(t1), tcs1)); // expect:
                                                                    // 10
  printf("%lld\n", minimumMoney((int **)t2, ARRAY_SIZE(t2), tcs2)); // expect: 3
}
