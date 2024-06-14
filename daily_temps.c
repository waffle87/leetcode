// 739. Daily Temperatures
#include "leetcode.h"

/*
 * given an array of integers 'temperatures' represents the daily temperatures
 * return an array 'answer' such that 'answer[i]' is the number of days you have
 * to wait after the i'th day to get a warmer temperature. if there is no future
 * day for which this is possible, keep 'answer[i] == 0' instead.
 */

int *dailyTemperatures(int *temperatures, int temperatures_size,
                       int *return_size) {
  *return_size = temperatures_size;
  int tmp = 0, cnt = temperatures_size - 2;
  int *ans = (int *)malloc(sizeof(int) * temperatures_size);
  ans[temperatures_size - 1] = 0;
  for (int i = temperatures_size - 2; i >= 0; i--)
    for (int j = 1; j + i < temperatures_size; j += tmp) {
      if (temperatures[i] < temperatures[i + j]) {
        ans[cnt--] = j;
        break;
      } else if (!ans[i + j]) {
        ans[cnt--] = 0;
        break;
      }
      tmp = ans[i + j];
    }
  return ans;
}

int main() {
  int t1[] = {73, 74, 75, 71, 69, 72, 76, 73}, t2[] = {30, 40, 50, 60},
      t3[] = {30, 60, 90};
  int rs1[] = {}, rs2[] = {}, rs3[] = {};
  int *dt1 = dailyTemperatures(t1, ARRAY_SIZE(t1), rs1);
  int *dt2 = dailyTemperatures(t2, ARRAY_SIZE(t2), rs2);
  int *dt3 = dailyTemperatures(t3, ARRAY_SIZE(t3), rs3);
  for (int i = 0; i < ARRAY_SIZE(t1); i++)
    printf("%d ", dt1[i]); // expect:  1,1,4,2,1,1,0,0
  printf("\n");
  for (int i = 0; i < ARRAY_SIZE(t2); i++)
    printf("%d ", dt2[i]); // expect: 1 1 1 0
  printf("\n");
  for (int i = 0; i < ARRAY_SIZE(t3); i++)
    printf("%d ", dt2[i]); // expect: 1 1 0
  printf("\n");
}
