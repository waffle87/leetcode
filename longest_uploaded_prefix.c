// 2424. Longest Uploaded Prefix
#include "leetcode.h"

/*
 * given a string of 'n' videos, each represented by a distinct number from 1 to
 * n that you need to upload to a server. you need to implement a data structure
 * that calculates the length of the longest uploaded prefix at various points
 * in the upload process. we consider i to be uploaded prefix if all videos in
 * the range 1 to i inclusive have been uploaded to the server. the longest
 * uploaded prefix is the maximum value of 'i' that satisfies this definition.
 */

typedef struct {
  bool *data;
  int size;
  int longest;
} LUPrefix;

LUPrefix *lUPrefixCreate(int n) {
  LUPrefix *res = malloc(sizeof(LUPrefix));
  res->data = calloc(n + 1, sizeof(bool));
  res->size = n;
  res->longest = 0;
  return res;
}

void lUPrefixUpload(LUPrefix *obj, int video) {
  obj->data[video] = 1;
  if (obj->data[1]) {
    int i = obj->longest + 1;
    for (i = obj->longest + 1; i <= obj->size; i++)
      if (!obj->data[i])
        break;
    obj->longest = i - 1;
  }
}

int lUPrefixLongest(LUPrefix *obj) { return obj->longest; }

void lUPrefixFree(LUPrefix *obj) {
  free(obj->data);
  free(obj);
}

/**
 * Your LUPrefix struct will be instantiated and called as such:
 * LUPrefix* obj = lUPrefixCreate(n);
 * lUPrefixUpload(obj, video);

 * int param_2 = lUPrefixLongest(obj);

 * lUPrefixFree(obj);
*/

int main() {
  LUPrefix *obj = lUPrefixCreate(4);
  lUPrefixUpload(obj, 3);
  printf("%d\n", lUPrefixLongest(obj)); // expect: 0
  lUPrefixUpload(obj, 1);
  printf("%d\n", lUPrefixLongest(obj)); // expect: 1
  lUPrefixUpload(obj, 2);
  printf("%d\n", lUPrefixLongest(obj)); // expect: 3
  lUPrefixFree(obj);
}
