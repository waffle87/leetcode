# 1291. Sequential Digits

"""
an integer has sequential digits if and only if each digit in the number is
one more than the previous digit. return a sorted list of all the integers in
the range '[low, high]' inclusive that have sequential digits.
"""


class Solution(object):
    def sequentialDigits(self, low, high):
        """
        :type low: int
        :type high: int
        :rtype: List[int]
        """
        ans = []
        queue = deque(range(1, 10))
        while queue:
            idx = queue.popleft()
            if low <= idx <= high:
                ans.append(idx)
            last = idx % 10
            if last < 9:
                queue.append(idx * 10 + last + 1)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.sequentialDigits(low=100, high=300))
    print(obj.sequentialDigits(low=1000, high=13000))
