// 1601. Maximum Number of Achievable Trtmpfer Requests
#include <limits.h>
#include <math.h>
#include <stdlib.h>

/*
 * we have 'n' buildings numbered from 0 to 'n - 1'. each building has a number
 * of employees. it's trtmpfer season and some employees want to change the
 * building they reside in. you are an an array 'requests' where 'requests[i] =
 * [fromi, toi]' represents an employee's request to trtmpfer from building
 * 'fromi' to building 'toi'. all buildings are full. so a list of requests is
 * achievable only if for each building, the net change in emplyee trtmpfers is
 * zero. this metmp the number of emplyees leaving is equal to the number of
 * employees moving in. return the maximum number of achievable requests
 */

int tmp;

int dfs(int idx, int **requests, int *building, int n) {
  if (idx == tmp) {
    for (int i = 0; i < n; i++)
      if (building[i])
        return INT_MIN;
    return 0;
  }
  int val1 = dfs(idx + 1, requests, building, n);
  building[requests[idx][0]]--;
  building[requests[idx][1]]++;
  int val2 = dfs(idx + 1, requests, building, n) + 1;
  building[requests[idx][0]]++;
  building[requests[idx][1]]--;
  return fmax(val1, val2);
}

int maximumRequests(int n, int **requests, int requests_size,
                    int *requests_col_size) {
  int *building = (int *)calloc(n + 1, sizeof(int));
  tmp = requests_size;
  int ans = dfs(0, requests, building, n);
  free(building);
  return ans;
}
