#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
  return (*(int **)a)[0] - (*(int **)b)[0];
}

int cmp1d(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int ufFind(int *class, int num) {
  int res = num;
  while (class[res] != res)
    res = class[res];
  class[num] = res;
  return res;
}

void ufUnion(int *class, int a, int b) {
  int numA = ufFind(class, a);
  int numB = ufFind(class, b);
  if (numA == numB)
    return;
  if (numA < numB) {
    class[numB] = numA;
    class[b] = numA;
  } else {
    class[numA] = numB;
    class[a] = numB;
  }
}

int numberOfGoodPaths(int *vals, int valsSize, int **edges, int edgesSize,
                      int *edgesColSize) {
  int ans = 0;
  int **qData = malloc(valsSize * sizeof(int *));
  int *class = malloc(valsSize * sizeof(int));
  int *tmp = malloc(valsSize * sizeof(int));
  int **qEdges = malloc(edgesSize * sizeof(int *));
  for (int i = 0; i < valsSize; i++) {
    qData[i] = malloc(2 * sizeof(int));
    class[i] = i;
    qData[i][0] = vals[i];
    qData[i][1] = i;
  }
  for (int i = 0; i < edgesSize; i++) {
    qEdges[i] = malloc(3 * sizeof(int));
    qEdges[i][0] = (vals[edges[i][0]] > vals[edges[i][1]]) ? vals[edges[i][0]]
                                                           : vals[edges[i][1]];
    qEdges[i][1] = edges[i][0];
    qEdges[i][2] = edges[i][1];
  }
  qsort(qData, valsSize, sizeof(qData[0]), cmp);
  qsort(qEdges, edgesSize, sizeof(qEdges[0]), cmp);
  int edgesIdx = 0, left = 0, right = 0;
  while (right < valsSize) {
    while (edgesIdx < edgesSize && qEdges[edgesIdx][0] <= qData[right][0]) {
      ufUnion(class, qEdges[edgesIdx][1], qEdges[edgesIdx][2]);
      edgesIdx++;
    }
    left = right;
    int tmpIdx = 0, cnt = 0;
    while (right < valsSize && qData[left][0] == qData[right][0]) {
      tmp[tmpIdx++] = class[qData[right][1]];
      right++;
    }
    qsort(tmp, tmpIdx, sizeof(tmp[0]), cmp1d);
    for (int i = 0; i < tmpIdx; i++) {
      if (tmp[i] == tmp[i - 1])
        cnt++;
      else
        cnt = 0;
      ans += cnt;
    }
  }
  return ans + valsSize;
}

int main() {
  int vals1[] = {1, 3, 2, 1, 3}, vals2[] = {1, 1, 2, 2, 3}, vals3[] = {1};
  int valsSize1 = 5, valsSize2 = 5, valsSize3 = 1;
  int edges1[4][2] = {{0, 1}, {0, 2}, {2, 3}, {2, 4}},
      edges2[4][2] = {{0, 1}, {1, 2}, {2, 3}, {2, 4}}, edges3[0][0] = {};
}
