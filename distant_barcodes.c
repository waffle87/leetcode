// 1054. Distant Barcodes
#include "leetcode.h"

/*
 * in a warehouse, there is a row of barcodes where the i'th barcode is
 * 'barcodes[i]'. rearrange the barcodes so that no two adjacent barcodes are
 * equal. you may return any answer, and it is guaranteed that an answer exists
 */

int cmp(const void *a, const void *b) { return (*(int *)b - *(int *)a); }

int *rearrangeBarcodes(int *barcodes, int barcodesSize, int *returnSize) {
  int *cnt = (int *)calloc(1e4 + 1, sizeof(int)), max_val = 0;
  for (int i = 0; i < barcodesSize; i++) {
    cnt[barcodes[i]] = (cnt[barcodes[i]] + 0x10000) | barcodes[i];
    max_val = fmax(max_val, barcodes[i]);
  }
  qsort(cnt, max_val + 1, sizeof(int), cmp);
  int idx = 0, b_idx = 0;
  while (cnt[idx]) {
    int curr = cnt[idx] & 0xFFFF;
    cnt[idx] >>= 16;
    for (int i = 0; i < cnt[idx]; i++) {
      barcodes[b_idx] = curr;
      b_idx += 2;
      if (b_idx >= barcodesSize)
        b_idx = 1;
    }
    cnt[idx++] = 0;
  }
  *returnSize = barcodesSize;
  return barcodes;
}

int main() {
  int b1[] = {1, 1, 1, 2, 2, 2}, b2[] = {1, 1, 1, 1, 2, 2, 3, 3}, rs1, rs2;
  int *rb1 = rearrangeBarcodes(b1, ARRAY_SIZE(b1), &rs1);
  int *rb2 = rearrangeBarcodes(b2, ARRAY_SIZE(b2), &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%d ", rb1[i]); // expect: 2,1,2,1,2,1
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%d ", rb2[i]); // expect: 1,3,1,3,1,2,1,2
  printf("\n");
  free(rb1), free(rb2);
}
