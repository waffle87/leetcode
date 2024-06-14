// 1444. Number of Ways of Cutting a Pizza
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * given rectangular pizza represented as a rows x cols matrix containing the
 * following characters 'A' an apple and '.' empty cell, and given integer 'k'.
 * you have to cut the pizza into 'k' pieces using 'k - 1' cuts.
 */

int ways(char **pizza, int pizza_size, int k) {}

int main() {
  char p1[][3] = {{"A.."}, {"AAA"}, {"..."}};
  char p2[][3] = {{"A.."}, {"AA."}, {"..."}};
  char p3[][3] = {{"A.."}, {"A.."}, {"..."}};
  printf("%d\n", ways(p1, 3, 3)); // expect: 3
  printf("%d\n", ways(p2, 3, 3)); // expect: 1
  printf("%d\n", ways(p3, 3, 1)); // expect: 1
}
