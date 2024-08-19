// 721. Accounts Merge
#include "leetcode.h"

/*
 * given a list of 'accounts' where each element 'accounts[i]' is a list of
 * strings, where the first element 'accounts[i][0]' is a name and the rest of
 * the elements are emails representing emails of the account. now we would like
 * to merge these accounts. two accounts definitely bbelong to the same person
 * if there is some common email to bboth accounts. note that even if two
 * accounts have the same name, they may belong to different people as people
 * could have the same name. a person can have any numbber of accounts initially
 * but all of their accounts definitely have the same name. after merging the
 * accounts, return the accounts in the following format: the first element of
 * each accout is the name, and the rest of the elements are emails in sorted
 * order. the accounts themselves can e returned in any order.
 */

int cmp(const void *a, const void *b) {
  char *a1 = *(char **)a, *b1 = *(char **)b;
  return strcmp(a1, b1);
}

int find(int *parent, int i) {
  if (parent[i] == i)
    return i;
  else
    return parent[i] = find(parent, parent[i]);
}

void _union(int *parent, int *rank, int i, int j) {
  i = find(parent, i);
  j = find(parent, j);
  if (i == j)
    return;
  if (rank[i] > rank[j])
    parent[j] = i;
  else {
    parent[i] = j;
    if (rank[i] == rank[j])
      rank[j]++;
  }
}

int get_idx(const char *email, const char **emails, int emails_size) {
  const char **val = bsearch(&email, emails, emails_size, sizeof(char *), cmp);
  return (int)(val - emails);
}

struct res_data {
  char ***r;
  int *cols;
  int size;
  int cap;
  char **curr;
  int curr_size;
  int curr_cap;
};

void add(struct res_data *r, char *val) {
  if (r->curr_cap <= r->curr_size) {
    r->curr_cap = (r->curr_cap + 1) * 2;
    r->curr = (char **)realloc(r->curr, r->curr_cap * sizeof(char *));
  }
  r->curr[r->curr_size++] = val;
}

void flush(struct res_data *r) {
  if (r->cap <= r->size) {
    r->cap = (r->cap + 1) * 2;
    r->r = (char ***)realloc(r->r, r->cap * sizeof(char **));
    r->cols = (int *)realloc(r->cols, r->cap * sizeof(int));
  }
  r->cols[r->size] = r->curr_size;
  r->r[r->size++] = r->curr;
  r->curr = NULL;
  r->curr_cap = r->curr_size = 0;
}

struct pair {
  int idx;
  int grp;
};

int cmp2(const void *a, const void *b) {
  const struct pair *p1 = a, *p2 = b;
  if (p1->grp == p2->grp)
    return p1->idx - p2->idx;
  return p1->grp - p2->grp;
}

char ***accountsMerge(char ***accounts, int accountsSize, int *accountsColSize,
                      int *returnSize, int **returnColumnSizes) {
  int emails_size, union_find_size, i, j, k, *parent, *rank;
  char **emails;
  struct pair *p;
  struct res_data *r;
  memset(&r, 0, sizeof(r));
  for (emails_size = 0, i = 0; i < accountsSize; i++)
    for (j = 1; j < accountsColSize[i]; j++)
      emails_size++;
  emails = (char **)malloc(emails_size * sizeof(char *));
  for (k = 0, i = 0; i < accountsSize; i++)
    for (j = 1; j < accountsColSize[i]; j++)
      emails[k++] = accounts[i][j];
  qsort(emails, emails_size, sizeof(char *), cmp);
  for (i = 0; i < emails_size; ++i)
    if (!j || strcmp(emails[j - 1], emails[i]))
      emails[j++] = emails[i];
  emails_size = j;
  union_find_size = accountsSize + emails_size;
  parent = (int *)malloc(union_find_size * sizeof(int));
  rank = (int *)malloc(union_find_size * sizeof(int));
  p = (struct pair *)malloc(union_find_size * sizeof(struct pair));
  for (i = 0; i < union_find_size; i++) {
    parent[i] = i;
    rank[i] = 0;
  }
  for (i = 0; i < accountsSize; i++)
    for (j = 1; j < accountsColSize[i]; j++) {
      // int idx = accountsSize + get_idx(accounts[i][j], (int**)emails,
      // emails_size);
      int idx = accountsSize +
                get_idx(accounts[i][j], (const char **)emails, emails_size);
      _union(parent, rank, i, idx);
    }
  for (i = 0; i < union_find_size; i++) {
    struct pair curr = {i, find(parent, i)};
    p[i] = curr;
  }
  qsort(p, union_find_size, sizeof(struct pair), cmp2);
  add(r, accounts[p[0].idx][0]);
  for (i = 1; i < union_find_size; i++)
    if (p[i].grp != p[i - 1].grp) {
      flush(r);
      add(r, accounts[p[i].idx][0]);
    } else {
      int idx = p[i].idx - accountsSize;
      if (idx >= 0)
        add(r, emails[idx]);
    }
  flush(r);
  *returnSize = r->size;
  *returnColumnSizes = r->cols;
  free(p), free(parent), free(rank), free(emails);
  return r->r;
}

int main() {
  int accountsSize = 4, accountsColSize[] = {3, 3, 2, 2}, returnSize,
      *returnColumnSizes;
  char ***accounts = malloc(accountsSize * sizeof(char **));
  accounts[0] = malloc(accountsColSize[0] * sizeof(char *));
  accounts[0][0] = "John";
  accounts[0][1] = "johnsmith@mail.com";
  accounts[0][2] = "john_newyork@mail.com";
  accounts[1] = malloc(accountsColSize[1] * sizeof(char *));
  accounts[1][0] = "John";
  accounts[1][1] = "johnsmith@mail.com";
  accounts[1][2] = "john00@mail.com";
  accounts[2] = malloc(accountsColSize[2] * sizeof(char *));
  accounts[2][0] = "Mary";
  accounts[2][1] = "mary@mail.com";
  accounts[3] = malloc(accountsColSize[3] * sizeof(char *));
  accounts[3][0] = "John";
  accounts[3][1] = "johnnybravo@mail.com";
  char ***am1 = accountsMerge(accounts, accountsSize, accountsColSize,
                              &returnSize, &returnColumnSizes);
  for (int i = 0; i < returnSize; i++)
    for (int j = 0; j < returnColumnSizes[i]; j++) {
      printf("\"%s\"", am1[i][j]);
      if (j < returnColumnSizes[i] - 1)
        printf(", ");
    }
  for (int i = 0; i < returnSize; i++)
    free(am1[i]);
  free(am1);
  free(returnColumnSizes);
  for (int i = 0; i < accountsSize; i++)
    free(accounts[i]);
  free(accounts);
}
