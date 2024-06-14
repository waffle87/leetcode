// 2251. Number of Flowers in Full Bloom
#include <limits.h>
#include <stdlib.h>

/*
 * given a 0-indexed 2d integer array 'flowers', where 'flowers[i] = [start[i],
 * end[i]]' means the i'th flower will be in full bloom from 'start[i]' to
 * 'end[i]' (inclusive). you are also given a 0-indexed integer array 'people'
 * of size 'n' where 'people[i]' is the time that the i'th person will arrive to
 * see the flowers. return an integer array 'answer' of size 'n' where
 * 'answer[i]' is the number of flowers that are in full bloom when the i'th
 * person arrives.
 */

struct pp {
  int person;
  int rank;
};

int cmp(const void *a, const void *b) {
  return (*(struct pp *)a).person > (*(struct pp *)b).person ? 1 : -1;
}

int *fullBloomFlowers(int **flowers, int flowers_size, int *flowers_col_size,
                      int *people, int people_size, int *return_size) {
  *return_size = people_size;
  int *ans = calloc(people_size, sizeof(int)), cnt = 0;
  struct pp *list = malloc(sizeof(struct pp) * (people_size));
  struct pp *tree = malloc(sizeof(struct pp) * (flowers_size * 2 + 1));
  for (int i = 0; i < flowers_size; i++) {
    tree[cnt].person = flowers[i][0];
    tree[cnt].rank = 1;
    cnt++;
    tree[cnt].person = flowers[i][1] + 1;
    tree[cnt].rank = -1;
    cnt++;
  }
  for (int i = 0; i < people_size; i++) {
    list[i].person = people[i];
    list[i].rank = i;
  }
  qsort(tree, flowers_size * 2, sizeof(struct pp), cmp);
  qsort(list, people_size, sizeof(struct pp), cmp);
  tree[cnt].person = INT_MAX;
  int now = 0, flower = 0;
  for (int i = 0; i < people_size; i++) {
    while (list[i].person >= tree[now].person) {
      flower += tree[now].rank;
      now++;
    }
    ans[list[i].rank] = flower;
  }
  free(list), free(tree);
  return ans;
}
