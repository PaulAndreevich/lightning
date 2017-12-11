#ifndef ABSTRACTMATRIX_H
#define ABSTRACTMATRIX_H

class AbstractMatrix
{
protected:
    int row_count;
    int column_count;
public:
    int getRowCount() {return row_count;}
    int getColumnCount() {return column_count;}
    bool IsEmpty()
    {
        if (!row_count || !column_count)
                return true;
        return false;
    }
};

#endif // ABSTRACTMATRIX_H
