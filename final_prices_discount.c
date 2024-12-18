// 1475. Final Prices With a Special Discount in a Shop
#include "leetcode.h"

/*
 * you are given an integer array 'prices' where 'prices[i]' is the price of the
 * i'th item in a shop. there is a special discount for items in the shop. if
 * you buy the i'th item, then you will receive a discount equivalent to
 * 'prices[j]' where 'j' is the minimum index such that 'j > i' and 'prices[j]
 * <= prices[i]'. otherwise, you will not receive any discount at all. return an
 * integer array 'answer' where 'answer[i]' is the final price you will pay for
 * the i'th item of the shop, considering the special discount
 */

int *finalPrices(int *prices, int pricesSize, int *returnSize) {
  int *ans = (int *)malloc(pricesSize * sizeof(int));
  *returnSize = 0;
  for (int i = 0; i < pricesSize; i++) {
    bool flag = false;
    for (int j = i + 1; j < pricesSize; j++)
      if (prices[i] >= prices[j]) {
        ans[(*returnSize)++] = prices[i] - prices[j];
        flag = true;
        break;
      }
    if (!flag)
      ans[(*returnSize)++] = prices[i];
  }
  return ans;
}

int main() {
  int p1[] = {8, 4, 6, 2, 3}, p2[] = {1, 2, 3, 4, 5}, p3[] = {10, 1, 1, 6};
  int rs1, rs2, rs3;
  int *fp1 = finalPrices(p1, ARRAY_SIZE(p1), &rs1);
  int *fp2 = finalPrices(p2, ARRAY_SIZE(p2), &rs2);
  int *fp3 = finalPrices(p3, ARRAY_SIZE(p3), &rs3);
  for (int i = 0; i < rs1; i++)
    printf("%d ", fp1[i]); // expect: 4 2 4 2 3
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", fp2[i]); // expect: 1 2 3 4 5
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", fp3[i]); // expect: 9 0 1 6
  printf("\n");
  free(fp1), free(fp2), free(fp3);
}
