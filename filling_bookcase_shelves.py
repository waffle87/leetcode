# 1105. Filling Bookcase Shelves

"""
you are given an array 'books' where 'books[i] = [thinkness, height]'
indicates the thickness and height of the i'th book. you are also given an
integer 'shelfWidth'. we want to place these books in order onto bookcase
shelves that have a total width 'shelfWidth'. we chose some of the books to
place on this shelf such that the sum of their thickness is less than or
equal to 'shelfWidth' then build another level of the shelf of the bookcase
so that the total height of the bookcase has increased by the maximum height
of the books we just put down. we repeat this process until there are no more
books to place.
"""


class Solution(object):
    def minHeightShelves(self, books, shelfWidth):
        """
        :type books: List[List[int]]
        :type shelfWidth: int
        :rtype: int
        """
        n = len(books)
        dp = [float("inf") for _ in range(n + 1)]
        dp[0] = 0
        for i in range(1, n + 1):
            width, height, j = shelfWidth, 0, i - 1
            while j >= 0 and width - books[j][0] >= 0:
                width -= books[j][0]
                height = max(height, books[j][1])
                dp[i] = min(dp[i], dp[j] + height)
                j -= 1
        return dp[n]


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.minHeightShelves(
            books=[[1, 1], [2, 3], [2, 3], [1, 1], [1, 1], [1, 1], [1, 2]], shelfWidth=4
        )
    )
    print(obj.minHeightShelves(books=[[1, 3], [2, 4], [3, 2]], shelfWidth=6))
