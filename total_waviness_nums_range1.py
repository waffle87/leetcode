# 3751. Total Waviness of Numbers in Range I

"""
you are given two integers 'num1' and 'num2' representing an inclusive range
'[num1, num2]'. the waviness of a number is defined as the total count of its
peaks and valleys. a digit is a peak if it is strictly greater than both its
immediate neighbours. a digit is a valley if it is strictly less than both of
its immediate neighbours. the first and last digits of a number cannot be
peaks or valleys. any number with fewer than 3 digits has a waviness of 0.
return the total sum of waviness for all numbers in the range '[num1, num2]'.
"""


class Solution:
    mx = 100001
    dp = [0] * mx
    pref = [0] * mx
    for i in range(100, mx):
        r = i % 10
        m = (i // 10) % 10
        l = (i // 100) % 10
        wave = m > max(l, r) or m < min(l, r)
        dp[i] = dp[i // 10] + int(wave)
        pref[i] = pref[i - 1] + dp[i]

    def totalWaviness(self, num1: int, num2: int) -> int:
        return self.pref[num2] - self.pref[num1 - 1]


if __name__ == "__main__":
    obj = Solution()
    print(obj.totalWaviness(num1=120, num2=130))
    print(obj.totalWaviness(num1=198, num2=202))
    print(obj.totalWaviness(num1=4848, num2=4848))
