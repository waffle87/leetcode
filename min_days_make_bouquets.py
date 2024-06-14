# 1482. Minimum Number of Days to Make m Bouquets

"""
given an integer array 'bloomDay', an integer 'm', and an integer 'k'. you
want to make 'm' bouquets. to make a bouquet, you need to use 'k' adjacent
flowers from the garden. the garden consists of 'n' flowers, the i'th flower
will bloom in the 'bloomDay[i]' and then can be used in exactly one bouquet.
return the minimum number of days you need to wait to be able to make 'm'
bouquets from the garden. if it is impossible to make 'm' bouquets, return -1
"""


class Solution(object):
    def minDays(self, bloomDay, m, k):
        """
        :type bloomDay: List[int]
        :type m: int
        :type k: int
        :rtype: int
        """
        if m * k > len(bloomDay):
            return -1
        left, right = 1, max(bloomDay)
        while left < right:
            mid = (left + right) / 2
            flow, bouq = 0, 0
            for i in bloomDay:
                flow = 0 if i > mid else flow + 1
                if flow >= k:
                    flow = 0
                    bouq += 1
                    if bouq == m:
                        break
            if bouq == m:
                right = mid
            else:
                left = mid + 1
        return left


if __name__ == "__main__":
    obj = Solution()
    print(obj.minDays(bloomDay=[1, 10, 3, 10, 2], m=3, k=1))
    print(obj.minDays(bloomDay=[1, 10, 3, 10, 2], m=3, k=2))
    print(obj.minDays(bloomDay=[7, 7, 7, 7, 12, 7, 7], m=2, k=3))
