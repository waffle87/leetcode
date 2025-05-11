# 1550. Three Consecutive Odds

"""
given an integer array 'arr', return true if there are three consecutive odd
numbers in the array. otherwise, return false
"""


class Solution(object):
    def threeConsecutiveOdds(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        cnt = 0
        for i in arr:
            if i % 2 != 0:
                cnt += 1
                if cnt == 3:
                    return True
            else:
                cnt = 0
        return False


if __name__ == "__main__":
    obj = Solution()
    print(obj.threeConsecutiveOdds(arr=[2, 6, 4, 1]))
    print(obj.threeConsecutiveOdds(arr=[1, 2, 34, 3, 4, 5, 7, 23, 12]))
