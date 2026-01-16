// 2975. Maximum Square Area by Removing Fences From a Field
#include "leetcode.h"

/*
 * there is a large '(m - 1) + (n - 1)' rectangular field with corners at '(1,
 * 1)' and '(m, n)' containing some horizontal and vertical fences given in
 * arrays 'hFences' and 'vFences' respectively. horizontal fences are from the
 * coordinates '(hFences[i], 1)' to '(hFences[i], n)' and vertical fences the
 * corresponding appropriately. return the maximum area of a square field that
 * can be formed by removing somee fences or -1 if is impossible to make a
 * square field.
 */

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int maximizeSquareArea(int m, int n, int *hFences, int hFencesSize,
                       int *vFences, int vFencesSize) {
  static int mod = 1e9 + 7;
  long long ans = -1;
  qsort(hFences, hFencesSize, sizeof(int), cmp);
  qsort(vFences, vFencesSize, sizeof(int), cmp);
  int *h = (int *)malloc((hFencesSize + 2) * sizeof(int));
  int *v = (int *)malloc((vFencesSize + 2) * sizeof(int));
  for (int i = 0; i < hFencesSize; i++)
    h[i + 1] = hFences[i];
  h[0] = 1;
  h[hFencesSize + 1] = m;
  for (int i = 0; i < vFencesSize; i++)
    v[i + 1] = vFences[i];
  v[vFencesSize + 1] = n;
  int square = fmin(n, m);
  char *h_map = (char *)calloc((square + 8) / 8, sizeof(char));
  char *v_map = (char *)calloc((square + 8) / 8, sizeof(char));
  for (int i = 0; i < hFencesSize + 2; i++)
    for (int j = i + 1; j < hFencesSize + 2; j++) {
      if (h[j] - h[i] >= square)
        continue;
      int byte = (h[j] - h[i]) / 8;
      int shift = (h[j] - h[i]) % 8;
      h_map[byte] |= 1 << shift;
    }
  for (int i = 0; i < vFencesSize + 2; i++)
    for (int j = i + 1; j < vFencesSize + 2; j++) {
      if (v[j] - v[i] >= square)
        continue;
      int byte = (v[j] - v[i]) / 8;
      int shift = (v[j] - v[i]) % 8;
      v_map[byte] |= 1 << shift;
    }
  for (int i = square - 1; i > 0; i--) {
    int byte = i / 8, shift = i % 8;
    if ((h_map[byte] & v_map[byte]) & (1 << shift)) {
      if (i > mod)
        i %= mod;
      ans = (unsigned long long)i * i;
      ans %= mod;
      break;
    }
  }
  free(h);
  free(v);
  free(h_map);
  free(v_map);
  return ans;
}

int main() {
  int hf1[] = {2, 3}, vf1[] = {2};
  int hf2[] = {2}, vf2[] = {4};
  printf("%d\n", maximizeSquareArea(4, 3, hf1, ARRAY_SIZE(hf1), vf1,
                                    ARRAY_SIZE(vf1))); // expect: 4
  printf("%d\n", maximizeSquareArea(6, 7, hf2, ARRAY_SIZE(hf2), vf2,
                                    ARRAY_SIZE(vf2))); // expect: -1
}
