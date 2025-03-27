#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int input;
    int n;
    int sum=0;
    cin >> input;
    for (int i=1;i<=input;i++)
    {
      n=pow(i, 3);
      sum+=n;
    }
    cout << sum;
}