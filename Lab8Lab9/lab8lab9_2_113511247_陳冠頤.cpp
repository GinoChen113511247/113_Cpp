#include <iostream>
using namespace std;

void fillUp(int [], int);
int addTotal(int [], int, int);

int main(void)
{
    int p, q, i, f;
    cin >> p >> q;
    int t[p];
    int answer[q];//把答案儲存在陣列中再一起輸出
    fillUp(t, p);
    for (int j=0;j<q;j++)
    {
      cin >> i >> f;
      answer[j]=addTotal(t, i, f);
    }
    for (int l=0;l<q;l++)
    {
        cout << answer[l] << endl;
    }
    return 0;
}

void fillUp (int a[], int size)
{
   for (int idx=0;idx<size;idx++)
     cin >> a[idx];
}//把array1填滿

int addTotal(int b[], int initial, int final)
{
    int result=0;
    int x=initial;
    for (int k=0;k<=final-initial;k++)
    {
        result+=b[x-1];
        x++;
    }
    return result;
} //算總和