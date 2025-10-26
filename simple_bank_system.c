// 2043. Simple Bank System
#include "leetcode.h"

/*
 * you have been tasked with writing a program for a popular bank that will
 * automate all its incoming transactions (transfer, deposit, and withdraw). the
 * bank has 'n' accounts numbered from 1 to 'n'. the initial balance of each
 * account is stored in a 0-indexed integer array 'balance' with the '(i + 1)'th
 * account having an initial balance of 'balance[i]'.
 */

typedef struct {
  long long *balance;
  int n;
} Bank;

bool valid(Bank *obj, int account) { return account > 0 && account <= obj->n; }

Bank *bankCreate(long long *balance, int balanceSize) {
  Bank *obj = (Bank *)malloc(sizeof(Bank));
  obj->n = balanceSize;
  obj->balance = (long long *)malloc(balanceSize * sizeof(long long));
  memcpy(obj->balance, balance, balanceSize);
  return obj;
}

bool bankTransfer(Bank *obj, int account1, int account2, long long money) {
  if (!valid(obj, account1) || !valid(obj, account2) ||
      obj->balance[account1 - 1] < money)
    return false;
  obj->balance[account1 - 1] -= money;
  obj->balance[account2 - 1] += money;
  return true;
}

bool bankDeposit(Bank *obj, int account, long long money) {
  if (!valid(obj, account))
    return false;
  obj->balance[account - 1] += money;
  return true;
}

bool bankWithdraw(Bank *obj, int account, long long money) {
  if (!valid(obj, account) || obj->balance[account - 1] < money)
    return false;
  obj->balance[account - 1] -= money;
  return true;
}

void bankFree(Bank *obj) {
  free(obj->balance);
  free(obj);
}

int main() {
  long long balance[] = {10, 100, 20, 50, 30};
  Bank *obj = bankCreate(balance, ARRAY_SIZE(balance));
  printf("%d\n", bankWithdraw(obj, 3, 10));    // expext: 1
  printf("%d\n", bankTransfer(obj, 5, 1, 20)); // expect: 1
  printf("%d\n", bankDeposit(obj, 5, 20));     // expect: 1
  printf("%d\n", bankTransfer(obj, 3, 4, 15)); // expect: 0
  printf("%d\n", bankWithdraw(obj, 10, 50));   // expect: 0
  bankFree(obj);
}
