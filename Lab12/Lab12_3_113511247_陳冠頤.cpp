#include <iostream>
#include <cstring>
using namespace std;

int findLargestSquare(int **matrix, int R, int C)
{
    int *dp = new int[C];           // 用一維數組代替動態規劃的二維表
    memset(dp, 0, sizeof(int) * C); // 初始化為 0
    int max_side = 0;               // 最大正方形邊長
    int prev = 0;                   // 用於保存左上角的值

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            int temp = dp[j]; // 暫存 dp[j] 的值，用於更新 prev
            if (matrix[i][j] == 1)
            {
                if (i == 0 || j == 0)
                {
                    dp[j] = 1; // 第一行或第一列，直接設為 1
                }
                else
                {
                    // 狀態轉移：dp[j] = min(左, 上, 左上) + 1
                    dp[j] = min(dp[j], min(dp[j - 1], prev)) + 1;
                }
                max_side = max_side > dp[j] ? max_side : dp[j]; // 更新最大邊長
            }
            else
            {
                dp[j] = 0; // 如果是 0，無法形成正方形
            }
            prev = temp; // 更新 prev，為下一次迭代做準備
        }
    }

    delete[] dp;                // 釋放動態分配的內存
    return max_side * max_side; // 返回最大正方形的面積
}

int main()
{
    int R, C;
    cin >> R >> C;

    // 動態分配二維數組
    int **matrix = new int *[R];
    for (int i = 0; i < R; ++i)
    {
        matrix[i] = new int[C];
        for (int j = 0; j < C; ++j)
        {
            cin >> matrix[i][j];
        }
    }

    cout << findLargestSquare(matrix, R, C) << endl;

    // 釋放動態分配的內存
    for (int i = 0; i < R; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}