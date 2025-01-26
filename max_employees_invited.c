// 2127. Maximum Employees to Be Invited to a Meeting
#include "leetcode.h"

/*
 * a company is organising a meeting and has a list of 'n' employees, waiting to
 * be invited. they have arrange for a large circular table, capable of seating
 * any number of employees. the employees are numbered from 0 to 'n - 1'. each
 * employee has a favourite person and they will attend the meeting only if they
 * can sit next to their favourite person. the favourite person of an employee
 * is not themselves. given a 0 indexed integer array 'favorite' where
 * 'favorite[i]' denotes the favourite person of the i'th employee, return the
 * maximum number of employees that can be invited.
 */

void topo_sort(const int *favorite, int *indegrees, int *chain_lens, int *stack,
               int node_cnt) {
  int stack_idx = 0;
  for (int i = 0; i < node_cnt; i++)
    if (!indegrees[i])
      stack[stack_idx++] = i;
  while (stack_idx) {
    int node = stack[--stack_idx], nn = chain_lens[node],
        parent = favorite[node], pn = chain_lens[parent];
    if (pn <= nn)
      chain_lens[parent] = nn + 1;
    indegrees[parent]--;
    if (!indegrees[parent])
      stack[stack_idx++] = parent;
  }
}

int traverse(const int *favorite, int *unvis, const int *chain_lens,
             int node_cnt) {
  int largest = 0, sum = 0;
  for (int i = 0; i < node_cnt; i++) {
    if (!unvis[i])
      continue;
    int start = i, curr = i, cn = 0;
    do {
      unvis[curr] = 0;
      cn++;
      curr = favorite[curr];
    } while (curr != start);
    if (cn > 2)
      largest = fmax(largest, cn);
    else
      sum += chain_lens[curr] + chain_lens[favorite[curr]] + 2;
  }
  return fmax(largest, sum);
}

int dfs(int *favorite, int favoriteSize) {
  int *buf = (int *)malloc(3 * favoriteSize * sizeof(int));
  int *indegrees = buf;
  memset(indegrees, 0, favoriteSize * sizeof(int));
  int *chain_lens = indegrees + favoriteSize;
  memset(chain_lens, 0, favoriteSize * sizeof(int));
  int *stack = chain_lens + favoriteSize;
  for (int i = 0; i < favoriteSize; i++) {
    int parent = favorite[i];
    indegrees[parent]++;
  }
  topo_sort(favorite, indegrees, chain_lens, stack, favoriteSize);
  int ans = traverse(favorite, indegrees, chain_lens, favoriteSize);
  free(buf);
  return ans;
}

int maximumInvitations(int *favorite, int favoriteSize) {
  return dfs(&favorite[0], favoriteSize);
}

int main() {
  int f1[] = {2, 2, 1, 2}, f2[] = {1, 2, 0}, f3[] = {3, 0, 1, 4, 1};
  printf("%d\n", maximumInvitations(f1, ARRAY_SIZE(f1))); // expect: 3
  printf("%d\n", maximumInvitations(f2, ARRAY_SIZE(f2))); // expect: 3
  printf("%d\n", maximumInvitations(f3, ARRAY_SIZE(f3))); // expect: 4
}
