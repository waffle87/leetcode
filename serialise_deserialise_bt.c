// 297. Serialize and Deserialize Binary Tree
#include "leetcode.h"

/*
 * serialisation is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted acorss a network connection link to be reconstructed later in the
 * same or another computer environment. design an algorithm to serialise and
 * deserialise a binary tree. there is no restriction on how your serialisation
 * and deserialisation algorithm shouldd work. you just need to ensure that a
 * binary tree can be serialised to a string and this string can be deserialised
 * to the original tree structure.
 */

struct list {
  char **data;
  int pos;
  int size;
};

int comma_cnt(char *s) {
  int cnt = 0;
  while (*s != '\0') {
    cnt += *s == ',';
    ++s;
  };
  return cnt;
}

struct list *split(char *s, int size) {
  struct list *l = (struct list *)malloc(sizeof(struct list));
  char **res = (char **)malloc(size * sizeof(char *)), *q = s;
  for (int i = 0; i < size; ++i) {
    while (*q != ',' && *q != '\0')
      ++q;
    if (*q == ',') {
      *q = '\0';
      ++q;
    }
    res[i] = s;
    s = q;
  }
  l->data = res;
  l->pos = 0;
  l->size = size;
  return l;
}

char *pop(struct list *l) {
  if (l->pos >= l->size)
    return NULL;
  return l->data[l->pos++];
}

char *cleanup(char *s) {
  int i = 0, j = 0;
  if (s[j] == '[')
    ++j;
  while (s[j] != ']' && s[j] != '\0') {
    if (!isspace(s[j]))
      s[i++] = s[j];
    ++j;
  }
  s[i] = '\0';
  return s;
}

/** Encodes a tree to a single string. */
char *serialize(struct TreeNode *root) {
  if (!root)
    return NULL;
  struct TreeNode *queue[21001];
  int head = 0, tail = 0;
  bool has_nodes;
  struct TreeNode *n;
  char *s = (char *)malloc(10 * sizeof(char)), num_str[10];
  int sl = 1, max_sl = 10;
  s[0] = '[';
  queue[tail++] = root;
  while (head != tail) {
    n = queue[head++];
    if (n) {
      sprintf(num_str, "%d", n->val);
      if (sl + strlen(num_str) + 4 >= max_sl) {
        max_sl *= 2;
        s = (char *)realloc(s, max_sl);
      }
      strcpy(s + sl, num_str);
      sl += strlen(num_str);
      s[sl++] = ',';
      queue[tail++] = n->left;
      queue[tail++] = n->right;
    } else {
      if (sl + 7 > max_sl) {
        max_sl *= 2;
        s = (char *)realloc(s, max_sl);
      }
      strcpy(s + sl, "null,");
      sl += 5;
    }
    has_nodes = false;
    for (int i = head; i < tail; i++)
      if (queue[i]) {
        has_nodes = true;
        break;
      }
    if (!has_nodes)
      head = tail;
  }
  s[sl - 1] = ']';
  s[sl] = '\0';
  return s;
}

/** Decodes your encoded data to tree. */
struct TreeNode *deserialize(char *data) {
  if (!data)
    return NULL;
  data = cleanup(data);
  int num_nodes = comma_cnt(data) + 1, head = 0, tail = 0;
  struct list *l = split(data, num_nodes);
  struct TreeNode *queue[num_nodes], *root, *n, *m;
  char *entry = pop(l);
  if (!entry)
    return NULL;
  root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  root->val = atoi(entry);
  root->left = NULL;
  root->right = NULL;
  queue[tail++] = root;
  while (head != tail) {
    n = queue[head++];
    entry = pop(l);
    if (entry && strcmp(entry, "null")) {
      m = (struct TreeNode *)malloc(sizeof(struct TreeNode));
      m->val = atoi(entry);
      m->left = NULL;
      m->right = NULL;
      n->left = m;
      queue[tail++] = m;
    }
    entry = pop(l);
    if (entry && strcmp(entry, "null")) {
      m = (struct TreeNode *)malloc(sizeof(struct TreeNode));
      m->val = atoi(entry);
      m->left = NULL;
      m->right = NULL;
      n->right = m;
      queue[tail++] = m;
    }
  }
  return root;
}

// Your functions will be called as such:
// char* data = serialize(root);
// deserialize(data);

int main() {
  struct TreeNode *root = treenode_create(1);
  root->left = treenode_create(2);
  root->right = treenode_create(3);
  root->right->left = treenode_create(4);
  root->right->right = treenode_create(5);
  char *data = serialize(root);
  struct TreeNode *ds = deserialize(data);
  treenode_print(ds); // expect: 1 2 3 nll null 4 5
  treenode_free(root);
  treenode_free(ds);
  free(data);
}
