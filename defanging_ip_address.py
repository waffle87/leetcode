# 1108. Defanging an IP Address
from re import sub

"""
given a valid ipv4 'address', return a defanged version of that ip address. a
defanged ip address replaces every period "." with '[.]'.
"""


class Solution(object):
    def defangIPaddr(self, address):
        """
        :type address: str
        :rtype: str
        """
        return sub("\.", "[.]", address)


if __name__ == "__main__":
    obj = Solution()
    print(obj.defangIPaddr(address="1.1.1.1"))
    print(obj.defangIPaddr(address="255.100.50.0"))
