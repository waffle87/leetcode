# 2048. Next Greater Numerically Balanced Number

"""
an integer 'x' is numerically balanced if for every digit 'd' in the number
'x', there are exactly 'd' occurences of that digit in 'x'. given an integer
'n', return the smallest numerically balanced number strictly greater than
'n'
"""


class Solution(object):
    def is_beautiful(self, cnt):
        for i in range(1, 8):
            if cnt[i] != 0 and cnt[i] != i:
                return False
        return True

    def generate(self, num, cnt, nums):
        if num > 0 and self.is_beautiful(cnt):
            nums.append(num)
        if num > 1224444:
            return
        for i in range(1, 8):
            if cnt[i] < i:
                cnt[i] += 1
                self.generate(num * 10 + i, cnt, nums)
                cnt[i] -= 1

    def nextBeautifulNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        nums = []
        self.generate(0, [0] * 10, nums)
        nums.sort()
        for i in nums:
            if i > n:
                return i
        return -1


if __name__ == "__main__":
    obj = Solution()
    print(obj.nextBeautifulNumber(1))
    print(obj.nextBeautifulNumber(1000))
    print(obj.nextBeautifulNumber(3000))
