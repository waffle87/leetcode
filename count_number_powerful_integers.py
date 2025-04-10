# 2999. Count the Number of Powerful Integers

"""
you are given three integers 'start', 'finish', and 'limit'. you are also
given a 0-indexed string 's' representing a positive integer. a positive
integer 'x' is called powerful if it ends with 's' and each digit in 'x' is
at most 'limit'. return the total number of powerful integers in the range
'[start .. finish]'. a string 'x' is a suffix of a string 'y' if and only if
'x' is a substring of 'y' that starts from some index in 'y' and extends to
the index 'y.length - 1'.
"""


class Solution(object):
    def numberOfPowerfulInt(self, start, finish, limit, s):
        """
        :type start: int
        :type finish: int
        :type limit: int
        :type s: str
        :rtype: int
        """
        cnt = [0] * 16

        def get_cnt(n, s):
            res, i, size = cnt[len(n) - 1], 0, len(n) - len(s)
            while True:
                res += (
                    n[i:] >= s
                    if i == size
                    else cnt[len(n) - i - 1] * (min(limit, int(n[i]) - 1) + (i > 0))
                )
                i += 1
                if i > size or int(n[i - 1]) > limit:
                    break
            return res

        for i in range(len(s), 16):
            cnt[i] = 1 if i == len(s) else cnt[i - 1] * (limit + 1)
        return get_cnt(str(finish), s) - get_cnt(str(start - 1), s)


if __name__ == "__main__":
    obj = Solution()
    print(obj.numberOfPowerfulInt(start=1, finish=6000, limit=4, s="124"))
    print(obj.numberOfPowerfulInt(start=15, finish=215, limit=6, s="10"))
    print(obj.numberOfPowerfulInt(start=1000, finish=2000, limit=4, s="3000"))
