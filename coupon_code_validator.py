# 3606. Coupon Code Validator

"""
you are given three arrays of length 'n' that describe the properties of 'n'
coupons 'code', 'businessLine', and 'isActive'. the i'th coupon has a string
representing the coupon identifier, a string denoting the business category
of the coupon, a boolean indicating if the coupon is currently active. a
coupon is considered valid if all of the following conditions hold: 'code[i]'
is non-empty and consists of only alphanumeric characters and underscores,
'businessLine[i]' is one of the categories electronics, grocery, pharmacy, or
restaurant, and 'isActive[i]' is True. return an array of the codes of all
valid coupons sorted first by their 'businessLine' order.
"""


class Solution(object):
    def validateCoupons(self, code, businessLine, isActive):
        """
        :type code: List[str]
        :type businessLine: List[str]
        :type isActive: List[bool]
        :rtype: List[str]
        """

        def valid(record):
            return (
                record[0] in valid_business
                and record[2]
                and record[1].replace("_", "a").isalnum()
            )

        valid_business = {"electronics", "grocery", "restaurant", "pharmacy"}
        ans = sorted(filter(valid, zip(businessLine, code, isActive)))
        return [id for _, id, _ in ans]


if __name__ == "__main__":
    obj = Solution()
    print(
        obj.validateCoupons(
            code=["SAVE20", "", "PHARMA5", "SAVE@20"],
            businessLine=["restaurant", "grocery", "pharmacy", "restaurant"],
            isActive=[True, True, True, True],
        )
    )
    print(
        obj.validateCoupons(
            code=["GROCERY15", "ELECTRONICS_50", "DISCOUNT10"],
            businessLine=["grocery", "electronics", "invalid"],
            isActive=[False, True, True],
        )
    )
