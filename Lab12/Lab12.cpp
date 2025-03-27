#include <iostream>
//#include <iomanip>
using namespace std;

int **New2DArray(int rows, int cols);
void SpiralFill(int **mat, int rows, int cols);
void ZigzagFill(int **mat, int rows, int cols);
void DiagonalFill(int **mat, int rows, int cols);
void Display2DArray(int **mat, int rows, int cols);
void Delete2DArray(int **mat, int rows);

int main(void)
{
    char mode;
    cin >> mode;
    int rows, cols;
    cin >> rows >> cols;
    if (rows==0 || cols==0)
        return -1;
    int **matrix = New2DArray(rows, cols);
    if (mode == 'A')
        SpiralFill(matrix, rows, cols);
    else if (mode == 'B')
        ZigzagFill(matrix, rows, cols);
    else if (mode == 'C')
        DiagonalFill(matrix, rows, cols);
    Display2DArray(matrix, rows, cols);
    Delete2DArray(matrix, rows);
    return 0;
}

int **New2DArray(int rows, int cols)
{
    int **matrix = new int *[rows];
    for (int idx = 0; idx < rows; idx++)
        matrix[idx] = new int[cols];
    return matrix;
}
void SpiralFill(int **mat, int rows, int cols)
{
    int value = 1;
    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;
    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
            mat[top][i] = value++;
        top++;

        for (int i = top; i < bottom; i++)
            mat[i][right] = value++;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
                mat[bottom][i] = value++;
            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                mat[i][left] = value++;
            left++;
        }
        right--;
    }
}
void ZigzagFill(int **mat, int rows, int cols)
{
    int value = 1;
    for (int i = 0; i < rows; i++)
    {
        if (i % 2 == 0)
        {
            for (int k = 0; k < cols; k++)
            {
                mat[i][k] = value;
                value++;
            }
        }
        else
        {
            for (int k = cols-1; k >= 0; k--)
            {
                mat[i][k] = value;
                value++;
            }
        }
    }
}
void DiagonalFill(int **mat, int rows, int cols)
{
    int value = 1, sum = rows + cols - 2, idx = 0;
    for (int i = 0; i <= sum; i++)
    {
        while (i - idx >= 0)
        {
            if (idx>rows-1) break;
            while (i-idx>cols-1)
                idx++;
            mat[idx][i - idx] = value;
            value++;
            idx++;
        }
        idx = 0;
    }
}
void Display2DArray(int **mat, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        cout << mat[i][0];
        for (int k = 1; k < cols; k++)
            cout << " " << mat[i][k];
        cout << endl;
    }
}
void Delete2DArray(int **mat, int rows)
{
    for (int i = 0; i < rows; i++)
        delete[] mat[i];
    delete[] mat;
}