#include <iostream>
#include <iomanip>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    double matrix[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = k + 1; i < n; i++)
        {
            double multiple = matrix[i][k] / matrix[k][k];
            for (int j = k; j < n; j++)
            {
                matrix[i][j] -= multiple * matrix[k][j];
            }
        }
    }
    double result = 1;
    for (int i = 0; i < n; i++)
        result *= matrix[i][i];
    cout << fixed << setprecision(2) << result << endl;
    return 0;
}