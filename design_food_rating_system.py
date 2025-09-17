# 2353. Design a Food Rating System
from collections import defaultdict

from sortedcontainers import SortedSet

"""
design a food rating system that can do the following:
- modify the rating of a food item listed in the system
- return the highest rated food item for a type of cuisine in the system
implement the 'FoodRatings' class. note that a string 'x' is
lexicographically smaller than string 'y' if 'x' comes before 'y' in
dictionary order, that is, either 'x' is a prefix of 'y' or if 'i' is the
first position such that 'x[i] != y[i], then x[i] comes beofre y[i] in
alpabetic order
"""


class FoodRatings(object):
    def __init__(self, foods, cuisines, ratings):
        """
        :type foods: List[str]
        :type cuisines: List[str]
        :type ratings: List[int]
        """
        self.food_rating_map = {}
        self.food_cuisine_map = {}
        self.cuisine_food_map = defaultdict(SortedSet)

        for i in range(len(foods)):
            self.food_rating_map[foods[i]] = ratings[i]
            self.food_cuisine_map[foods[i]] = cuisines[i]
            self.cuisine_food_map[cuisines[i]].add((-ratings[i], foods[i]))

    def changeRating(self, food, newRating):
        """
        :type food: str
        :type newRating: int
        :rtype: None
        """
        cuisine_name = self.food_cuisine_map[food]
        old_element = (-self.food_rating_map[food], food)
        self.cuisine_food_map[cuisine_name].remove(old_element)
        self.food_rating_map[food] = newRating
        self.cuisine_food_map[cuisine_name].add((-newRating, food))

    def highestRated(self, cuisine):
        """
        :type cuisine: str
        :rtype: str
        """
        highest_rated = self.cuisine_food_map[cuisine][0]
        return highest_rated[1]


if __name__ == "__main__":
    obj = FoodRatings(
        foods=["kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"],
        cuisines=["korean", "japanese", "japanese", "greek", "japanese", "korean"],
        ratings=[9, 12, 8, 15, 14, 7],
    )
    print(obj.highestRated("korean"))
    print(obj.highestRated("japanese"))
    obj.changeRating("sushi", 16)
    print(obj.highestRated("japanese"))
    obj.changeRating("ramen", 16)
    print(obj.highestRated("japanese"))
