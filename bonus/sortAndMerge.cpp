#include <iostream>
using namespace std;

int compare(const void*, const void*);

int main(void)
{
    int m, n;
    cin >> m >> n;
    int num1[m+n]={0};
    for (int i=0;i<m;i++)
        cin >> num1[i];
    int num2[n];
    for (int i=0;i<n;i++)
        cin >> num2[i];
    for (int j=0;j<n;j++)
        num1[m+j]=num2[j];
    qsort(num1, m+n, sizeof(int), compare);
    for (int k=0;k<m+n;k++)
        cout << num1[k] << " ";
    return 0;
}

int compare(const void* a, const void* b)
{
    return (*(int*)a-*(int*)b);
}