# 316. Remove Duplicate Letters

"""
given a string 's', remove duplicate letters so that every letter appears
once and only once. you must make sure your result is the smallest in
lexicographical order among all possible results.
"""


class Solution(object):
    def removeDuplicateLetters(self, s):
        last = {}
        stack = []
        visited = set()
        for i in range(len(s)):
            last[s[i]] = i
        for i in range(len(s)):
            if s[i] not in visited:
                while stack and stack[-1] > s[i] and last[stack[-1]] > i:
                    visited.remove(stack.pop())
                stack.append(s[i])
                visited.add(s[i])
        return "".join(stack)


if __name__ == "__main__":
    obj = Solution()
    print(obj.removeDuplicateLetters("bcabc"))  # expect: abc
    print(obj.removeDuplicateLetters("cbacdcbc"))  # expect: acdb
