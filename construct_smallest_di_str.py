# 2375. Construct Smallest Number From DI String

"""
you are given a 0-indexed string 'pattern' of length 'n' consisting of the
characters 'I' meaning increased and 'D' meaning decreased. a 0-indexed
string 'num' of length 'n + 1' is created using thhe following conditions:
'num' consists of the digits 1 to 9, where each digit is used at most once,
if 'pattern[i] == I', then 'num[i] < num[i + 1]', and if 'pattern[i] == D',
thhen 'num[i] > num[i + 1]'. return the lexicographically smallest possible
string 'num' that meets the conditions.
"""


class Solution(object):
    def smallestNumber(self, pattern):
        """
        :type pattern: str
        :rtype: str
        """
        ans, pool = [], list("987654321")
        for i in map(len, pattern.split("I")):
            ans += [pool.pop() for _ in range(i + 1)][::-1]
        return "".join(ans)


if __name__ == "__main__":
    obj = Solution()
    print(obj.smallestNumber(pattern="IIIDIDDD"))
    print(obj.smallestNumber(pattern="DDD"))
