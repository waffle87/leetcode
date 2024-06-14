# 1178. Number of Valid Words for Each Puzzle

"""
with respect to a given puzzle string, a word is valid of both the following
conditions are satisfied. word contains the first letter of puzzle. for each
letter in word, that letter is in puzzle. invalid words are "beefed" (does
not include "a") and "based" (includes "s" which is not in the puzzle).
return an array where arr[i] is the number of words in the given word list
words that is valid with respect to the puzzle
"""


class Solution(object):
    def get_mask(self, word):
        mask = 0
        for c in word:
            i = ord(c) - ord("a")
            mask |= 1 << i
        return mask

    def findNumOfValidWords(self, words, puzzles):
        """
        :type words: List[str]
        :type puzzles: List[str]
        :rtype: List[int]
        """
        freq = {}
        for w in words:
            mask = self.get_mask(w)
            freq[mask] = freq.get(mask, 0) + 1
        ans = [0] * len(puzzles)
        for i in range(len(puzzles)):
            p = puzzles[i]
            mask = self.get_mask(p)
            sub_mask = mask
            total = 0
            bit_idx = ord(p[0]) - ord("a")
            while True:
                if sub_mask >> bit_idx & 1:
                    total += freq.get(sub_mask, 0)
                if not sub_mask:
                    break
                sub_mask = (sub_mask - 1) & mask
            ans[i] = total
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.findNumOfValidWords(
            words=["aaaa", "asas", "able", "ability", "actt", "actor", "access"],
            puzzles=["aboveyz", "abrodyz", "abslute", "absoryz", "actresz", "gaswxyz"],
        )
    )
    print(
        obj.findNumOfValidWords(
            words=["apple", "pleas", "please"],
            puzzles=["aelwxyz", "aelpxyz", "aelpsxy", "saelpxy", "xaelpsy"],
        )
    )
