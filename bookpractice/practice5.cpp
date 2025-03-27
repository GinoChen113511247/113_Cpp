#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int input;
    cin >> input;
    for (int i=1;i<=input;i++)
    {
        for (int j=1;j<=input;j++)
        {
            cout << i << "*" << j << "=" << i*j << " ";
            if (i*j<10)
              cout << " ";
            if (j==input)
              cout << endl;
        }
    }
    return 0;
}