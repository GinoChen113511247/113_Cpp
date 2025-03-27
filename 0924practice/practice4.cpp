#include <iostream>
#include <string>
using namespace std;

int main()
{
    string number;
    cin >> number;
    int length = number.size();
    if (length==1)
    {
      if (number[0]=='I')             cout << "1";
      else if (number[0]=='V')        cout << "5";
      else if (number[0]=='X')        cout << "10";
      else if (number[0]=='L')        cout << "50";
      else if (number[0]=='C')        cout << "100";
      else if (number[0]=='D')        cout << "500";
      else if (number[0]=='M')        cout << "1000";        
    }
    else
    {
      int num1, num2;
      if (number[0]=='I')             num1=1;
      else if (number[0]=='V')        num1=5;
      else if (number[0]=='X')        num1=10;
      else if (number[0]=='L')        num1=50;
      else if (number[0]=='C')        num1=100;
      else if (number[0]=='D')        num1=500;
      else if (number[0]=='M')        num1=1000;

      if (number[1]=='I')             num2=1;
      else if (number[1]=='V')        num2=5;
      else if (number[1]=='X')        num2=10;
      else if (number[1]=='L')        num2=50;
      else if (number[1]=='C')        num2=100;
      else if (number[1]=='D')        num2=500;
      else if (number[1]=='M')        num2=1000;

      if (num1>=num2)
        cout << num1+num2;
      else
        cout << num2-num1;
    }

  return 0;
}