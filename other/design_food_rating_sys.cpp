// 2353. Design a Food Rating System
#include "leetcode.h"

/*
 * design a food rating system that can do the following:
 * - modify the rating of a food item listed in the system
 * - return the highest rated food item for a type of cuisine in the system
 * implement the 'FoodRatings' class. note that a string 'x' is
 * lexicographically smaller than string 'y' if 'x' comes before 'y' in
 * dictionary order, that is, either 'x' is a prefix of 'y' or if 'i' is the
 * first position such that 'x[i] != y[i], then x[i] comes beofre y[i] in
 * alpabetic order
 */

class FoodRatings {
private:
  unordered_map<string_view, string_view> f2c;
  unordered_map<string_view, int> f2r;
  unordered_map<string_view, set<pair<int, string>>> c2r;

public:
  FoodRatings(vector<string> &foods, vector<string> &cuisines,
              vector<int> &ratings) {
    for (int i = 0; i < foods.size(); i++) {
      f2c[foods[i]] = cuisines[i];
      f2r[foods[i]] = ratings[i];
      c2r[cuisines[i]].emplace(-ratings[i], foods[i]);
    }
  }

  void changeRating(string food, int newRating) {
    int r = exchange(f2r[food], newRating);
    auto &c = f2c[food];
    auto it = c2r.find(c);
    it->second.erase({-r, food});
    it->second.emplace(-newRating, food);
  }

  string highestRated(string cuisine) { return begin(c2r[cuisine])->second; }
};
