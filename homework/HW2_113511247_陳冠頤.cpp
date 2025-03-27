#include <iostream>
using namespace std;

int main()
{
  int a, b, carry;
  cin >> a >> b;
    while (b != 0)
  {
    carry = a & b; //計算carry
    a = a ^ b; //先加起來，不考慮進位
    b = carry << 1; //左移一位以進位
  }
  cout << a;
  return 0;
}