#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int count=0;
    for (int i=1;i<=n;i++)
    {
        if (n%i==0)
        {
          cout << i <<" ";
          for (int j=1;j<=i;j++)
          {
            if (i%j==0)
              count ++;
          }
          if (count==2)
              cout << "(prime) ";
          count=0;
        }
    }
  return 0;
}