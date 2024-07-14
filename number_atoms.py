# 726. Number of Atoms
from collections import defaultdict

"""
given a string 'formula' representing a chemical formula, return the count of
each atom. the atomic element always stats with an uppercase character, then
zer or more lowercase letters, representing the name. one or more digits
representing that element's count may follow if the count is greater than 1.
if the count is 1, no digits will follow. return the count of all elements as
a string in the following form: the first name, followed by its count,
followed by the second name, followed by its count, and so on.
"""


class Solution(object):
    def countOfAtoms(self, formula):
        """
        :type formula: str
        :rtype: str
        """
        dic, coeff, stack, elem, cnt, i = defaultdict(int), 1, [], "", 0, 0
        for c in formula[::-1]:
            if c.isdigit():
                cnt += int(c) * (10**i)
                i += 1
            elif c == ")":
                stack.append(cnt)
                coeff *= cnt
                i = cnt = 0
            elif c == "(":
                coeff //= stack.pop()
                i = cnt = 0
            elif c.isupper():
                elem += c
                dic[elem[::-1]] += (cnt or 1) * coeff
                elem = ""
                i = cnt = 0
            elif c.islower():
                elem += c
        return "".join(k + str(v > 1 and v or "") for k, v in sorted(dic.items()))


if __name__ == "__main__":
    obj = Solution()
    print(obj.countOfAtoms(formula="H2O"))
    print(obj.countOfAtoms(formula="Mg(OH)2"))
    print(obj.countOfAtoms(formula="K4(ON(SO3)2)2"))
