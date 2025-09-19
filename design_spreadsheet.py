# 3484. Design Spreadsheet

"""
a spreadsheet is a grid with 26 columns labeled from 'A' to 'Z' and a given
number of 'rows'. each cell in the spreadsheet can hold an integer value
between 0 and 10^5. note: if 'spreadsheetGetValue' references a cell that has
not been explicitly set using 'spreadsheetSetCell', its value is considered
to be 0.
"""


class Spreadsheet(object):
    def __init__(self, rows):
        """
        :type rows: int
        """
        self.rows = rows
        self.cells = {}

    def setCell(self, cell, value):
        """
        :type cell: str
        :type value: int
        :rtype: None
        """
        self.cells[cell] = value

    def resetCell(self, cell):
        """
        :type cell: str
        :rtype: None
        """
        self.cells.pop(cell, None)

    def getValue(self, formula):
        """
        :type formula: str
        :rtype: int
        """
        parts = formula[1:].split("+")
        return sum(int(p) if p.isdigit() else self.cells.get(p, 0) for p in parts)


if __name__ == "__main__":
    obj = Spreadsheet(3)
    print(obj.getValue(formula="=5+7"))
    obj.setCell(cell="A1", value=10)
    print(obj.getValue(formula="=A1+6"))
    obj.setCell(cell="B2", value=15)
    print(obj.getValue(formula="=A1+B2"))
    obj.resetCell(cell="A1")
    print(obj.getValue(formula="=A1+B2"))
