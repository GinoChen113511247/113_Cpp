#include <iostream>
using namespace std;

const long long mod = 1e9 + 7;

void matrixMultiply(long long a[3][3], long long b[3][3])
{
    long long temp[3][3] = {};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                temp[i][j] += a[i][k] * b[k][j];
                temp[i][j] %= mod;
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            a[i][j] = temp[i][j];
    }
}

int main(void)
{
    int N;
    cin >> N;
    int expo = N - 1;
    long long trans[3][3] = {{1, 3, 1}, {1, 0, 2}, {1, 1, 0}};
    long long result[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}; // 單位矩陣

    while (expo > 0)
    {
        if (expo % 2 == 1)
            matrixMultiply(result, trans);

        matrixMultiply(trans, trans); // 將 trans 矩陣平方
        expo /= 2;
    }

    long long f = (result[0][0] + result[1][0] + result[2][0]) % mod;
    long long g = (result[0][1] + result[1][1] + result[2][1]) % mod;
    long long h = (result[0][2] + result[1][2] + result[2][2]) % mod;

    cout << f << " " << g << " " << h;
    return 0;
}