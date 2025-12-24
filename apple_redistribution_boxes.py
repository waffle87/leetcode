# 3074. Apple Redistribution into Boxes

"""
you are given an array 'apple' of size 'n' and an array 'capacity' of size
'm'. there are 'n' packs where the i'th pack contains 'apple[i]' apples.
there are 'm' boxes as well, and the i'th box has a capacity of 'capacity[i]'
apples. return the minimum number of boxes you need to redistribute these 'n'
packs of apples into boxes. note that apples from the same pack can be
distributed into different boxes.
"""


class Solution(object):
    def minimumBoxes(self, apple, capacity):
        """
        :type apple: List[int]
        :type capacity: List[int]
        :rtype: int
        """
        total, ans = sum(apple), 0
        capacity.sort(reverse=True)
        while total > 0:
            total -= capacity[ans]
            ans += 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.minimumBoxes(apple=[1, 3, 2], capacity=[4, 3, 1, 5, 2]))
    print(obj.minimumBoxes(apple=[5, 5, 5], capacity=[2, 4, 2, 7]))
