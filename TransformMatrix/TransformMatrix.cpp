#include "TransformMatrix.h"
#define DEG_TO_RAD(x) ((double)(((x)* M_PI)/180.0))

TransformMatrix::TransformMatrix()
{
    matrix = alloc_memory(4,4);
    createIdentityMatrix();
}

TransformMatrix::TransformMatrix(const TransformMatrix & obj) : Matrix()
{
    if (!obj.matrix)
    {
        matrix = NULL;
        row_count = column_count = 0;
    }
    else
    {
        matrix = alloc_memory(obj.row_count,obj.column_count);
        int i = 0, j = 0;
        for (i = 0; i < row_count; i++)
            for (j = 0; j < column_count; j++)
                matrix[i][j] = obj.matrix[i][j];
    }
}

TransformMatrix::~TransformMatrix()
{
    free_memory();
}

void TransformMatrix::createRotateXMatrix(double arc)
{
    arc = DEG_TO_RAD(arc);
    matrix[1][1] = cos(arc);
    matrix[1][2] = -sin(arc);
    matrix[2][1] = sin(arc);
    matrix[2][2] = cos(arc);
    matrix[3][3] = 1;
}

void TransformMatrix::createRotateYMatrix(double arc)
{
    arc = DEG_TO_RAD(arc);
    matrix[0][0] = cos(arc);
    matrix[0][2] = sin(arc);
    matrix[2][0] = -sin(arc);
    matrix[2][2] = cos(arc);
    matrix[3][3] = 1;
}

void TransformMatrix::createRotateZMatrix(double arc)
{
    arc = DEG_TO_RAD(arc);
    matrix[0][0] = cos(arc);
    matrix[0][1] = -sin(arc);
    matrix[1][0] = sin(arc);
    matrix[1][1] = cos(arc);
    matrix[3][3] = 1;
}

void TransformMatrix::createMoveMatrix(double dx, double dy, double dz)
{
    matrix[3][0] = dx;
    matrix[3][1] = dy;
    matrix[3][2] = dz;
    matrix[3][3] = 1;
}

void TransformMatrix::createZoomMatrix(double dx, double dy, double dz)
{
    matrix[0][0] = dx;
    matrix[1][1] = dy;
    matrix[2][2] = dz;
    matrix[3][3] = 1;
}
