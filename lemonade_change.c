// 860. Lemonade Change
#include <stdbool.h>
#include <stdio.h>

/*
 * at a lemonade stand, each lemonade costs $5. customers are standing in a
 * queue to buy from you and order one at a time. each customer will only buy
 * one lemonade and pay with either $5, $10, or $20 bill. you must provide the
 * correct change to each customer so that the net transaction is that the
 * customer pays $5. note that you do not have any change in hand at first.
 * given an integer array 'bills' where 'bills[i]' is the bill the i'th customer
 * pays, return true if you can provide every customer with the correct change,
 * or false otherwise
 */

bool lemonadeChange(int *bills, int bills_size) {
  int five = 0, ten = 0;
  while (bills_size--) {
    switch (*bills++) {
    case 5:
      ++five;
      break;
    case 10:
      ++ten;
      break;
    case 20:
      !ten ? five -= 3 : --ten, --five;
      break;
    }
    if (five < 0)
      return false;
  }
  return true;
}

int main() {
  int b1[] = {5, 5, 5, 10, 20}, b2[] = {5, 5, 10, 10, 20};
  printf("%d\n", lemonadeChange(b1, 5)); // expect: 1
  printf("%d\n", lemonadeChange(b2, 5)); // expect: 0
}
