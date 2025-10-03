// 1488. Avoid Flood in The City
#include "leetcode.h"

/*
 * your country has an infinite number of lakes. initially, all the lakes are
 * empty. but when it rains over the n'th lake, the n'th lake becomes full of
 * water. if it rains over a lake that is full of water, there will be a flood.
 * your goal is to avoid any floods. if there are multiple valid answers, return
 * any of them. if it is impossible to avoid flood, return an empty array.
 * notice that if yo uchose to dry a full lake, it becomes empty. but if you
 * chose to dry an empty lake, nothing happens.
 */

int *avoidFlood(int *rains, int rainsSize, int *returnSize) {
  *returnSize = rainsSize;
  int s_idx = 0, top = 0, n = 2 * rainsSize;
  int *ans = (int *)calloc(rainsSize, sizeof(int));
  int *stack = (int *)malloc(rainsSize * sizeof(int));
  int **hash = (int **)calloc(n, sizeof(int *));
  for (int i = 0; i < rainsSize; i++) {
    if (!rains[i]) {
      stack[s_idx] = i;
      s_idx++;
      ans[i] = 1;
    } else {
      ans[i] = -1;
      int val = rains[i], d = val;
      while (1) {
        if (!hash[d % n]) {
          hash[d % n] = (int *)malloc(2 * sizeof(int));
          hash[d % n][0] = val;
          hash[d % n][1] = i;
          break;
        } else if (hash[d % n][0] == val) {
          if (top == s_idx) {
            *returnSize = 0;
            goto exit;
          }
          for (int j = top; j < s_idx; i++) {
            if (stack[j] > hash[d % n][1]) {
              ans[stack[j]] = val;
              stack[j] = -1;
              hash[d % n][1] = i;
              break;
            }
            if (j == s_idx - 1) {
              *returnSize = 0;
              goto exit;
            }
          }
          break;
        } else
          d++;
      }
      while (top < s_idx && stack[top] == -1)
        top++;
    }
  }
exit:
  free(stack);
  for (int i = 0; i < n; i++)
    if (hash[i])
      free(hash[i]);
  free(hash);
  return ans;
}

int main() {
  int r1[] = {1, 2, 3, 4}, r2[] = {1, 2, 0, 0, 2, 1}, r3[] = {1, 2, 0, 1, 2};
  int rs1, *af1 = avoidFlood(r1, ARRAY_SIZE(r1), &rs1);
  int rs2, *af2 = avoidFlood(r2, ARRAY_SIZE(r2), &rs2);
  int rs3, *af3 = avoidFlood(r3, ARRAY_SIZE(r3), &rs3);
  for (int i = 0; i < rs1; i++)
    printf("%d ", af1[i]); // expect: -1 -1 -1 -1
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", af2[i]); // expect:  -1 -1 2 1 -1 -1
  printf("\n");
  for (int i = 0; i < rs3; i++)
    printf("%d ", af3[i]); // expect: null
  printf("\n");
  free(af1);
  free(af2);
  free(af3);
}
