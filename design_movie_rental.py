# 1912. Design Movie Rental System
from collections import defaultdict

from sortedcontainers import SortedList


class MovieRentingSystem(object):
    def __init__(self, n, entries):
        """
        :type n: int
        :type entries: List[List[int]]
        """
        self.shops = defaultdict(SortedList)
        self.shop_movie = {}
        self.rented = SortedList()
        for s, m, p in entries:
            self.shops[m].add((p, s))
            self.shop_movie[s, m] = p

    def search(self, movie):
        """
        :type movie: int
        :rtype: List[int]
        """
        return [i for _, i in self.shops[movie][:5]]

    def rent(self, shop, movie):
        """
        :type shop: int
        :type movie: int
        :rtype: None
        """
        price = self.shop_movie[shop, movie]
        self.shops[movie].remove((price, shop))
        self.rented.add((price, shop, movie))

    def drop(self, shop, movie):
        """
        :type shop: int
        :type movie: int
        :rtype: None
        """
        price = self.shop_movie[shop, movie]
        self.shops[movie].add((price, shop))
        self.rented.remove((price, shop, movie))

    def report(self):
        """
        :rtype: List[List[int]]
        """
        return [[i, j] for _, i, j in self.rented[:5]]


if __name__ == "__main__":
    obj = MovieRentingSystem(
        3, [[0, 1, 5], [0, 2, 6], [0, 3, 7], [1, 1, 4], [1, 2, 7], [2, 1, 5]]
    )
    print(obj.search(1))
    obj.rent(0, 1)
    obj.rent(1, 2)
    print(obj.report())
    obj.drop(1, 2)
    print(obj.search(2))
