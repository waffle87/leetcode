// 1436. Destination City
#include "leetcode.h"

/*
 * given the array 'paths' where 'paths[i] = [citya[i], cityb[i]]' means there
 * exists a direct path going from 'citya[i]' to 'cityb[i]'. return the
 * destination city that is the city without any path outgoing to another city.
 * it is guaranteed that the graph of paths forms a line without any loop,
 * therefore there will be exactly one destination.
 */

char *destCity(char ***paths, int paths_size, int *paths_col_size) {
  char *dest = paths[0][1];
  for (int i = 1; i < paths_size; i++)
    if (!strcmp(paths[i][0], dest)) {
      dest = paths[i][1];
      i = 0;
    }
  return dest;
}

int main() {
  char ***p1 = {
      {"London", "New York"}, {"New York", "Lima"}, {"Lima", "Sao Paulo"}};
  char ***p2 = {{"B", "C"}, {"D", "B"}, {"C", "A"}};
  printf("%s\n", destCity(p1, 3, NULL));
  printf("%s\n", destCity(p2, 3, NULL));
}
