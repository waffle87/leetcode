# 338. Counting Bits

"""
given an integer 'n', return an array 'ans' of length 'n + 1' such that for
each 'i (0 <= i <= n)', 'ans[i]' is the number of 1's inthe binary
representation of 'i'
"""


class Solution(object):
    def countBits(self, n):
        cnt = [0]
        for i in range(1, n + 1):
            cnt.append(cnt[i >> 1] + i % 2)
        return cnt

if __name__ == "__main__":
    obj = Solution()
    print(obj.countBits(2)) # expect: 0 1 1
    print(obj.countBits(5)) # expect: 0 1 1 2 1 2
