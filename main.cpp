#include "SpreadSheet.hpp"

int main()
{
    int row = 3;
    int col = 3;
    Spreadsheet sp(row, col);
    sp.SetCellAt(0,0, "String");
    sp.SetCellAt(0,1, 3.14);
    sp.Print();
    
}