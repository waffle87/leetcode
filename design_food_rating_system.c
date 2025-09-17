// 2353. Design a Food Rating System
#include "leetcode.h"

/*
 * design a food rating system that can do the following: modify the rating of a
 * food item listed in the system, return the highest rated food item for a type
 * of cuisine in the system. note that a string 'x' is lexicographically smaller
 * than string 'y' if 'x' comes before 'y' in the dictionary order, that is,
 * either 'x' is a prefix of 'y', or if 'i' is the first position such that
 * 'x[i] != y[i]', then 'x[i]' comes before 'y[i]' in alphabetic order.
 */

struct cuisine_hash;

struct food_hash {
  char *food;
  struct cuisine_hash *cuisine;
  int rating;
  int idx;
  UT_hash_handle hh;
};

struct cuisine_hash {
  char *cuisine;
  struct food_hash **foods;
  int foods_size;
  UT_hash_handle hh;
};

typedef struct {
  struct food_hash *foods;
  struct cuisine_hash *cuisines;
  struct food_hash *food_entries;
} FoodRatings;

static char *str_clone(const char *s) {
  int n = strlen(s);
  char *const res = (char *const)malloc((n + 1) * sizeof(char));
  memcpy(res, s, n + 1);
  return res;
}

static bool is_food_greater(struct food_hash *lhs, struct food_hash *rhs) {
  return lhs->rating > rhs->rating ||
         (lhs->rating == rhs->rating && 0 > strcmp(lhs->food, rhs->food));
}

FoodRatings *foodRatingsCreate(char **foods, int foodsSize, char **cuisines,
                               int cuisinesSize, int *ratings,
                               int ratingsSize) {
  FoodRatings *res = (FoodRatings *)malloc(sizeof(FoodRatings));
  memset(res, 0, sizeof(FoodRatings));
  res->food_entries =
      (struct food_hash *)malloc(foodsSize * sizeof(struct food_hash));
  struct cuisine_hash *entry;
  for (int i = 0; i < foodsSize; i++) {
    HASH_FIND_STR(res->cuisines, cuisines[i], entry);
    if (!entry) {
      entry = (struct cuisine_hash *)malloc(sizeof(struct cuisine_hash));
      entry->cuisine = str_clone(cuisines[i]);
      entry->foods = NULL;
      entry->foods_size = 0;
      HASH_ADD_KEYPTR(hh, res->cuisines, entry->cuisine, strlen(entry->cuisine),
                      entry);
    }
    ++entry->foods_size;
    struct food_hash *food_entry = &res->food_entries[i];
    food_entry->food = str_clone(foods[i]);
    food_entry->cuisine = entry;
    food_entry->rating = ratings[i];
  }
  struct cuisine_hash *tmp;
  HASH_ITER(hh, res->cuisines, entry, tmp) {
    entry->foods = (struct food_hash **)malloc(entry->foods_size *
                                               sizeof(struct food_hash *));
    entry->foods_size = 0;
  }
  for (int i = 0; i < foodsSize; ++i) {
    struct food_hash *food_entry = &res->food_entries[i];
    entry = food_entry->cuisine;
    int idx = entry->foods_size++;
    while (idx && is_food_greater(food_entry, entry->foods[(idx - 1) / 2])) {
      entry->foods[idx] = entry->foods[(idx - 1) / 2];
      entry->foods[idx]->idx = idx;
      idx = (idx - 1) / 2;
    }
    entry->foods[idx] = food_entry;
    entry->foods[idx]->idx = idx;
    HASH_ADD_KEYPTR(hh, res->foods, food_entry->food, strlen(food_entry->food),
                    food_entry);
  }
  return res;
}

void foodRatingsChangeRating(FoodRatings *obj, char *food, int newRating) {
  struct food_hash *food_entry;
  HASH_FIND_STR(obj->foods, food, food_entry);
  struct cuisine_hash *const cuisine = food_entry->cuisine;
  int idx = food_entry->idx;
  const int prev = food_entry->rating;
  if (newRating > prev) {
    while (idx && is_food_greater(food_entry, cuisine->foods[(idx - 1) / 2])) {
      cuisine->foods[idx] = cuisine->foods[(idx - 1) / 2];
      cuisine->foods[idx]->idx = idx;
      idx = (idx - 1) / 2;
    }
    cuisine->foods[idx] = food_entry;
    cuisine->foods[idx]->idx = idx;
  } else if (newRating < prev) {
    for (;;) {
      int to_move = idx, left = idx * 2 + 1, right = idx * 2 + 2;
      if (left < cuisine->foods_size &&
          is_food_greater(cuisine->foods[left], cuisine->foods[to_move]))
        to_move = left;
      if (right < cuisine->foods_size &&
          is_food_greater(cuisine->foods[right], cuisine->foods[to_move]))
        to_move = right;
      if (to_move == idx)
        break;
      cuisine->foods[idx] = cuisine->foods[to_move];
      cuisine->foods[idx]->idx = idx;
      cuisine->foods[to_move] = food_entry;
      idx = to_move;
    }
    cuisine->foods[idx]->idx = idx;
  }
}

char *foodRatingsHighestRated(FoodRatings *obj, char *cuisine) {
  struct cuisine_hash *entry;
  HASH_FIND_STR(obj->cuisines, cuisine, entry);
  return entry->foods[0]->food;
}

void foodRatingsFree(FoodRatings *obj) {
  HASH_CLEAR(hh, obj->foods);
  struct cuisine_hash *del, *tmp;
  HASH_ITER(hh, obj->cuisines, del, tmp) {
    for (int i = 0; i < del->foods_size; ++i)
      free(del->foods[i]->food);
    free(del->foods);
    HASH_DEL(obj->cuisines, del);
    free(del->cuisine);
    free(del);
  }
  free(obj->food_entries);
  free(obj);
}

int main() {
  char *foods[] = {"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"};
  char *cuisines[] = {"korean", "japanese", "japanese",
                      "greek",  "japanese", "korean"};
  int ratings[] = {9, 12, 8, 15, 14, 7};
  FoodRatings *obj =
      foodRatingsCreate((char **)foods, ARRAY_SIZE(foods), (char **)cuisines,
                        ARRAY_SIZE(cuisines), ratings, ARRAY_SIZE(ratings));
  printf("%s\n", foodRatingsHighestRated(obj, "korean"));   // expect: kimchi
  printf("%s\n", foodRatingsHighestRated(obj, "japanese")); // expect: ramen
  foodRatingsChangeRating(obj, "sushi", 16);
  printf("%s\n", foodRatingsHighestRated(obj, "japanese")); // expect: sushi
  foodRatingsChangeRating(obj, "ramen", 16);
  printf("%s\n", foodRatingsHighestRated(obj, "japanese")); // expect: ramen
  foodRatingsFree(obj);
}
