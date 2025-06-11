// 3445. Maximum Difference Between Even and Odd Frequency II
#include "leetcode.h"

/*
 * you are given a string 's' and an integer 'k'. your task is to find the
 * maximum difference between the frequency of two characters 'freq[a], -
 * freq[b]', in a substring 'subs' of 's' such that 'subs' has a size of at
 * least 'k', character 'a' has an odd frequency in 'subs', character 'b' has an
 * even frequency in 'subs'. return the maximum difference. note that 'subs' can
 * contain more than 2 distinct characters.
 */

static int upper_bound(const int *arr, int n, int key) {
  int low = 0, high = n;
  while (low < high) {
    int mid = low + ((high - low) >> 1);
    if (arr[mid] <= key)
      low = mid + 1;
    else
      high = mid;
  }
  return low;
}

int maxDifference(char *s, int k) {
  int n = strlen(s);
  if (!n || k > n)
    return -1;
  int (*freq)[5] = malloc(sizeof(int[5]) * n), present[5] = {0};
  if (!freq)
    return -1;
  for (int i = 0; i < n; i++) {
    int c = s[i] - '0';
    if (!i)
      memset(freq[i], 0, sizeof(int) * 5);
    else
      memcpy(freq[i], freq[i - 1], sizeof(int) * 5);
    freq[i][c]++;
    present[c] = 1;
  }
  int ans = INT_MIN;
  for (int a = 0; a < 5; a++) {
    if (!present[a])
      continue;
    for (int b = 0; b < 5; b++) {
      if (!present[b] || a == b)
        continue;
      int *idx_list[4], *val_list[4], size[4];
      for (int i = 0; i < 4; i++) {
        idx_list[i] = (int *)malloc(sizeof(int) * n);
        val_list[i] = (int *)malloc(sizeof(int) * n);
        size[i] = 0;
      }
      int odd = 0, even = 0;
      for (int i = 0; i < n; i++) {
        int c = s[i] - '0';
        if (c == a)
          odd++;
        else if (c == b)
          even++;
        if ((odd & 1) && (even & 1) == 0 && (i + 1) >= k && even > 0) {
          int diff = odd - even;
          if (diff > ans)
            ans = diff;
        }
        int key1 = ((odd % 2 == 0) ? 1 : 0) << 1 | ((even % 2 == 0) ? 0 : 1);
        if (size[key1] > 0) {
          int limit = i - k;
          if (limit >= 0) {
            int pos = upper_bound(idx_list[key1], size[key1], limit);
            if (pos > 0) {
              int prev = pos - 1, l = 0, r = prev, curr_min = INT_MAX;
              while (l <= r) {
                int mid = (l + r) >> 1, j = idx_list[key1][mid];
                if (freq[i][b] != freq[j][b]) {
                  int v = val_list[key1][mid];
                  if (v < curr_min)
                    curr_min = v;
                  l = mid + 1;
                } else
                  r = mid - 1;
              }
              if (curr_min != INT_MAX) {
                int cur = odd - even - curr_min;
                if (cur > ans)
                  ans = cur;
              }
            }
          }
        }
        int key2 = (odd % 2) << 1 | (even % 2), curr_diff = odd - even;
        if (!size[key2]) {
          idx_list[key2][0] = i;
          val_list[key2][0] = curr_diff;
          size[key2] = 1;
        } else {
          int prev_min = val_list[key2][size[key2] - 1];
          int new_min = (prev_min < curr_diff) ? prev_min : curr_diff;
          idx_list[key2][size[key2]] = i;
          val_list[key2][size[key2]] = new_min;
          size[key2]++;
        }
      }
      for (int i = 0; i < 4; i++) {
        free(idx_list[i]);
        free(val_list[i]);
      }
    }
  }

  free(freq);
  return (ans == INT_MIN ? -1 : ans);
}

int main() {
  char *s1 = "12233", *s2 = "1122211", *s3 = "110";
  printf("%d\n", maxDifference(s1, 4)); // expect: -1
  printf("%d\n", maxDifference(s2, 3)); // expect: 1
  printf("%d\n", maxDifference(s3, 3)); // expect: -1
}
