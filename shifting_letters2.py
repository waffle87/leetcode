# 2381. Shifting Letters II

"""
you are given a string 's' of lowercase english letters and a 2d integer
array 'shifts' where 'shifts[i] = [start_i, end_i, direction_i]'. for every
'i', shift the characters in 's' from the index 'start_i' to he index 'end_i'
(inclusive) forward if the 'direction_i = 1' or shift the characters backward
if 'direction_i = 0'. shifting a character forward means replacing it with
the next letter in the alphabet. similarily, shifting a character backward
means replacing it with the previous alphabetic character. return the final
string ater all such shifts to 's' are applied
"""


class Solution(object):
    def shiftingLetters(self, s, shifts):
        """
        :type s: str
        :type shifts: List[List[int]]
        :rtype: str
        """
        n = len(s)
        shift = [0] * (n + 1)
        for i in shifts:
            start, end, direction = i
            shift[start] += 1 if direction == 1 else -1
            if end + 1 < n:
                shift[end + 1] -= 1 if direction == 1 else -1
        curr, ans = 0, list(s)
        for i in range(n):
            curr += shift[i]
            net = (curr % 26 + 26) % 26
            ans[i] = chr((ord(ans[i]) - ord("a") + net) % 26 + ord("a"))
        return "".join(ans)


if __name__ == "__main__":
    obj = Solution()
    print(obj.shiftingLetters(s="abc", shifts=[[0, 1, 0], [1, 2, 1], [0, 2, 1]]))
    print(obj.shiftingLetters(s="dztz", shifts=[[0, 0, 0], [1, 1, 1]]))
