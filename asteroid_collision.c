// 735. Asteroid Collision
#include <stdio.h>
#include <stdlib.h>

/*
 * given an array 'asteroids' o intergers representing asteroids in a row. for
 * each asteroid, the absolute value represents its size, and the sign
 * represents its direction (positive meaning right, negative meaning left).
 * each asteroid moves at the same speed. find out the state of the asteroids
 * after all collisions. if two asteroids meet the smaller one will explode. if
 * both are the same size, both will explode. two asteroids moving in the same
 * direction will never meet.
 */

int *asteroidCollision(int *asteroids, int asteroids_size, int *return_size) {
  int n = asteroids_size, ans_idx = 0;
  int *ans = malloc(n * sizeof(int));
  ans[ans_idx] = asteroids[ans_idx];
  for (int i = 0; i < n; i++) {
    ans_idx++;
    ans[ans_idx] = asteroids[i];
    while (ans_idx && ans[ans_idx] < 0 && ans[ans_idx - 1]) {
      if (abs(ans[ans_idx]) == abs(ans[ans_idx - 1])) {
        ans_idx -= 2;
        continue;
      }
      if (abs(ans[ans_idx]) > abs(ans[ans_idx - 1])) {
        ans[ans_idx - 1] = ans[ans_idx];
        ans_idx--;
      } else
        ans_idx--;
    }
  }
  *return_size = ans_idx + 1;
  ans = realloc(ans, (*return_size) * sizeof(int));
  return ans;
}

int main() {
  int a1[] = {5, 10, -5}, a2[] = {8, -8}, a3[] = {10, 2, -5};
  int as1 = 3, as2 = 2, as3 = 3;
  int rs1[] = {}, rs2[] = {}, rs3[] = {};
  int *ac1 = asteroidCollision(a1, as1, rs1);
  int *ac2 = asteroidCollision(a2, as2, rs2);
  int *ac3 = asteroidCollision(a3, as3, rs3);
  for (int i = 0; i < as1; i++)
    printf("%d ", ac1[i]); // expect: 5 10
  printf("\n");
  for (int i = 0; i < as2; i++)
    printf("%d ", ac2[i]); // expect:
  printf("\n");
  for (int i = 0; i < as3; i++)
    printf("%d ", ac3[i]); // expect: 10
  printf("\n");
}
