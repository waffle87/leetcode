# 2075. Decode the Slanted Ciphertext

"""
a string 'originalText' is encoded using a slanted transposition cipher to a
string 'encodedText' with the help of a matrix having a fixed number of
'rows'. given the encoded string 'encodedText' and a numbe of rows, return
the original string 'originalText'.
"""


class Solution:
    def decodeCiphertext(self, encodedText: str, rows: int) -> str:
        if rows == 1:
            return encodedText
        n, ans = len(encodedText), []
        cols = n // rows
        for c in range(cols):
            r, j = 0, c
            while r < rows and j < cols:
                ans.append(encodedText[r * cols + j])
                r += 1
                j += 1
        return "".join(ans).rstrip()


if __name__ == "__main__":
    obj = Solution()
    print(obj.decodeCiphertext(encodedText="ch   ie   pr", rows=3))
    print(obj.decodeCiphertext(encodedText="iveo    eed   l te   olc", rows=4))
    print(obj.decodeCiphertext(encodedText="coding", rows=1))
