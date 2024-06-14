# 3075. Maximize Happiness of Selected Children

"""
given an array 'happiness' of length 'n' and a positive integer 'k'. there
are 'n' children standing in a queue where the i'th child has happiness value
'happiness[i]'. you want to select 'k' children from these 'n' children in
'k' turns. in each turn you select a child the happiness value of all the
children that have not been selected till now decreases by one. note that the
happiness value cannot become negative and decremented only if it is
positive. return the maximum sum of the happiness values of the selected
children you can achieve by selecting 'k' children.
"""


class Solution(object):
    def maximumHappinessSum(self, happiness, k):
        """
        :type happiness: List[int]
        :type k: int
        :rtype: int
        """
        happiness.sort(reverse=True)
        i, ans = 0, 0
        while k:
            happiness[i] = max(happiness[i] - i, 0)
            ans += happiness[i]
            i += 1
            k -= 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.maximumHappinessSum(happiness=[1, 2, 3], k=2))
    print(obj.maximumHappinessSum(happiness=[1, 1, 1, 1], k=2))
    print(obj.maximumHappinessSum(happiness=[2, 3, 4, 5], k=1))
