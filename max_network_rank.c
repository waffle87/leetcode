// 1615. Maximal Network Rank
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

/*
 * there is an infrastructure of 'n' cities with some number of 'roads'
 * connecting these cities. each 'roads[i] = [ai, bi]'. indicates that there is
 * a bidirectional road between cities 'ai' and 'bi'. the network rank of two
 * different cities is defined as the total number of directly conncected roads
 * to either city. if a road is directly connected to both cities, it is only
 * counted once. the maximal network rank of the infrastructure is the maximum
 * network rank of all pairs of different cities. given the integer 'n' and the
 * array 'roads', return the maximal network rank of the entire infrastructure.
 */

int maximalNetworkRank(int n, int **roads, int roads_size,
                       int *roads_col_size) {
  bool **connect = malloc(n * sizeof(bool *));
  for (int i = 0; i < n; i++)
    connect[i] = calloc(n, sizeof(bool));
  int *edges = calloc(n, sizeof(int));
  for (int i = 0; i < roads_size; i++) {
    int a = roads[i][0];
    int b = roads[i][1];
    connect[a][b] = true;
    connect[b][a] = true;
    edges[a]++;
    edges[b]++;
  }
  int ans = INT_MIN;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      int rank = edges[i] + edges[j] - connect[i][j];
      ans = fmax(ans, rank);
    }
  for (int i = 0; i < n; i++)
    free(connect);
  free(connect), free(edges);
  return ans;
}
