// 2284. Sender With Largest Word Count
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * you have a chat log of 'n' messages. you are given two string arrays
 * 'messages' and 'senders' where 'messages[i]' is a message sent by
 * 'senders[i]'. a message is a list of words that are separated by a single
 * space with no leading or trailing spaces. the word count of a sender is the
 * total number of words sent by the sender. note that a sender may send more
 * than one message. return the sender with the largest word count. if there is
 * more than one sender with the largest word count, return the one with the
 * lexicographically largest name
 */

typedef struct {
  uint val;
  char *str;
  int cnt;
} dict;

uint rs_hash(char *str) {
  uint a = 63689, b = 378551, hash = 0;
  while (*str) {
    hash = hash * a + (*str++);
    a *= b;
  }
  return (hash & 0x7FFFFFFF);
}

int cmp(const void *a, const void *b) {
  dict aa = **(dict **)a;
  dict bb = **(dict **)b;
  if (aa.cnt == bb.cnt)
    return strcmp(aa.str, bb.str);
  return aa.cnt - bb.cnt;
}

char *largestWordCount(char **messages, int messages_size, char **senders,
                       int senders_size) {
  int n = senders_size, *words = calloc(n, sizeof(int));
  for (int i = 0; i < n; i++) {
    int len = strlen(messages[i]);
    if (!len) {
      words[i] = 0;
      continue;
    }
    words[i] = 1;
    for (int j = 0; j < len; j++)
      if (messages[i][j] == ' ')
        words[i]++;
    dict **hash = malloc(n * sizeof(dict *));
    for (int i = 0; i < n; i++) {
      hash[i] = malloc(sizeof(dict));
      hash[i]->cnt = 0;
    }
    int max = 0, pos = 0;
    dict **max_data = malloc(n * sizeof(dict *));
    for (int i = 0; i < n; i++) {
      uint h = rs_hash(senders[i]);
      if (!hash[h % n]->cnt) {
        hash[h % n]->cnt = words[i];
        int len = strlen(senders[i]);
        hash[h % n]->str = malloc((len + 1) * sizeof(char));
        strcpy(hash[h % n]->str, senders[i]);
        hash[h % n]->val = h;
        if (hash[h % n]->cnt == max) {
          max_data[pos] = hash[h % n];
          pos++;
        }
        if (hash[h % n]->cnt > max) {
          pos = 0;
          max = hash[h % n]->cnt;
          max_data[pos] = hash[h % n];
          pos++;
        }
      } else if (hash[h % n]->val == h) {
        hash[h % n]->cnt += words[i];
        if (hash[h % n]->cnt == max) {
          max_data[pos] = hash[h % n];
          pos++;
        }
        if (hash[h % n]->cnt > max) {
          pos = 0;
          max = hash[h % n]->cnt;
          max_data[pos] = hash[h % n];
          pos++;
        }
      } else {
        int k = (h + 1) % n;
        bool done = false;
        while (hash[k]->cnt) {
          if (hash[k]->val == h) {
            hash[k]->cnt += words[i];
            if (hash[k]->cnt == max) {
              max_data[pos] = hash[k];
              pos++;
            }
            if (hash[k]->cnt > max) {
              pos = 0;
              max = hash[k]->cnt;
              max_data[pos] = hash[k];
              pos++;
            }
            done = true;
            break;
          }
          k = (k + 1) % n;
        }
        if (!done) {
          hash[k]->val = h;
          hash[k]->cnt = words[i];
          int len = strlen(senders[i]);
          hash[k]->str = malloc((len + 1) * sizeof(char));
          strcpy(hash[k]->str, senders[i]);
          if (hash[k]->cnt == max) {
            max_data[pos] = hash[k];
            pos++;
          }
          if (hash[k]->cnt > max) {
            pos = 0;
            max = hash[k]->cnt;
            max_data[pos] = hash[k];
            pos++;
          }
        }
      }
    }
    qsort(max_data, pos, sizeof(dict *), cmp);
    return max_data[pos - 1]->str;
  }
}

int main() {
  char m1[4][19] = {"Hello userTwooo", "Hi userThree", "Wonderful day Alice",
                    "Nice day userThree"};
  char s1[4][9] = {"Alice", "userTwo", "userThree", "Alice"};
  char m2[2][31] = {"How is leetcode for everyone",
                    "Leetcode is useful for practice"};
  char s2[2][7] = {"Bob", "Charlie"};
  printf("%s\n", largestWordCount(m1, 4, s1, 4)); // expect: Alice
  printf("%s\n", largestWordCount(m2, 2, s2, 2)); // expect: Charlie
}
