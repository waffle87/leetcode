// 68. Text Justification
#include <stdio.h>
#include <stdlib.h>

/*
 * given an array of strings 'words', and a width 'max_width', format the text
 * such that each line has exactly 'max_width' characters and is fully (left and
 * right) justified. you should pack your words in a greedy approach; that is,
 * pack as many words as you can in each line. pad extra spaces ' ' when
 * necessary so that each line has exactly 'max_width' characters. extra spaces
 * between words just be distributed as evenly as possible. if the number of
 * spaces on a line does not divide evenly between the words, the empty slots on
 * the left will be assigned more spaces than the slots on the right. for the
 * last line of text, it should be left-justified, and no extra space is
 * inserted between words.
 */

int get_len(char *s) {
  int len = 0;
  while (s[len])
    len++;
  return len;
}

char *centre_justify(char **words, int words_size, int *len, int start_idx,
                     int end_idx, int max_width) {
  int width = 0;
  for (int i = start_idx; i <= end_idx; i++)
    width += len[i];
  int total_space = max_width - width;
  int space = total_space / (end_idx - start_idx);
  int bonus_space = total_space % (end_idx - start_idx);
  char *line = (char *)malloc(sizeof(char) * (max_width + 1));
  int idx = 0;
  for (int i = start_idx; i <= end_idx; i++) {
    if (i > start_idx) {
      for (int j = 0; j < space; j++)
        line[idx++] = ' ';
      if (bonus_space--)
        line[idx++] = ' ';
    }
    for (int j = 0; j < len[i]; j++)
      line[idx++] = words[i][j];
  }
  line[idx] = 0;
  return line;
}

char *left_justify(char **words, int words_size, int *len, int start_idx,
                   int end_idx, int max_width) {
  char *line = (char *)malloc(sizeof(char) * (max_width + 1));
  int idx = 0;
  for (int i = start_idx; i <= end_idx; i++) {
    if (i > start_idx)
      line[idx++] = ' ';
    for (int j = 0; j < len[i]; j++)
      line[idx++] = words[i][j];
  }
  for (int i = idx; i < max_width; i++)
    line[idx++] = ' ';
  line[idx] = 0;
  return line;
}

char **fullJustify(char **words, int words_size, int max_width,
                   int *return_size) {
  if (!words_size) {
    char **ans = (char **)malloc(sizeof(char *));
    ans[0] = (char *)malloc(sizeof(char) * max_width + 1); // hmm, pemdas?
    int idx = 0;
    for (int i = 0; i < max_width; i++)
      ans[0][idx++] = ' ';
    ans[0][idx] = 0;
    *return_size = 1;
    return ans;
  }
  int *len = (int *)calloc(words_size, sizeof(int));
  for (int i = 0; i < words_size; i++)
    len[i] = get_len(words[i]);
  int *start_idx = (int *)malloc(sizeof(int) * words_size);
  int start_len = 0, width = 0, new_width;
  start_idx[start_len++] = 0;
  for (int i = 0; i < words_size; i++) {
    new_width = width + len[i];
    if (width)
      new_width++;
    if (new_width > max_width) {
      start_idx[start_len++] = i;
      width = len[i];
    } else
      width = new_width;
  }
  char **ans = (char **)malloc(sizeof(char *) * start_len);
  int idx = 0;
  for (int i = 0; i < start_len - 1; i++) {
    if (start_idx[i + 1] - start_idx[i] >= 2)
      ans[idx++] = centre_justify(words, words_size, len, start_idx[i],
                                  start_idx[i + 1] - 1, max_width);
    else
      ans[idx++] =
          left_justify(words, words_size, len, start_idx[start_len - 1],
                       words_size - 1, max_width);
  }
  ans[idx] = left_justify(words, words_size, len, start_idx[start_len - 1],
                          words_size - 1, max_width);
  free(start_idx);
  *return_size = start_len;
  return ans;
}

int main() {
  char w1[7][14] = {"This",          "is", "an", "example", "of", "text",
                    "justification."};
  char w2[6][14] = {"What", "must", "be", "acknowledgment", "shall", "be"};
  int rs1[] = {}, rs2[] = {};
  char **fj1 = fullJustify(w1, 7, 16, rs1);
  char **fj2 = fullJustify(w2, 6, 16, rs2);
  for (int i = 0; i < 7; i++)
    printf("%s ", fj1[i]);
  printf("\n");
  for (int i = 0; i < 6; i++)
    printf("%s ", fj2[i]);
  printf("\n");
}
