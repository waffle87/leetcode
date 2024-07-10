// 1598. Crawler Log Folder
#include "leetcode.h"

/*
 * the leetcode file system keeps a log each time some user performs a change
 * folder operation. the operations are described below. "../" move to the
 * parent folder of the current folder. if you are already in the main folder,
 * remain in the same folder. "./" remain in the same folder. "x/" move to the
 * child folder named 'x' which is guaranteed to exist. you are given a list of
 * strings 'logs' where 'logs[i]' is the operation performed by the user at the
 * i'th step.
 */

int minOperations(char **logs, int logsSize) {
  int steps = 0;
  char *parent = "../", *curr = "./";
  for (int i = 0; i < logsSize; i++) {
    if (logs[i] == parent)
      steps = fmax(steps - 1, 0);
    else if (logs[i] != curr)
      steps++;
  }
  return steps;
}

int main() {
  char *l1[] = {"d1/", "d2/", "../", "d21/", "./"},
       *l2[] = {"d1/", "d2/", "./", "d3/", "../", "d31/"},
       *l3[] = {"d1/", "../", "../", "../"};
  printf("%d\n", minOperations((char **)l1, ARRAY_SIZE(l1))); // execpt: 2
  printf("%d\n", minOperations((char **)l2, ARRAY_SIZE(l2))); // execpt: 3
  printf("%d\n", minOperations((char **)l3, ARRAY_SIZE(l3))); // execpt: 0
}
