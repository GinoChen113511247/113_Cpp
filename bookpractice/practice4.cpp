#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int i=1;
    int n;
    int sum=0;
    while (i<=20)
    {
      if (i%2==0)
      {
        cout << i <<"_";
        n=pow(i, 2);
        sum+=n;
      }
      i++;
    }
    cout << endl << sum;
    return 0;
}