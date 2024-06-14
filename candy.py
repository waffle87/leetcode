# 135. Candy

"""
there are 'n' children standing in a line. each child is assigned a rating
value. given in the integer array 'ratings'. you are giving candies to these
children subjected to the following requirements
- each child must have at least one candy
- children with a higher rating get more candies than their neighbours
return the maximum number of candies you need to have to distribute the
candies to the children
"""


class Solution(object):
    def candy(self, ratings):
        n = len(ratings)
        candies = [1] * n
        for i in range(1, n):
            if ratings[i] > ratings[i - 1]:
                candies[i] = candies[i - 1] + 1
        for i in range(n - 2, -1, -1):
            if ratings[i] > ratings[i + 1]:
                candies[i] = max(candies[i], candies[i + 1] + 1)
        return sum(candies)


if __name__ == "__main__":
    obj = Solution()
    print(obj.candy([1, 0, 2]))  # expect: 5
    print(obj.candy([1, 2, 2]))  # expect: 4
