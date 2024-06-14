# 279. Perfect Squares

"""
given an integer 'n', return the least number of perfect square numbers that
sum to 'n'. a perfect square is an integer that is the square of an integer;
in other words, it is the product of some integer with itself. for example,
1,4,9,16 are perfect squares while 3 and 11 are not.
"""


class Solution(object):
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n < 2:
            return n
        lst = []
        i = 1
        while i * i <= n:
            lst.append(i * i)
            i += 1
        cnt = 0
        to_check = {n}
        while to_check:
            cnt += 1
            tmp = set()
            for x in to_check:
                for y in lst:
                    if x == y:
                        return cnt
                    if x < y:
                        break
                    tmp.add(x - y)
            to_check = tmp
        return cnt


if __name__ == "__main__":
    obj = Solution()
    print(obj.numSquares(12))
    print(obj.numSquares(13))
