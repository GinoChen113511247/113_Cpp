#include <iostream>
using namespace std;

int main()
{
  int a, b, borrow;
  cin >> a >> b;
    while (b != 0)
  {
    borrow = (~a) & b;
    a = a ^ b;
    b = borrow << 1; 
  }
  cout << a;
  return 0;
}