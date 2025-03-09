# 3208. alternating groups ii

"""
there is a circle of red and blue tiles. you are given an array of integers
'colours' and an integer 'k'. the colour of tile 'i' is represented by
'colours[i]': '0' means that tile 'i' is red, and '1' means that tile 'i' is
blue. an alternating group is every 'k' contiguous tiles in the circle with
alternating colours. return the number of alternating groups. note that since
'colours' represents a circle, the first and last tiles are considered to be
next to eachother.
"""


class Solution(object):
    def numberOfAlternatingGroups(self, colours, k):
        """
        :type colours: List[int]
        :type k: int
        :rtype: int
        """
        n, cnt, left = len(colours), 0, 0
        for right in range(n + k - 1):
            if right > 0 and colours[right % n] == colours[(right - 1) % n]:
                left = right
            if right - left + 1 >= k:
                cnt += 1
        return cnt


if __name__ == "__main__":
    obj = Solution()
    print(obj.numberOfAlternatingGroups(colours=[0, 1, 0, 1, 0], k=3))
    print(obj.numberOfAlternatingGroups(colours=[0, 1, 0, 0, 1, 0, 1], k=6))
    print(obj.numberOfAlternatingGroups(colours=[1, 1, 0, 1], k=4))
