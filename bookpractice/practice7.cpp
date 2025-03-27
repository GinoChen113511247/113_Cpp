#include <iostream>
using namespace std;

int main()
{
    int input;
    int sum=0;
    cin >> input;
    int i=1;
    while (i<=input/2)
    {
       int n;
       n=2*i;
       sum+=n;
       i++;
    }
    cout << sum;
    return 0;
}