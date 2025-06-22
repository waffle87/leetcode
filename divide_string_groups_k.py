# 2138. Divide a String Into Groups of Size k

"""
a string 's' can be partitioned into groups of size 'k' using the following
procedure: the first group consists of the first 'k' characters of the
string, the second group consists of the next 'k' characters of the string,
ans so on. each element can be a part of exactly one group. for the last
group, if the string does not have 'k' characters remaining, a character
'fill' is used to complete the group. note that the partition is done so that
after removing the 'fill' character from the last group, and concatenating
all the groups in oder, the resultant string should be 's'. given a string
's', the size of each group 'k', and the character 'fill', return a string
array denoting the composition of every group 's' has been divided into.
"""


class Solution(object):
    def divideString(self, s, k, fill):
        """
        :type s: str
        :type k: int
        :type fill: str
        :rtype: List[str]
        """
        n = len(s)
        groups, ans = (n + k - 1) // k, []
        for i in range(groups):
            curr = ""
            for j in range(k):
                idx = i * k + j
                if idx < n:
                    curr += s[idx]
                else:
                    curr += fill
            ans.append(curr)
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(obj.divideString(s="abcdefghi", k=3, fill="x"))
    print(obj.divideString(s="abcdefghij", k=3, fill="x"))
