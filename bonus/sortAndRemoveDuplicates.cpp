#include <iostream>
using namespace std;

int compare(const void*, const void*);

int main(void)
{
    int size, i=1, a=0;
    cin >> size;
    int input[size];
    for (int i=0;i<size;i++)
        cin >> input[i];
    qsort(input, size, sizeof(int), compare);
    int answer[size]={0};
    answer[0]=input[0];
    while(i<size)
    {
        while (answer[a]==input[i] && i<size-1)
            i++;
        if (i<size)
        {
            a++;
            answer[a]=input[i];//輸入的最後一項一定會被輸進去answer裡
            i++;
        }
    }
    int b=0;
    if (answer[a-1]==answer[a])
        b=a;
    else
        b=a+1;//解決上述問題
    for(int i=0;i<b;i++)
        cout << answer[i] << " ";
    return 0;
}

int compare(const void* a, const void* b)
{
    return (*(int*)a-*(int*)b);
}