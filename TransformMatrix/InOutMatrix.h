#ifndef INOUTMATRIX_H
#define INOUTMATRIX_H

template <class TN>
class Matrix;

template <class TN>
std::ostream& operator<< (std::ostream& out, Matrix<TN> & obj)
{
    int i = 0, j = 0;
    for (i = 0; i < obj.getRowCount(); i++)
    {
        for (j = 0; j < obj.getColumnCount(); j++)
            out << obj(i, j) << " ";
        out << "\n";
    }
    return out;
}

template <class TN>
std::istream& operator >>(std::istream& in,  Matrix<TN> &obj)
{
    int n = 0, m = 0;  
    in >> n >> m;
    if (n <= 0 || m <= 0)    
        throw WrongSize("Error size of matrix in reading! n > 0 && m > 0!\n");

    if (obj.matrix)
        obj.free_memory();
    obj.matrix = obj.alloc_memory(n,m);
    TN value = 0;
    int i = 0, j = 0;
    for (i = 0; i < obj.getRowCount(); i++)
        for (j = 0; j < obj.getColumnCount(); j++)
        {
            in >> value;
            obj(i, j, value);
        }
    return in;
}
#endif // INOUTMATRIX_H
