#include <iostream>
using namespace std;
const int MOD = 1e9 + 7; // 模數，避免整數溢位

void matrixMultiply(long long A[3][3], long long B[3][3], long long result[3][3])
{
    long long temp[3][3] = {0};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                temp[i][j] = (temp[i][j] + A[i][k] * B[k][j] % MOD) % MOD;
            } // 記得隨時取模避免溢位
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result[i][j] = temp[i][j];
        }
    }
}

void matrixPower(long long A[3][3], long long exp, long long result[3][3])
{
    long long base[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            base[i][j] = A[i][j];
            result[i][j] = (i == j) ? 1 : 0;
        } // 初始化result為單位矩陣免得出錯
    }

    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            matrixMultiply(result, base, result);
        }
        matrixMultiply(base, base, base); // base=base*base(快速冪)
        exp /= 2;
    }
}

int main()
{
    int size;
    cin >> size;
    long long A[3][3] = {{1, 2, 1}, {1, 0, 0}, {0, 1, 0}};
    long long B[3] = {13, 12, 1};

    for (int index = 0; index < size; index++)
    {
        long long k;
        cin >> k;

        if (k == 1)
        {
            cout << 1 << endl;
        }
        else if (k == 2)
        {
            cout << 12 << endl;
        }
        else if (k == 3)
        {
            cout << 13 << endl;
        }
        else
        {
            long long result[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
            matrixPower(A, k - 3, result);
            long long answer = 0;
            for (int i = 0; i < 3; i++)
            {
                answer = (answer + result[0][i] * B[i] % MOD) % MOD;
            }
            cout << answer << endl;
        }
    }
    return 0;
}