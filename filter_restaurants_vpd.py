# 1333. Filter Restaurants by Vegan-Friendly, Price and Distance

"""
given the array 'restaurants' where 'restaurants[i] = [id_i, rating_i,
veganFriendly_i, price_i, distance_i]'. you have to filter the restaurants
using three filters. the 'veganFriendly' filter will either be true or false.
in addition, you have the filters 'maxPrice' and 'maxDistance' which are the
maximum value for price and distance of restaurants you should consider
respectively. return the array of restaurant id's after filtering, ordered by
rating from highest to lowest. for restaurants with the same rating, order
them by id from highest to lowest.
"""


class Solution(object):
    def filterRestaurants(self, restaurants, veganFriendly, maxPrice, maxDistance):
        """
        :type restaurants: List[List[int]]
        :type veganFriendly: int
        :type maxPrice: int
        :type maxDistance: int
        :rtype: List[int]
        """
        restaurants.sort(key=lambda x: (-x[1], -x[0]))
        return [
            i
            for i, _, v, p, d in restaurants
            if v >= veganFriendly and p <= maxPrice and d <= maxDistance
        ]


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.filterRestaurants(
            restaurants=[
                [1, 4, 1, 40, 10],
                [2, 8, 0, 50, 5],
                [3, 8, 1, 30, 4],
                [4, 10, 0, 10, 3],
                [5, 1, 1, 15, 1],
            ],
            veganFriendly=1,
            maxPrice=50,
            maxDistance=10,
        )
    )
    print(
        obj.filterRestaurants(
            restaurants=[
                [1, 4, 1, 40, 10],
                [2, 8, 0, 50, 5],
                [3, 8, 1, 30, 4],
                [4, 10, 0, 10, 3],
                [5, 1, 1, 15, 1],
            ],
            veganFriendly=0,
            maxPrice=50,
            maxDistance=10,
        )
    )
    print(
        obj.filterRestaurants(
            restaurants=[
                [1, 4, 1, 40, 10],
                [2, 8, 0, 50, 5],
                [3, 8, 1, 30, 4],
                [4, 10, 0, 10, 3],
                [5, 1, 1, 15, 1],
            ],
            veganFriendly=0,
            maxPrice=30,
            maxDistance=3,
        )
    )
