// 811. Subdomain Visit Count
#include "leetcode.h"

/*
 * a website domain "discuss.leetcode.com" consists of various subdomains. at
 * the level, we have "com" at the next level, we have "leetcode.com", and the
 * lest level, "discuss.leetcode.com". when we visit a domain like the above, we
 * will also visit the parent domains "leetcode.com" and "com" implicitly. a
 * count paired domain is a domain that has one of the two formats
 * "rep.d1.d2.d3" or "rep.d1.d2" where "rep" is the number of visits to the
 * domain and 'd1.d2.d3' is the domain itself. given an array of count paird
 * domains 'cpdomains' return an array of the count pared domains of each
 * subdomain in the input. you may return the answer in any order.
 */

#define STR_LEN 110

typedef struct {
  char domain[STR_LEN];
  int cnt;
  UT_hash_handle hh;
} hash;

void add_domain(hash **webs, char name[STR_LEN], int num) {
  hash *s;
  HASH_FIND_STR(*webs, name, s);
  if (s)
    s->cnt += num;
  else {
    s = (hash *)malloc(sizeof(hash));
    s->cnt = num;
    strcpy(s->domain, name);
    HASH_ADD_STR(*webs, domain, s);
  }
}

char **subdomainVisits(char **cpdomains, int cpdomainsSize, int *returnSize) {
  hash *webs = NULL, *s, *tmp;
  char **ans = (char **)malloc(cpdomainsSize * 3 * sizeof(char)),
       cut[STR_LEN] = "";
  for (int i = 0; i < cpdomainsSize * 3; i++)
    ans[i] = (char *)malloc(STR_LEN * sizeof(char));
  for (int i = 0; i < cpdomainsSize; i++) {
    int n = strlen(cpdomains[i]), j = 0, k = 0;
    while (cpdomains[i][j] != '\0') {
      int num, l;
      if (cpdomains[i][j] == ' ' && !k) {
        k = j;
        memcpy(cut, cpdomains[i], k);
        num = atoi(cut);
        l = j + 1;
        memcpy(cut, cpdomains[i] + l, n - l + 1);
        add_domain(&webs, cut, num);
      }
      if (cpdomains[i][j] == '.') {
        l = j + 1;
        memcpy(cut, cpdomains[i] + l, n - l + 1);
        add_domain(&webs, cut, num);
      }
      j++;
    }
  }
  int i = 0;
  HASH_ITER(hh, webs, s, tmp) {
    sprintf(cut, "%d %s", s->cnt, s->domain);
    strcpy(ans[i], cut);
    i++;
  }
  *returnSize = i;
  return ans;
}

int main() {
  char *cpd1[] = {"9001 discuss.leetcode.com"},
       *cpd2[] = {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com",
                  "5 wiki.org"};
  int rs1, rs2;
  char **sv1 = subdomainVisits((char **)cpd1, ARRAY_SIZE(cpd1), &rs1);
  char **sv2 = subdomainVisits((char **)cpd2, ARRAY_SIZE(cpd2), &rs2);
  for (int i = 0; i < rs1; i++)
    printf("%s ", sv1[i]); // expect: ["9001 leetcode.com","9001
                           // discuss.leetcode.com","9001 com"]
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%s ", sv2[i]); // expect: ["901 mail.com","50 yahoo.com","900
                           // google.mail.com","5 wiki.org","5 org","1
                           // intel.mail.com","951 com"]
  printf("\n");
}
