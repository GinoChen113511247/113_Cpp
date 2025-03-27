#include <iostream>
using namespace std;

void fillUp(int [], int);
int findTreasure(int [], int, int);

int main(void)
{
    int number, queue, target;
    while (cin >> number >> queue)//輸入EOF就可關掉
    {
        int a1[number], a2[queue];
        fillUp(a1, number);
        for (int i=0;i<queue;i++)
        {
            cin >> target;
            a2[i]=findTreasure(a1, number, target);
        }
        for (int k=0;k<queue;k++)
        {
            if (a2[k]!=(-2))//我定義-2為找不到對應的值
                cout << a2[k]+1 << endl;//題目規定第一個index為一
            else
                cout << "Break your bridge!" << endl;
        }
    }
    return 0;
}

void fillUp (int a[], int size)
{
   for (int idx=0;idx<size;idx++)
     cin >> a[idx];
}

int findTreasure(int a[], int size, int target)
{
    for (int j=0;j<size;j++)
    {
        if(a[j]==target)
        {
            return j;
        }
    }
    return -2;
}