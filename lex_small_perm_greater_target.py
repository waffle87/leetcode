# 3720. Lexicographically Smallest Permutation Greater Than Target

"""
you are given two strings 's' and 'target', both having legnth 'n',
consisting of lowercase english letters. return the lexicographically
smallest permutation of 's' that is strictly greater than 'target'. if no
permutation of 's' is lexicographically strictly greater than 'target',
return an empty string.
"""


class Solution:
    def lexGreaterPermutation(self, s: str, target: str) -> str:
        s = [ord(c) - 97 for c in s]
        target = [ord(c) - 97 for c in target]
        s.sort(reverse=True)
        ans = []
        for i, x in enumerate(target):
            if x in s:
                s.remove(x)
                if s > target[i + 1 :]:
                    ans.append(x)
                    continue
                s.append(x)
                s.sort(reverse=True)

            s.sort()
            for y in s:
                if y > x:
                    s.remove(y)
                    ans.append(y)
                    ans.extend(s)
                    break
            break

        return "".join(chr(97 + x) for x in ans)


if __name__ == "__main__":
    obj = Solution()
    print(obj.lexGreaterPermutation(s="abc", target="bba"))
    print(obj.lexGreaterPermutation(s="leet", target="code"))
    print(obj.lexGreaterPermutation(s="baba", target="bbaa"))
