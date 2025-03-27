#include <iostream>
using namespace std;

int *findInvArr(int *A, int size)
{
    int *B = new int[size];
    for (int k = 0; k < size; ++k)
    {
        int count = 0;
        for (int j = 0; j < k; ++j)
        {
            if (A[j] < A[k])
                count++;
        }
        B[k] = count;
    }
    return B;
}

int *findPermArr(int *B, int size)
{
    // 題目有說原數列是不會跳過數字和沒有重複數字的(e.g. 3, 1, 2, 4 ,0)
    // 不然有多個A可得出同一個B
    int *A = new int[size];
    int *L = new int[size];
    for (int i = 0; i < size; ++i)
    {
        L[i] = i;
    } // 儲存要填的數字(已經用遞增的方式排列好了)
    int len = size;
    for (int k = size - 1; k >= 0; --k)
    {
        int idx = B[k]; // 得知比A[k]小的數字有幾個
        A[k] = L[idx];  // 得到A[k]

        for (int i = idx; i < len - 1; ++i)
        {
            L[i] = L[i + 1];
        } // 移除用過的數字
        len--;
    }
    delete[] L;
    return A;
}

int main()
{
    int N;
    cin >> N;
    cin.ignore();
    for (int testCase = 0; testCase < N; ++testCase)
    {
        char code;
        int size;
        cin >> code >> size;
        int *data = new int[size];
        for (int i = 0; i < size; ++i)
            cin >> data[i];
        int *result = nullptr; // 先初始化以免出錯
        if (code == 'A')
            result = findInvArr(data, size);
        else if (code == 'B')
            result = findPermArr(data, size);

        for (int i = 0; i < size; ++i)
        {
            cout << result[i];
            if (i != size - 1)
                cout << " "; // 依題目要求的格式輸出
        }
        cout << endl;
        delete[] data;
        delete[] result;
    }
    return 0;
}