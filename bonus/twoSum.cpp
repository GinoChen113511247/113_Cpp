#include <iostream>
using namespace std;

int main(void)
{
    int size, target;
    cin >> size;
    int input[size];
    for (int i=0;i<size;i++)
        cin >> input[i];
    cin >> target;
    for (int i=0;i<size;i++)
    {
        for (int j=i+1;j<size;j++)
        {
            if (input[j]==target-input[i])
            {
                cout << i << " " << j;
                break;
            }
        }
    }
    return 0;
}