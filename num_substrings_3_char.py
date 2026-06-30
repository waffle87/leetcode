# 1358. Number of Substrings Containing All Three Characters

"""
given a string 's' consisting only of characters 'a', 'b', and 'c'. return
the number of substrings containing at least one occurence of all these
characters 'a', 'b', and 'c'.
"""


class Solution:
    def numberOfSubstrings(self, s: str) -> int:

        lastSeen = [-1, -1, -1]
        count = 0
        for i in range(len(s)):
            lastSeen[ord(s[i]) - ord("a")] = i
            if lastSeen[0] != -1 and lastSeen[1] != -1 and lastSeen[2] != -1:
                count += 1 + min(lastSeen[0], lastSeen[1], lastSeen[2])
        return count


if __name__ == "__main__":
    obj = Solution()
    print(obj.numberOfSubstrings(s="abcabc"))
    print(obj.numberOfSubstrings(s="aaacb"))
    print(obj.numberOfSubstrings(s="abc"))
