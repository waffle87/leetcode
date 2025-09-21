# 1807. Evaluate the Bracket Pairs of a String

"""
you are given a string 's' that contains some bracket pairs, with each pair
containing a non-empty key. you know the values of a wide range of keys.
thiis represented by a 2d string array 'knowledge' where each 'knowledge[i] =
[key_i, value_i]' indicates that key 'key_i' has a value of 'value_i'. you
are tasked evaluate a bracket pair that contains some key 'key_i' you will
replace 'key_i' and the bracket pair with the key's corresponding 'value_i'.
if you do not know the value of the key you will replace 'key_i' and the
bracket pair with a question mark. return the resulting string after
evaluting all of the bracket pairs.
"""


class Solution(object):
    def evaluate(self, s, knowledge):
        """
        :type s: str
        :type knowledge: List[List[str]]
        :rtype: str
        """
        d = {k: v for k, v in knowledge}
        t = s.split("(")
        ans = t[0]
        for i in range(1, len(t)):
            a, b = t[i].split(")")
            ans += d.get(a, "?") + b
        return ans


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.evaluate(
            s="(name)is(age)yearsold", knowledge=[["name", "bob"], ["age", "two"]]
        )
    )
    print(obj.evaluate(s="hi(name)", knowledge=[["a", "b"]]))
    print(obj.evaluate(s="(a)(a)(a)aaa", knowledge=[["a", "yes"]]))
