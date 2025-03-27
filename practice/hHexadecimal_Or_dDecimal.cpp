#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

void decimalToHexadecimal (double);
void hexadecimalToDecimal (string);

int main ()
{
    char choice;
    cin >> choice;
    if (choice=='h')
    {
       double input;
       cin >> input;
       decimalToHexadecimal(input);
    }
    else if (choice=='d')
    {
       string input;
       cin >> input;
       hexadecimalToDecimal(input);
    }
    return 0;
}

void decimalToHexadecimal(double input)
{
    double input2=input;
    int n=(int)input;
    int count=0;
    while (n>=16)
    {
       n=n/16;
       count++; 
    }
    for (int i=count;i>=0;i--)
    {
        int t=(int)(input/pow(16, i));
        switch (t)
        {
          case 0:  cout << "0"; break;
          case 1:  cout << "1"; break;
          case 2:  cout << "2"; break;
          case 3:  cout << "3"; break;
          case 4:  cout << "4"; break;
          case 5:  cout << "5"; break;
          case 6:  cout << "6"; break;
          case 7:  cout << "7"; break;
          case 8:  cout << "8"; break;
          case 9:  cout << "9"; break;
          case 10:  cout << "A"; break;
          case 11:  cout << "B"; break;
          case 12:  cout << "C"; break;
          case 13:  cout << "D"; break;
          case 14:  cout << "E"; break;
          case 15:  cout << "F"; break;
        }
        input=(int)(input-pow(16, i)*t);
    }
    cout << ".";
    double p=input2-(int)input2;
    for (int i=0;i<15;i++)
    {   
        p*=16;
        int x=(int)p;
        switch (x)
        {
          case 0:  cout << "0"; break;
          case 1:  cout << "1"; break;
          case 2:  cout << "2"; break;
          case 3:  cout << "3"; break;
          case 4:  cout << "4"; break;
          case 5:  cout << "5"; break;
          case 6:  cout << "6"; break;
          case 7:  cout << "7"; break;
          case 8:  cout << "8"; break;
          case 9:  cout << "9"; break;
          case 10:  cout << "A"; break;
          case 11:  cout << "B"; break;
          case 12:  cout << "C"; break;
          case 13:  cout << "D"; break;
          case 14:  cout << "E"; break;
          case 15:  cout << "F"; break;
        }
        p-=x;
    }
    cout << "(hexadecimal)";
}

void hexadecimalToDecimal(string input)
{
    int sum1=0;
    double sum2=0;
    int n1;
    double n2;
    size_t position=input.find('.');
    if (position!=std::string::npos)
    {
      for (int i=0;i<position;i++)
      {
       int x=position-i-1;
       switch(input[i])
       {
         case '0': n1=0; break;
         case '1': n1=(int)(1*pow(16, x)); break;
         case '2': n1=(int)(2*pow(16, x)); break;
         case '3': n1=(int)(3*pow(16, x)); break;
         case '4': n1=(int)(4*pow(16, x)); break;
         case '5': n1=(int)(5*pow(16, x)); break;
         case '6': n1=(int)(6*pow(16, x)); break;
         case '7': n1=(int)(7*pow(16, x)); break;
         case '8': n1=(int)(8*pow(16, x)); break;
         case '9': n1=(int)(9*pow(16, x)); break;
         case 'A': n1=(int)(10*pow(16, x)); break;
         case 'B': n1=(int)(11*pow(16, x)); break;
         case 'C': n1=(int)(12*pow(16, x)); break;
         case 'D': n1=(int)(13*pow(16, x)); break;
         case 'E': n1=(int)(14*pow(16, x)); break;
         case 'F': n1=(int)(15*pow(16, x)); break;
       }
       sum1+=n1;
      }
      for (int i=position+1;i<input.length();i++)
      {
       int x=position-i;
       switch(input[i])
       {
         case '0': n2=0; break;
         case '1': n2=(1*pow(16, x)); break;
         case '2': n2=(2*pow(16, x)); break;
         case '3': n2=(3*pow(16, x)); break;
         case '4': n2=(4*pow(16, x)); break;
         case '5': n2=(5*pow(16, x)); break;
         case '6': n2=(6*pow(16, x)); break;
         case '7': n2=(7*pow(16, x)); break;
         case '8': n2=(8*pow(16, x)); break;
         case '9': n2=(9*pow(16, x)); break;
         case 'A': n2=(10*pow(16, x)); break;
         case 'B': n2=(11*pow(16, x)); break;
         case 'C': n2=(12*pow(16, x)); break;
         case 'D': n2=(13*pow(16, x)); break;
         case 'E': n2=(14*pow(16, x)); break;
         case 'F': n2=(15*pow(16, x)); break;
       }
      sum2+=n2;
      }
     cout << fixed << setprecision(15) << (double)sum1+sum2 << "(decimal)";
    }
    else
    {
      for (int i=0;i<input.length();i++)
      {
       int x=input.length()-i-1;
       switch(input[i])
       {
         case '0': n1=0; break;
         case '1': n1=(int)(1*pow(16, x)); break;
         case '2': n1=(int)(2*pow(16, x)); break;
         case '3': n1=(int)(3*pow(16, x)); break;
         case '4': n1=(int)(4*pow(16, x)); break;
         case '5': n1=(int)(5*pow(16, x)); break;
         case '6': n1=(int)(6*pow(16, x)); break;
         case '7': n1=(int)(7*pow(16, x)); break;
         case '8': n1=(int)(8*pow(16, x)); break;
         case '9': n1=(int)(9*pow(16, x)); break;
         case 'A': n1=(int)(10*pow(16, x)); break;
         case 'B': n1=(int)(11*pow(16, x)); break;
         case 'C': n1=(int)(12*pow(16, x)); break;
         case 'D': n1=(int)(13*pow(16, x)); break;
         case 'E': n1=(int)(14*pow(16, x)); break;
         case 'F': n1=(int)(15*pow(16, x)); break;
       }
       sum1+=n1;
      }
      cout << sum1 << "(decimal)";
    }
}