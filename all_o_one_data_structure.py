# 432. All O`one Data Structure

"""
design a data structure to store the strings' count with the ability to
return the strings with minimum and maximum counts. implement the 'allOne'
class. Note that each function must run in O(1) average time complexity
"""


class Block(object):
    def __init__(self, val=0):
        self.val = val
        self.keys = set()
        self.before = None
        self.after = None

    def remove(self):
        self.before.after = self.after
        self.after.before = self.before
        self.before, self.after = None, None

    def insert_after(self, new_block):
        old_after = self.after
        self.after = new_block
        new_block.before = self
        new_block.after = old_after
        old_after.before = new_block


class AllOne(object):
    def __init__(self):
        self.begin = Block()
        self.end = Block()
        self.begin.after = self.end
        self.end.before = self.begin
        self.mapping = {}

    def inc(self, key):
        """
        :type key: str
        :rtype: None
        """
        if not key in self.mapping:
            current_block = self.begin
        else:
            current_block = self.mapping[key]
            current_block.keys.remove(key)
        if current_block.val + 1 != current_block.after.val:
            new_block = Block(current_block.val + 1)
            current_block.insert_after(new_block)
        else:
            new_block = current_block.after
        new_block.keys.add(key)
        self.mapping[key] = new_block

        if not current_block.keys and current_block.val != 0:
            current_block.remove()

    def dec(self, key):
        """
        :type key: str
        :rtype: None
        """
        if not key in self.mapping:
            return
        current_block = self.mapping[key]
        del self.mapping[key]
        current_block.keys.remove(key)
        if current_block.val != 1:
            if current_block.val - 1 != current_block.before.val:
                new_block = Block(current_block.val - 1)
                current_block.before.insert_after(new_block)
            else:
                new_block = current_block.before
            new_block.keys.add(key)
            self.mapping[key] = new_block
        if not current_block.keys:
            current_block.remove()

    def getMaxKey(self):
        """
        :rtype: str
        """
        if self.end.before.val == 0:
            return ""
        key = self.end.before.keys.pop()
        self.end.before.keys.add(key)
        return key

    def getMinKey(self):
        """
        :rtype: str
        """
        if self.begin.after.val == 0:
            return ""
        key = self.begin.after.keys.pop()
        self.begin.after.keys.add(key)
        return key


if __name__ == "__main__":
    obj = AllOne()
    obj.inc("hello")
    obj.inc("hello")
    print(obj.getMaxKey())
    print(obj.getMinKey())
    obj.inc("leet")
    print(obj.getMaxKey())
    print(obj.getMinKey())
