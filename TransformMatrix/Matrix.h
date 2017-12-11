#ifndef MATRIX_H
#define MATRIX_H

#include <new>
#include <cmath>
#include <vector>
#include <math.h>
#include <iostream>
#include "AbstractMatrix.h"
#include "WrongSize.h"
#include "ErrorAlloc.h"
#include "ErrorIndex.h"
#include "NullObject.h"
#include "DividingByZero.h"
#include "ErrorPow.h"
#include "NoReverseMatrix.h"
#include "InOutMatrix.h"

#define EXCEPTION


template <class T>
class Matrix : public AbstractMatrix
{
public:
    Matrix();
    Matrix(int, int);
    Matrix(const Matrix<T>&);
    ~Matrix();

    // Ввод матрицы
    template <class TN>
    friend std::istream &operator>> (std::istream &, Matrix<TN> &);

    // Вывод матрицы
    template <class TN>
    friend std::ostream &operator<< (std::ostream &, const Matrix<TN> &);

    // Получить значение из матрицы по индексам
    T& getVal(int, int) const;
    T& operator()(int, int);

    // Установить значение в матрицу по индексам
    void setVal(int, int, T);
    void operator() (int, int, T);

    // Нахождение определителя матрицы
    T getDeterminant();
    T operator!();

    // След матрицы
    T getTrace();
    T operator* ();

    // Нахождение обратной матрицы
    Matrix<T> getReverseMatrix();
    Matrix<T> operator- ();

    // Транспонирование матрицы
    void transposition();
    void operator ~();

    // Умножение матрицы на число
    template <class TN>
    friend Matrix<TN> operator*(Matrix<TN> &, TN);

    template <class TN>
    friend Matrix<TN> operator*(TN, Matrix<TN> &);

    Matrix<T> MultNumber(T);

    // Сложение матриц
    Matrix<T> operator+ (const Matrix<T> &);
    Matrix<T> Sum(const Matrix<T> &);

    // Вычитание матриц
    Matrix<T> operator- (const Matrix<T> &);
    Matrix<T> Sub(const Matrix<T> &);

    // Умножение матриц
    Matrix<T> operator* (const Matrix<T> &) const;
    Matrix<T> Mult(const Matrix<T> &);

    // Присваивание матриц
    Matrix<T>& operator= (const Matrix<T> &);
    Matrix<T>& Assignment(const Matrix<T> &);

    // Возведение матрицу в целую степень
    Matrix<T> operator^ (int);
    Matrix<T> Power(int);

    // Сравнение матриц
    bool operator== (const Matrix<T> &);
    bool Equal(const Matrix<T> &);

    // Сравнение матриц
    bool operator!= (const Matrix<T> &);
    bool NotEqual(const Matrix<T> &);

    // Присваивание после сложения с матрицей
    Matrix<T>& operator+= (const Matrix<T> &);
    Matrix<T>& SumSelf(const Matrix<T> &);

    // Присваивание после вычитания с матрицей
    Matrix<T>& operator-= (const Matrix<T> &);
    Matrix<T>& SubSelf(const Matrix<T> &);

    // Присваивание после умножения с матрицей
    Matrix<T>& operator*= (const Matrix<T> &);
    Matrix<T>& MultSelf(const Matrix<T> &);

    // Присваивание после возведения матрицы в целую степень
    Matrix<T>& operator ^= (int);
    Matrix<T>& PowerSelf(int);

    // Присваивание после умножения на число
    Matrix<T>& operator*= (T);
    Matrix<T>& MultSelfNumber(T);

    // Поменять строки матрицы местами
    void ChangeRows(int, int);

    // Поменять столбцы матрицы местами
    void ChangeColumns(int, int);

    // Заполение матрицы одним заданным числом
    void FillWithNumber(T);

    // Создание единичной матрицы
    void createIdentityMatrix();


protected:
    T** matrix;

protected:
    T** alloc_memory(int, int);
    void free_memory();
    T find_max_in_column(int*,int, int);
    void null_row(int,int,T);
    void divide_row(T max, int i);
    void make_null_columns(Matrix<T>& ,int);
    T CountDeterminamt(int);
    T get_divisor_det(int);
    int get_sign_det(int);
};


template <class T>
Matrix<T>::Matrix()
{
    row_count = 0;
    column_count = 0;
    matrix = NULL;
}

template <class T>
Matrix<T>::Matrix(int n, int m)
{
    matrix = alloc_memory(n,m);
}

template <class T>
Matrix<T>::Matrix(const Matrix<T>& obj)
{
    if (!obj.matrix)
    {
        matrix = NULL;
        row_count = column_count = 0;
    }
    else
    {
        matrix = alloc_memory(obj.row_count,obj.column_count);
        for (int i = 0; i < row_count; i++)
            for (int j = 0; j < column_count; j++)
                matrix[i][j] = obj.matrix[i][j];
    }
}


template <class T>
Matrix<T>::~Matrix()
{
    free_memory();
}


template <class T>
T** Matrix<T>::alloc_memory(int n, int m)
{
    if (n <=0 || m <=0)
        throw WrongSize("Error size of matrix (alloc_memory)");

    row_count = n;
    column_count = m;

    T** buf = (T**) new (std::nothrow) char[row_count*sizeof(T*) + row_count*column_count*sizeof(T)];
    if (!buf)
        throw NullObject("Memory was not allocated for object (alloc_memory)!");

    for(int i = 0; i < row_count; i++)
        buf[i]  = (T*) ((char*) buf + row_count*sizeof(T*) + i*column_count*sizeof(T));
    return buf;
}

template <class T>
void Matrix<T>::free_memory()
{
    if (matrix)
    {
        delete [] matrix;
        //for(int i = 0; i < row_count; i++)
         //   delete[] matrix[i];
        //delete matrix;
        matrix = NULL;
        row_count = 0;
        column_count = 0;
    }
}


template <class T>
void Matrix<T>::createIdentityMatrix()
{
    if (!matrix)
        throw NullObject("Memory was not allocated for object (createIdentityMatrix)!");

#ifdef EXCEPTION
    if (row_count != column_count)
        throw WrongSize("Error size of matrix (createIdentityMatrix)");
#endif

    if (row_count == column_count)
    {
        for (int i = 0; i < row_count; i++)
            for (int j = 0; j < column_count; j++)
            {
                if (i == j)
                    matrix[i][j] = 1;
                else
                    matrix[i][j] = 0;
            }
    }
}

template <class T>
void Matrix<T>::FillWithNumber(T num)
{
    if (!matrix)
        throw NullObject("Memory was not allocated for object (FillWithNumber)!");

    for (int i = 0; i < row_count; i++)
        for (int j = 0; j < column_count; j++)
            matrix[i][j] = num;
}

template <class T>
void Matrix<T>::ChangeRows(int ind1, int ind2)
{
    if(!matrix)
        throw NullObject("Memory was not allocated for object (change_matrix_rows)!");

#ifdef EXCEPTION
    if (ind1 >= row_count || ind2 >= row_count || ind1 < 0 || ind2 < 0)
        throw ErrorIndex("Sush index doesn't exist in matrix (change_matrix_rows)!");
#endif

    if (ind1 < row_count && ind2 < row_count && ind1 >= 0 & ind2 >= 0)
    {
        T* temp = NULL;
        temp = *(matrix + ind1);
        *(matrix + ind1) = *(matrix + ind2);
        *(matrix + ind2) = temp;
    }
}

template <class T>
void Matrix<T>::ChangeColumns(int ind1, int ind2)
{
    if(!matrix)
        throw NullObject("Memory was not allocated for object (change_matrix_columns)!");

#ifdef EXCEPTION
    if (ind1 >= column_count || ind2 >= column_count || ind1 < 0 || ind2 < 0)
        throw ErrorIndex("Sush index doesn't exist in matrix (change_matrix_columns)!");
#endif
    if (ind1 < column_count && ind2 < column_count && ind1 >= 0 & ind2 >= 0)
    {
        T tmp = 0;
        for (int i = 0; i < row_count; i++)
        {
            tmp = matrix[i][ind1];
            matrix[i][ind1] = matrix[i][ind2];
            matrix[i][ind2] = tmp;
        }
    }
}

template <class T>
T& Matrix<T>::getVal(int i, int j) const
{
    if(!matrix)
        throw NullObject("Memory was not allocated for object (getVal)");
#ifdef EXCEPTION
    if (i >= row_count || j >= column_count || i < 0 || j < 0)
        throw ErrorIndex("Such index doesn't exist in matrix (getVal)!");
#endif
    if (i < row_count && j < column_count && i >= 0 && j >= 0)
        return matrix[i][j];
    return matrix[0][0];
}

template <class T>
void Matrix<T>::setVal(int i, int j, T value)
{
    if(!matrix)
        throw NullObject("Memory was not allocated for object (setVal)");
#ifdef EXCEPTION
    if (i >= row_count || j >= column_count || i < 0 || j < 0)
        throw ErrorIndex("Sush index doesn't exist in matrix (setVal)!");
#endif
    if (i < row_count && j < column_count && i >= 0 && j >= 0)
        matrix[i][j] = value;
}

template <class T>
T Matrix<T>::getTrace()
{
    if (!matrix)
        throw NullObject("Memory was not allocated for object (getTrace)!");
#ifdef EXCEPTION
    if (row_count != column_count)
        throw WrongSize("Error size of matrix (getTrace)!\n");
#endif
    if (row_count == column_count)
    {
        T tr = 0;
        for (int i = 0; i < row_count; i++)
                tr += matrix[i][i];
        return tr;
    }

}


template <class T>
T Matrix<T>::operator* ()
{
    return getTrace();
}


template <class T>
T Matrix<T>::getDeterminant()
{
    if (!matrix)
        throw NullObject("Memory was not allocated for object (getDeterminant)!");
#ifdef EXCEPTION
    if (row_count != column_count)
        throw WrongSize("Error size of matrix (getDeterminant)!");
#endif
    if (row_count == column_count)
    {
        Matrix<T> copy_matrix = *this;
        T prev = 0, k = 1;
        int sgn = 0;
        for (int i = 0 ; i < row_count ; i++)
        {
            if (i != (row_count-1))
            {
                prev = copy_matrix.matrix[i][i];
                if (!prev)
                    sgn = copy_matrix.get_sign_det(i);
                else
                    k *=  copy_matrix.get_divisor_det(i);
            }
        }
        return copy_matrix.CountDeterminamt(sgn)/k;
    }
}

template <class T>
T Matrix<T>::operator !()
{
    return getDeterminant();
}


template <class T>
void Matrix<T>::transposition()
{
    if (!matrix)
        throw NullObject("Memory was not allocated for object (transposition)!");

    Matrix<T> tr_matrix = *this;
    int n = column_count;
    int m = row_count;
    free_memory();
    matrix = alloc_memory(n,m);
    for (int i = 0 ; i < row_count; i++)
        for (int j = 0; j < column_count; j++)
            matrix[i][j] = tr_matrix.matrix[j][i];
}

template <class T>
void Matrix<T>::operator ~()
{
    transposition();
}

template <class T>
Matrix<T> Matrix<T>::getReverseMatrix()
{
    if (!matrix)
        throw NullObject("Memory was not allocated for object (getReverseMatrix)!");
#ifdef EXCEPTION
    if (row_count != column_count)
        throw WrongSize("Error size of matrix (getReverseMatrix)!");
    if (!getDeterminant())
        throw NoReverseMatrix("Impossible to find reverse matrix!");
#endif
    if (row_count == column_count && getDeterminant())
    {
        T max = 1;
        int index = 0;
        Matrix<T> ident_m(row_count,column_count);
        Matrix<T> copy_m = *this;
        ident_m.createIdentityMatrix();
        for (int i = 0 ; i < row_count ; i++)
        {
            max = copy_m.find_max_in_column(&index,i,i);
            if (index != i)
            {
                copy_m.ChangeRows(i,index);
                ident_m.ChangeRows(i,index);
            }
            copy_m.divide_row(max,i);
            ident_m.divide_row(max,i);
            copy_m.make_null_columns(ident_m,i);
        }
        return ident_m;
    }
}

template <class T>
Matrix<T> Matrix<T>::operator- ()
{
    return getReverseMatrix();
}



template <class T>
Matrix<T> Matrix<T>::operator + (const Matrix<T>& obj)
{
    if (!obj.matrix || !matrix)
        throw NullObject("Memory was not allocated for object (sum matrix)!");
#ifdef EXCEPTION
    if (row_count != obj.row_count || column_count != obj.column_count)
        throw WrongSize("Error size of matrix (sum matrix)!");
#endif
    if (row_count == obj.row_count && column_count == obj.column_count)
    {
        Matrix<T> sum(row_count,column_count);
        for (int i = 0; i < row_count; i++)
            for (int j = 0; j < column_count; j++)
                sum.matrix[i][j] =  matrix[i][j] + obj.matrix[i][j];
        return sum;
    }
}

template <class T>
Matrix<T> Matrix<T>::Sum(const Matrix<T>& obj)
{
    if (!obj.matrix || !matrix)
        throw NullObject("Memory was not allocated for object (Sum)!");
#ifdef EXCEPTION
    if (row_count != obj.row_count || column_count != obj.column_count)
        throw WrongSize("Error size of matrix (sum matrix)!");
#endif
    if (row_count == obj.row_count && column_count == obj.column_count)
    {
        Matrix<T> sum = *this + obj;
        return sum;
    }
}


template <class T>
Matrix<T> Matrix<T>::operator - (const Matrix<T>& obj)
{
    if (!obj.matrix || !matrix)
        throw NullObject("Memory was not allocated for object (subtraction matrix)!");
#ifdef EXCEPTION
    if (row_count != obj.row_count || column_count != obj.column_count)
        throw WrongSize("Error size of matrix (subtraction matrix)!");
#endif
    if (row_count == obj.row_count && column_count == obj.column_count)
    {
        Matrix<T> sum(row_count,column_count);
        for (int i = 0; i < row_count; i++)
            for (int j = 0; j < column_count; j++)
                sum.matrix[i][j] =  matrix[i][j] - obj.matrix[i][j];
        return sum;
    }
}

template <class T>
Matrix<T> Matrix<T>::Sub(const Matrix<T>& obj)
{
    if (!obj.matrix || !matrix)
        throw NullObject("Memory was not allocated for object (Sub)!");
#ifdef EXCEPTION
    if (row_count != obj.row_count || column_count != obj.column_count)
        throw WrongSize("Error size of matrix (subtraction matrix)!");
#endif
    if (row_count == obj.row_count && column_count == obj.column_count)
    {
        Matrix<T> sub = *this - obj;
        return sub;
    }
}


template <class T>
Matrix<T> Matrix<T>::operator* (const Matrix<T>& obj) const
{
    if (!obj.matrix || !matrix)
        throw NullObject("Memory was not allocated for object (mult matrix)!");
#ifdef EXCEPTION
    if (column_count != obj.row_count)
        throw WrongSize("Error size of matrix in mult matrix!");
#endif
    if (column_count == obj.row_count)
    {
        Matrix<T> mult(row_count,obj.column_count);
        T sum = 0;
        int l = 0;
        for(int i = 0; i < row_count; i++)
            for(int j = 0; j < obj.column_count; j++)
            {
                for(l = 0, sum = 0; l < column_count; l++)
                    sum += matrix[i][l]*obj.matrix[l][j];
                mult.matrix[i][j] = sum;
            }
        return mult;
    }
    return Matrix<T>();
}

template <class T>
Matrix<T> Matrix<T>::Mult(const Matrix<T> & obj)
{
    if (!obj.matrix || !matrix)
        throw NullObject("Memory was not allocated for object (Mult)!");
#ifdef EXCEPTION
    if (column_count != obj.row_count)
        throw WrongSize("Error size of matrix in mult matrix!");
#endif
    if (column_count == obj.row_count)
    {
        Matrix<T> mult = *this * obj;
        return mult;
    }
    return (*this);
}

template <class T>
Matrix<T> Matrix<T>::operator^(int pow)
{
    if (!matrix)
        throw NullObject("Memory was not allocated for object (involution matrix)!");
#ifdef EXCEPTION
    if (pow <= 0)
        throw ErrorPow("Pow of matrix must be > 0!");
    if (row_count != column_count)
        throw WrongSize("Error size of matrix (involution matrix)!");
#endif
    if (pow > 0 && row_count == column_count)
    {
        Matrix<T> pow_matrix = *this;
        for (int i = 1; i < pow; i++)
            pow_matrix *= *this;
        return pow_matrix;
    }
    return (*this);
}

template <class T>
Matrix<T> Matrix<T>::Power(int pow)
{
    Matrix<T> pow_matrix = *this ^ pow;
    return pow_matrix;
}


template <class T>
Matrix<T>& Matrix<T>::operator= (const Matrix<T>& obj)
{
    if(&obj == this)
        return *this;
    if (matrix)
        free_memory();
    if(!obj.matrix)
        return *this;
    matrix = alloc_memory(obj.row_count,obj.column_count);
    for (int i = 0; i < row_count; i++)
        for (int j = 0; j < column_count; j++)
            matrix[i][j] = obj.matrix[i][j];
    return (*this);
}

template <class T>
Matrix<T>& Matrix<T>::Assignment(const Matrix<T> & obj)
{
    *this = obj;
    return *this;
}

template <class T>
bool Matrix<T>::operator== (const Matrix<T> & obj)
{
    if (!obj.matrix || !matrix)
        throw NullObject("Memory was not allocated for object (compare matrix ==)!");

    if (row_count != obj.row_count || column_count != obj.column_count)
        return false;

    double eps = 0.0000001;
    int count = 0;
    for (int i = 0; i < row_count; i++)
        for (int j = 0; j < column_count; j++)
            if ( fabs(matrix[i][j] - obj.matrix[i][j]) <= eps)
                count++;
    if (count != row_count*column_count)
        return false;
    return true;
}

template <class T>
bool Matrix<T>::Equal(const Matrix<T> & obj)
{
    return *this == obj;
}

template <class T>
bool Matrix<T>::operator!= (const Matrix<T> & obj)
{
    if (!obj.matrix || !matrix)
        throw NullObject("Memory was not allocated for object (compare matrix !=)!");

    return !(*this == obj);
}

template <class T>
bool Matrix<T>::NotEqual(const Matrix<T> & obj)
{
    return *this != obj;
}

template <class T>
Matrix<T>& Matrix<T>::operator+= (const Matrix<T> & obj)
{
    *this = *this + obj;
    return *this;
}
template <class T>
Matrix<T>& Matrix<T>::SumSelf(const Matrix<T> & obj)
{
    *this = *this + obj;
    return *this;
}

template <class T>
Matrix<T>& Matrix<T>::operator-= (const Matrix<T> & obj)
{
    *this = *this - obj;
    return *this;
}

template <class T>
Matrix<T>& Matrix<T>::SubSelf(const Matrix<T> & obj)
{
    *this = *this - obj;
    return *this;
}

template <class T>
Matrix<T>& Matrix<T>::operator*= (const Matrix<T> &obj)
{
    *this = *this * obj;
    return *this;
}

template <class T>
Matrix<T>& Matrix<T>::MultSelf(const Matrix<T> & obj)
{
    *this = *this * obj;
    return *this;
}

template <class T>
Matrix<T>& Matrix<T>::operator ^= (int pow)
{
     *this = *this ^ pow;
     return *this;
}

template <class T>
Matrix<T>& Matrix<T>::PowerSelf(int pow)
{
    *this = *this ^ pow;
    return *this;
}

template <class T>
Matrix<T>& Matrix<T>::operator*= (T num)
{
    if (!matrix)
        throw NullObject("Memory was not allocated for object (*= with number)!");

    for (int i = 0; i < row_count; i++)
        for (int j = 0; j < column_count; j++)
            matrix[i][j] *= num;
    return *this;
}

template <class T>
Matrix<T>& Matrix<T>::MultSelfNumber(T num)
{
    return *this *= num;
}


template <class T>
Matrix<T> operator*(T num, Matrix<T>& obj)
{
    if (!obj.matrix)
        throw NullObject("Memory was not allocated for object (mult with number)!");

    int row_count = obj.getRowCount();
    int column_count = obj.getColumnCount();
    Matrix<T> mult(row_count,column_count);
    for (int i = 0; i < row_count; i++)
        for (int j = 0; j < column_count; j++)
            mult.setVal(i, j, num * obj.getVal(i, j));
    return mult;
}

template <class T>
Matrix<T> operator*(Matrix<T>& obj, T num)
{
    if (!obj.matrix)
        throw NullObject("Memory was not allocated for object (mult with number)!");

    int row_count = obj.getRowCount();
    int column_count = obj.getColumnCount();
    Matrix<T> mult(row_count,column_count);
    for (int i = 0; i < row_count; i++)
        for (int j = 0; j < column_count; j++)
            mult.setVal(i, j, num * obj.getVal(i, j));
    return mult;
}

template <class T>
Matrix<T> Matrix<T>::MultNumber(T num)
{
    Matrix<T> mult = *this * num;
    return mult;
}

template <class T>
T& Matrix<T>::operator()(int i, int j)
{
    if (!matrix)
        throw NullObject("Memory was not allocated for object GET_VAL()!");
#ifdef EXCEPTION
    if (i >= row_count || j >= column_count || i < 0 || j < 0)
        throw ErrorIndex("Sush index doesn't exist in matrix (GET_VAL)!");
#endif
    if (i >= 0 && i < row_count && j >= 0 && j < column_count)
        return matrix[i][j];
}

template <class T>
void Matrix<T>::operator() (int i, int j, T value)
{
    if (!matrix)
        throw NullObject("Memory was not allocated for object SET_VAL()!");
#ifdef EXCEPTION
    if (i >= row_count || j >= column_count || i < 0 || j < 0)
        throw ErrorIndex("Sush index doesn't exist in matrix (SET_VAL)!");
#endif
    if (i >= 0 && i < row_count && j >= 0 && j < column_count)
        matrix[i][j] = value;
}





/// PRIVATE ФУНКЦИИ


template <class T>
T Matrix<T>::find_max_in_column(int *index, int l, int column)
{
    if(!matrix)
        throw NullObject("Memory was not allocated for object (find_max_in_column)!");
    int j = 0;
    T max = 0;
    for (j = l, max = matrix[l][column], *index = l; j < row_count; j++)
    {
        if (fabs(matrix[j][column]) > fabs(max))
        {
            max = matrix[j][column];
            *index = j;
        }
    }
    return max;
}

template <class T>
int Matrix<T>::get_sign_det(int i)
{
    if (!matrix)
        throw NullObject("Memory was not allocated for object (get_sign_det)!");
    int sgn = 0;
    for (int j = i ; j < row_count ;j++)
        if (matrix[j][i] != 0)
        {
            ChangeRows(i,j);
            sgn++;
        }
    return sgn;
}

template <class T>
T Matrix<T>::get_divisor_det(int i)
{
    if (!matrix)
        throw NullObject("Memory was not allocated for object (get_divisor_det)!");
    T k = 1, ks = 1;
    for (int j = 0 ; j < row_count ;j++)
        if (matrix[j][i] != 0 && (j > i))
        {
            k *= matrix[i][i]*(-1);
            ks = matrix[j][i];
            for (int l = 0 ; l < row_count ; l++)
                matrix[j][l] = -matrix[j][l]*matrix[i][i] + ks*matrix[i][l];
        }
    return k;
}

template <class T>
T Matrix<T>::CountDeterminamt(int sgn)
{
    if (!matrix)
        throw NullObject("Memory was not allocated for object (CountDeterminamt)!");
    T det = 1;
    for(int i = 0; i < row_count ;i++)
        for (int j = 0; j < column_count; j++)
            if (i == j)
                det *= matrix[i][j];
    if (sgn%2 != 0)
        det *= -1;
    return det;
}

template <class T>
void Matrix<T>::make_null_columns(Matrix<T> &m, int i)
{
    if (!matrix || !m.matrix)
        throw NullObject("Memory was not allocated for object (make_null_columns)!");

    T k = 1;
    for (int j = 0 ; j < row_count ;j++)
    {
        if ((j != i))
        {
            k = matrix[j][i]*(-1);
            null_row(i,j,k);
            m.null_row(i,j,k);
        }
    }
}

template <class T>
void Matrix<T>::divide_row(T max, int i)
{
    if (!matrix)
        throw NullObject("Memory was not allocated for object (divide_row)!");
#ifdef EXCEPTION
    if (!max)
        throw DividingByZero("Dividing by zero (divide_row)!\n");
#endif
    if (max != 0)
    {
        for (int j = 0 ; j < column_count ;j++)
            matrix[i][j] = matrix[i][j]/max;
    }
}

template <class T>
void Matrix<T>::null_row(int i, int j, T k)
{
    if (!matrix)
        throw NullObject("Memory was not allocated for object (null_column)!");

    for (int l = 0; l < column_count ; l++)
      matrix[j][l] = matrix[j][l] + matrix[i][l]*k;
}


template <class t> class Vec2
{
public:
    t x, y;
    Vec2<t>() : x(t()), y(t()) {}
    ~Vec2<t>() {}
    Vec2<t>(t _x, t _y) : x(_x), y(_y) {}
    Vec2<t> operator +(const Vec2<t> &V) const { return Vec2<t>(x+V.x, y+V.y); }
    Vec2<t> operator -(const Vec2<t> &V) const { return Vec2<t>(x-V.x, y-V.y); }
    Vec2<t> operator *(double f)          const { return Vec2<t>(x*f, y*f); }
    t& operator[](const int i) { return i<=0 ? x : y; }
    template <class > friend std::ostream& operator<<(std::ostream& s, Vec2<t>& v);
};

template <class t> class Vec3
{
public:
    t x, y, z;
    Vec3<t>() : x(t()), y(t()), z(t()) { }
    ~Vec3<t>() {}
    Vec3<t>(t _x, t _y, t _z) : x(_x), y(_y), z(_z) {}
    Vec3<t>(Matrix<t> m);
    template <class u> Vec3<t>(const Vec3<u> &v);
    Vec3<t> operator ^(const Vec3<t> &v) const { return Vec3<t>(y*v.z-z*v.y, z*v.x-x*v.z, x*v.y-y*v.x); }
    Vec3<t> operator +(const Vec3<t> &v) const { return Vec3<t>(x+v.x, y+v.y, z+v.z); }
    Vec3<t> operator -(const Vec3<t> &v) const { return Vec3<t>(x-v.x, y-v.y, z-v.z); }
    bool   operator ==(const Vec3<t> &v) const { return ((x == v.x) && (y == v.y) && (z == v.z)); }
    Vec3<t> operator *(double f)          const { return Vec3<t>(x*f, y*f, z*f); }

    Vec3<t> operator /(double f)          const { return Vec3<t>(x/f, y/f, z/f); }
    t       operator *(const Vec3<t> &v) const { return x*v.x + y*v.y + z*v.z; }
    double norm () const { return std::sqrt(x*x+y*y+z*z); }
    Vec3<t> & normalize(t l=1)
    {
        if (norm() == 0)
            return *(new Vec3<t>());

        *this = (*this)*(l/norm());
        return *this;
    }
    t& operator[](const int i) { return i<=0 ? x : (1==i ? y : z); }
    template <class > friend std::ostream& operator<<(std::ostream& s, Vec3<t>& v);
};

typedef Vec2<double> Vec2f;
typedef Vec2<int>   Vec2i;
typedef Vec3<double> Vec3f;
typedef Vec3<int>   Vec3i;

template <> template <> Vec3<int>::Vec3(const Vec3<double> &v);
template <> template <> Vec3<double>::Vec3(const Vec3<int> &v);


template <class t> std::ostream& operator<<(std::ostream& s, Vec2<t>& v) {
    s << "(" << v.x << ", " << v.y << ")\n";
    return s;
}

template <class t> std::ostream& operator<<(std::ostream& s, Vec3<t>& v) {
    s << "(" << v.x << ", " << v.y << ", " << v.z << ")\n";
    return s;
}



#endif // MATRIX_H
