// 2115. Find All Possible Recipes from Given Supplies
#include "leetcode.h"

/*
 * you have information about 'n' different recipes. you are given a string
 * array 'recipes' and a 2d string array 'ingredients'. the i'th recipe has the
 * name 'recipes[i]', and you can create it is you have all the needed
 * ingredients from 'ingredients[i]'. ingredients to a recipe may need to be
 * created from other recipes, ie. 'ingredients[i]' may contain a string that is
 * in 'recipes'. you are also given a string array 'supplies' containing all the
 * ingredients that you initially have, and you have an infinite supply of all
 * of them. return a list of all the recipes that you can create. you may return
 * the answer in any order.
 */

struct item {
  struct item *next[26];
  bool end;
};

struct item trie;

void trie_init(void) { memset((void *)&trie, 0, sizeof(trie)); }

void trie_push(char *s) {
  struct item *header = &trie;
  for (int i = 0; s[i]; i++) {
    if (!header->next[s[i] - 'a'])
      header->next[s[i] - 'a'] = (struct item *)calloc(1, sizeof(struct item));
    header = header->next[s[i] - 'a'];
  }
  header->end = true;
}

bool trie_find(char *s) {
  struct item *header = &trie;
  for (int i = 0; s[i]; i++) {
    if (!header->next[s[i] - 'a'])
      return false;
    header = header->next[s[i] - 'a'];
  }
  return header->end;
}

void trie_free_single(struct item *trie) {
  if (trie) {
    for (int i = 0; i < 26; i++)
      trie_free_single(trie->next[i]);
    free(trie);
  }
}

void trie_free(void) {
  for (int i = 0; i < 26; i++)
    trie_free_single(trie.next[i]);
}

char **findAllRecipes(char **recipes, int recipesSize, char ***ingredients,
                      int ingredientsSize, int *ingredientsColSize,
                      char **supplies, int suppliesSize, int *returnSize) {
  char **ans = (char **)malloc(recipesSize * sizeof(char *));
  trie_init();
  for (int i = 0; i < suppliesSize; i++)
    trie_push(supplies[i]);
  *returnSize = 0;
  bool progress = true;
  while (progress) {
    progress = false;
    for (int i = 0; i < recipesSize; i++) {
      if (trie_find(recipes[i]))
        continue;
      bool create = true;
      for (int j = 0; j < ingredientsColSize[i]; j++)
        if (!trie_find(ingredients[i][j])) {
          create = false;
          break;
        }
      if (create) {
        progress = true;
        trie_push(recipes[i]);
        ans[*returnSize] =
            (char *)malloc((strlen(recipes[i]) + 1) * sizeof(char));
        strcpy(ans[*returnSize], recipes[i]);
        (*returnSize)++;
      }
    }
  }
  trie_free();
  return ans;
}

int main() {
  char *r1[] = {"bread"};
  char *i11[] = {"yeast", "flour"};
  char **i1 = {i11};
  char *s1[] = {"yeast", "flour", "corn"};
  char *r2[] = {"bread", "sandwich"};
  char *i21[] = {"yeast", "flour"}, *i22[] = {"bread", "meat"};
  char **i2[] = {i21, i22};
  char *s2[] = {"yeast", "flour", "meat"};
  char *r3[] = {"bread", "sandwich", "burger"};
  char *i31[] = {"yeast", "flour"}, *i32[] = {"bread", "meat"},
       *i33[] = {"sandwich", "meat", "bread"};
  char **i3[] = {i31, i32, i33};
  char *s3[] = {"yeast", "flour", "meat"};
  int rs1, rs2, rs3;
  char **far1 =
      findAllRecipes(r1, ARRAY_SIZE(r1), (char ***)i1, ARRAY_SIZE(i11),
                     (int *)ARRAY_SIZE(i11), s1, ARRAY_SIZE(s1), &rs1);
  char **far2 =
      findAllRecipes(r2, ARRAY_SIZE(r2), (char ***)i2, ARRAY_SIZE(i21),
                     (int *)ARRAY_SIZE(i21), s2, ARRAY_SIZE(s2), &rs2);
  char **far3 =
      findAllRecipes(r3, ARRAY_SIZE(r3), (char ***)i3, ARRAY_SIZE(i31),
                     (int *)ARRAY_SIZE(i31), s3, ARRAY_SIZE(s3), &rs3);
  for (int i = 0; i < rs1; i++)
    printf("%s ", far1[i]); // expect: ["bread"]
  printf("\n");
  for (int i = 0; i < rs2; i++)
    printf("%s ", far2[i]); // expect: ["bread","sandwich"]
  printf("\n");
  for (int i = 0; i < rs3; i++)
    printf("%s ", far3[i]); // expect: ["bread","sandwich","burger"]
  printf("\n");
  free(far1);
  free(far2);
  free(far3);
}
