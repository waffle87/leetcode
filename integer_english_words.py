# 273. Integer to English Words

"""
convert a non-negative integer 'num' to its english words represetation.
"""


class Solution(object):
    def numberToWords(self, num):
        """
        :type num: int
        :rtype: str
        """

        below_twenty = (
            "One Two Three Four Five Six Seven Eight Nine Ten Eleven Twelve "
            "Thirteen Fourteen Fifteen Sixteen Seventeen Eighteen Nineteen".split()
        )
        tens = "Twenty Thirty Forty Fifty Sixty Seventy Eighty Ninety".split()

        def words(n):
            if n < 20:
                return below_twenty[n - 1 : n]
            if n < 100:
                return [tens[n / 10 - 2]] + words(n % 10)
            if n < 1000:
                return [below_twenty[n / 100 - 1]] + ["Hundred"] + words(n % 100)
            for p, w in enumerate(("Thousand", "Million", "Billion"), 1):
                if n < 1000 ** (p + 1):
                    return words(n / 1000**p) + [w] + words(n % 1000**p)

        return " ".join(words(num)) or "Zero"


if __name__ == "__main__":
    obj = Solution()
    print(obj.numberToWords(123))
    print(obj.numberToWords(12345))
    print(obj.numberToWords(1234567))
