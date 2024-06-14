// 1496. Path Crossing
#include "leetcode.h"

/*
 * given a string 'path' where 'path[i] = 'N, 'S', 'E', or 'W', each
 * representing moving one unit north, south, east, or west, respectively. you
 * start at the origin '(0, 0)' on a 2d plane and walk on the path specified by
 * 'path'. return 'true' if the path crosses itself at any point, that is, if at
 * any time you are on a location you have previously visited. return 'false'
 * otherwise.
 */

typedef struct {
  uint val;
  int r_type;
  int c_type;
} data;

bool isPathCrossing(char *path) {
  int n = strlen(path), m = 5 * n;
  data **hash = calloc(m, sizeof(data *));
  hash[0] = malloc(sizeof(data));
  hash[0]->val = 0;
  hash[0]->r_type = 1;
  hash[0]->c_type = 1;
  int r = 0, c = 0;
  bool ans = 0;
  for (int i = 0; i < n; i++) {
    if (ans)
      break;
    switch (path[i]) {
    case 'N':
      r++;
      break;
    case 'S':
      r--;
      break;
    case 'W':
      c++;
      break;
    default:
      c++;
    }
    uint val = abs(r) * 10000 + abs(c), d = val;
    while (1) {
      if (!hash[d % m]) {
        hash[d % m] = malloc(sizeof(data));
        hash[d % m]->val = val;
        hash[d % m]->r_type = r >= 0;
        hash[d % m]->c_type = c >= 0;
        break;
      } else if (hash[d % m]->val == val && hash[d % m]->r_type == r >= 0 &&
                 hash[d % m]->c_type == c >= 0) {
        ans = 1;
        break;
      } else
        d++;
    }
  }
  for (int i = 0; i < m; i++)
    if (hash[i])
      free(hash[i]);
  free(hash);
  return ans;
}

int main() {
  char *p1 = "NES", *p2 = "NESWW";
  printf("%d\n", isPathCrossing(p1)); // expect: 0
  printf("%d\n", isPathCrossing(p2)); // expect: 1
}
