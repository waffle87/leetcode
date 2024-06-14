# 455. Assign Cookies

"""
assume you are an awesome parent and want to give your children some cookies.
but you should give each child at most one cookie. each child 'i' has a greed
factor 'g[i]', which is the minimum size of a cookie that the child will be
content with; and each cookie 'j' has a size 's[j]' if 's[j] >= g[i]', we can
assign the cookie 'j' to the child 'i', and the child 'i' will be content.
your goal is to maximise the number of your content children and output the
maximum number.
"""


class Solution(object):
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        g.sort(reverse=True)
        s.sort(reverse=True)
        res, i, j = 0, 0, 0
        while i < len(g) and j < len(s):
            if g[i] <= s[j]:
                res += 1
                i += 1
                j += 1
            else:
                i += 1
        return res


if __name__ == "__main__":
    obj = Solution()
    print(obj.findContentChildren(g=[1, 2, 3], s=[1, 1]))  # expect: 1
    print(obj.findContentChildren(g=[1, 2], s=[1, 2, 3]))  # expect: 2
