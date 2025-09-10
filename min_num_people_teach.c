// 1733. Minimum Number of People to Teach
#include "leetcode.h"

/*
 * on a social network consisting of 'm' users and some friendships between
 * users, two users can communicate with each other if they know a common
 * language. you are given an integer 'n', an array 'languages', and an array
 * 'friendships' where there are 'n' languages numbered 1 through 'n',
 * 'languages[i]' is the set of languages the i'th user knows, and
 * 'friendships[i] = [ui, vi]' denotes a friendship between the users 'ui' and
 * 'vi'. you can choose one language and teach it to some users so that all
 * friends can communicate with eachother. return the minimum number of users
 * you need to teach. note that friendships are not transitive, meaning if 'x'
 * is a friend of 'y' and 'y' is a friend of 'z', this doesn't guarantee 'x' is
 * a friend of 'z'.
 */

int minimumTeachings(int n, int **languages, int languagesSize,
                     int *languagesColSize, int **friendships,
                     int friendshipsSize, int *friendshipsColSize) {
  bool need[505] = {false};
  for (int i = 0; i < friendshipsSize; i++) {
    int u = friendships[i][0] - 1;
    int v = friendships[i][1] - 1;
    bool valid = false;
    for (int j = 0; j < languagesColSize[u]; j++) {
      for (int k = 0; k < languagesColSize[v]; k++)
        if (languages[u][j] == languages[v][k]) {
          valid = true;
          break;
        }
      if (valid)
        break;
    }
    if (!valid)
      need[u] = need[v] = true;
  }
  int ans = languagesSize + 1;
  for (int i = 1; i <= n; i++) {
    int candidate = 0;
    for (int j = 0; j < languagesSize; j++) {
      if (need[j]) {
        bool found = false;
        for (int k = 0; k < languagesColSize[j]; k++)
          if (languages[j][k] == i) {
            found = true;
            break;
          }
        if (!found)
          candidate++;
      }
    }
    if (candidate < ans)
      ans = candidate;
  }
  return ans;
}

int main() {
  int l1i[3][2] = {{1}, {2}, {1, 2}}, lcs1[] = {};
  int f1i[3][2] = {{1, 2}, {1, 3}, {2, 3}};
  int l2i[4][2] = {{2}, {1, 3}, {1, 2}, {3}}, lcs2[] = {};
  int f2i[4][2] = {{1, 4}, {1, 2}, {3, 4}, {2, 3}};
  for (int i = 0; i < ARRAY_SIZE(l1i); i++)
    lcs1[i] = ARRAY_SIZE(l1i[i]);
  for (int i = 0; i < ARRAY_SIZE(l2i); i++)
    lcs2[i] = ARRAY_SIZE(l2i[i]);
  struct two_d_arr *l1 =
      two_d_arr_init(ARRAY_SIZE(l1i), ARRAY_SIZE(l1i[2]), l1i);
  struct two_d_arr *f1 =
      two_d_arr_init(ARRAY_SIZE(f1i), ARRAY_SIZE(f1i[0]), f1i);
  struct two_d_arr *l2 =
      two_d_arr_init(ARRAY_SIZE(l2i), ARRAY_SIZE(l2i[1]), l2i);
  struct two_d_arr *f2 =
      two_d_arr_init(ARRAY_SIZE(f2i), ARRAY_SIZE(f2i[0]), f2i);
  printf("%d\n", minimumTeachings(2, l1->arr, l1->row_size, lcs1, f1->arr,
                                  f1->row_size, f1->col_size)); // expect: 1
  printf("%d\n", minimumTeachings(3, l2->arr, l2->row_size, lcs2, f2->arr,
                                  f2->row_size, f2->col_size)); // expect: 2
  two_d_arr_free(l1);
  two_d_arr_free(f1);
  two_d_arr_free(l2);
  two_d_arr_free(f2);
}
