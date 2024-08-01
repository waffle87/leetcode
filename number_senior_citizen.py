# 2678. Number of Senior Citizens

"""
you are given a 0-indexed array of strings 'details'. each element of
'details' provides information about a given passenger compressed into a
string of length '15'. the system is such that the first ten characters of
the phone number of passengers, the next character denotes the gender of the
person, the following two characters are used to indicate the age of the
person, and the last two characters determine the seat allotted to that
person. return the number of passengers who are strictly more than 60 years
old
"""


class Solution(object):
    def countSeniors(self, details):
        """
        :type details: List[str]
        :rtype: int
        """
        return sum(int(p[-4:-2]) > 60 for p in details)


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.countSeniors(
            details=["7868190130M7522", "5303914400F9211", "9273338290F4010"]
        )
    )
    print(obj.countSeniors(details=["1313579440F2036", "2921522980M5644"]))
