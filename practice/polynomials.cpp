#include <iostream>
using namespace std;

struct terms
{
    int coeff = 0;
    int expo = 0;
};

int isExist(terms poly[], int expo, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (poly[i].expo == expo)
            return i;
    }
    return -1;
}

int main(void)
{
    int coeff, expo, size = 0;
    terms poly[100];

    // 讀取第一組多項式
    while (true)
    {
        cin >> coeff >> expo;
        if (expo == -1)
            break;
        poly[size].coeff = coeff;
        poly[size].expo = expo;
        size++;
    }

    // 讀取第二組多項式並相加
    while (true)
    {
        cin >> coeff >> expo;
        if (expo == -1)
            break;
        int x = isExist(poly, expo, size);
        if (x != -1)
        {
            // 已存在相同次方
            poly[x].coeff += coeff;
        }
        else
        {
            // 尋找正確的插入點（假設多項式依照次方由大到小排序）
            int insertPos = size; // 若找不到更高的次方，預設插到末尾
            for (int i = 0; i < size; i++)
            {
                if (poly[i].expo < expo)
                {
                    insertPos = i;
                    break; // 找到應插入的位置就中斷
                }
            }

            // 將插入位置之後的項目往後移一格
            for (int i = size - 1; i >= insertPos; i--)
            {
                poly[i + 1] = poly[i];
            }

            // 插入新項
            poly[insertPos].coeff = coeff;
            poly[insertPos].expo = expo;
            size++;
        }
    }

    cout << "Resulting Polynomial after Addition: ";

    // 若 size == 0，表示沒有任何項目，即為0多項式
    if (size == 0)
    {
        cout << "0" << endl;
        return 0;
    }

    // 輸出多項式的第一項
    cout << poly[0].coeff;
    if (poly[0].expo != 0)
        cout << "x^" << poly[0].expo;

    // 從第二項開始輸出
    for (int i = 1; i < size; i++)
    {
        if (poly[i].coeff == 0)
            continue; // 若係數為0可選擇跳過（視需求定義）

        if (poly[i].coeff > 0)
            cout << " + " << poly[i].coeff;
        else
            cout << " - " << (-poly[i].coeff);

        if (poly[i].expo != 0)
            cout << "x^" << poly[i].expo;
    }
    cout << endl;

    return 0;
}
