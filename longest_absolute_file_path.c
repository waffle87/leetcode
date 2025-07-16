// 388. Longest Absolute File Path
#include "leetcode.h"

/*
 * suppose we have a file system that stores both files and directories. every
 * file and directory has a unique absolute path in the file system which is the
 * order of directories that must be opened to reach the file/directory it self,
 * all concatenated by '/'s. each directory name consists of letters, digits,
 * and/or spaces. each filename is of the form 'name.extension', where 'name'
 * and 'extension' consist of letters, digits, and/or spaces. given a string
 * 'input' representing the file system in the explained format, return the
 * length of the longest absolute path to a file in the abstracted file system.
 * if there ino file in the system, return 0
 */

int dir_level(char *d) {
  int i = 0;
  while (d[i] && d[i] == '\t')
    i++;
  return i;
}

int entry_len(char *d, bool *is_file) {
  int i = 0;
  while (d[i] && d[i] != '\n') {
    if (d[i] == '.')
      *is_file = true;
    i++;
  }
  return i;
}

int find_path(char *input, int l, int *max, int clen) {
  int n = 0, tclen, dl, dlen;
  bool is_file;
  while (input[n]) {
    tclen = clen;
    if (input[n] && input[n] == '\n')
      ++n;
    dl = dir_level(&input[n]);
    if (dl != l)
      break;
    n += dl;
    is_file = false;
    dlen = entry_len(&input[n], &is_file);
    tclen += dlen + (dl > 0 ? 1 : 0);
    if (is_file && tclen > *max)
      *max = tclen;
    n += dlen;
    n += find_path(&input[n], l + 1, max, tclen);
  }
  return n;
}

int lengthLongestPath(char *input) {
  int max = 0;
  find_path(&input[0], 0, &max, 0);
  return max;
}

int main() {
  char *i1 = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
  char *i2 = "dir\n\tsubdir1\n\t\tfile1."
             "ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
  char *i3 = "a";
  printf("%d\n", lengthLongestPath(i1)); // expect: 20
  printf("%d\n", lengthLongestPath(i2)); // expect: 32
  printf("%d\n", lengthLongestPath(i3)); // expect: 0
}
