#include <iostream>
using namespace std;

int main ()
{
    int input;
    cin >> input;
    int f0=0, f1=1;
    cout << f0 << ", " << f1 << ", ";
    for (int i=3;i<=input;i++)
    {
       int f2=f0+f1;
       cout << f2 << ", ";
       f0=f1;
       f1=f2;
    }
}