#include <iostream>
using namespace std;

int MEX(int *arr, int);

int main(void)
{
    int times;
    cin >> times;
    for (int i=0;i<times;i++)
    {
        int size;
        int sum=0;
        cin >> size;
        int *arr = new int[size];
        for (int j=0;j<size;j++)
            cin >> arr[j];
        for (int i=1;i<=size;i++)
            sum += MEX(arr, i);
        cout << sum << endl;
        delete [] arr;
    }
    return 0;
}

int MEX(int *arr, int n)
{
    int size=n-1;
    
}