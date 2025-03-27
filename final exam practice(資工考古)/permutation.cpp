#include <iostream>
#include <string>

using namespace std;

int main()
{
    int size;
    cin >> size;
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    int a=0, b=1, c=2;
    while (a<size-2)
    {
        while (b<size-1)
        {
            while (c<size)
            {
                cout << arr[a] << " " << arr[b] << " " << arr[c] << endl;
                c++;
            }
            b++;
            c=b+1;
        }
        a++;
        b=a+1;
        c=b+1;
    }
    delete [] arr;
    return 0;
}
