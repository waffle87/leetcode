# 1051. Height Checker

"""
a school is trying to take an annual photo of all the students. the students
are asked to stand in a single file line in non decreasing order by height.
let this ordering be represented by the integer array 'expected' where
'expected[i]' is the expected height of the i'th student in line. you are
given an integer array 'heights' representing the current order that the
students are standing in. each 'heights[i]' is the height of the i'th student
in line. return the number of indices where 'heights[i] != expected[i]'
"""


class Solution(object):
    def heightChecker(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        max_nr = max(heights)
        cnt = [0] * (max_nr + 1)
        for n in heights:
            cnt[n] += 1
        sum_cnt = [0] * (max_nr + 1)
        for i, n in enumerate(cnt[1:], start=1):
            sum_cnt[i] = n + sum_cnt[i - 1]
        output = [0] * len(heights)
        for i in range(len(heights) - 1, -1, -1):
            output[sum_cnt[heights[i]] - 1] = heights[i]
            sum_cnt[heights[i]] -= 1
        ans = 0
        for i, n in enumerate(heights):
            if n != output[i]:
                ans += 1
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.heightChecker(heights=[1, 1, 4, 2, 1, 3]))
    print(obj.heightChecker(heights=[5, 1, 2, 3, 4]))
    print(obj.heightChecker(heights=[1, 2, 3, 4, 5]))
