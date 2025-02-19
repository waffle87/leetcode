# 1415. The k-th Lexicographical String of All Happy Strings of Length n

"""
a happy string is a string that consists only of letters of the set '[a, b,
c]', 's[i] != s[i + 1]' for all values of 'i' from 1 to 's.length - 1'. given
two integers 'n' and 'k', consider a list of all happy strings of length 'n'
sorted in lexicographical order. return the k'th string of this list or
return an empty string if there are less than 'k' strings of length 'n'.
"""


class Solution(object):
    def getHappyString(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        m = n

        def dfs(prefix, n, k):
            if n == 0:
                return prefix
            for c in "abc":
                if prefix and c == prefix[-1]:
                    continue
                cnt = 2 ** (m - len(prefix) - 1)
                if cnt >= k:
                    return dfs(prefix + c, n - 1, k)
                else:
                    k -= cnt
            return ""

        return dfs("", n, k)


if __name__ == "__main__":
    obj = Solution()
    print(obj.getHappyString(1, 3))
    print(obj.getHappyString(1, 4))
    print(obj.getHappyString(3, 9))
