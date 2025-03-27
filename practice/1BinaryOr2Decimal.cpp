#include <iostream>
#include <cmath>
using namespace std;

void decimalToBinary(int);
void binaryToDecimal(string);

int main()
{
   int choice;
   cin >> choice;
   if (choice == 1)
   {
      int input;
      cin >> input;
      decimalToBinary(input);
   }
   else
   {
      string input;
      cin >> input;
      binaryToDecimal(input);
   }
   return 0;
}

void decimalToBinary(int input)
{
   int n = input;
   int count = 0;
   while (n >= 2)
   {
      n = n / 2;
      count++;
   }
   for (int i = count; i >= 0; i--)
   {
      if (input - pow(2, i) >= 0)
      {
         cout << "1";
         input = input - pow(2, i);
      }
      else
         cout << "0";
   }
   cout << "(binary)";
}

void binaryToDecimal(string input)
{
   int sum = 0;
   int n;
   for (int i = 0; i < input.size(); i++)
   {
      int x = input.size() - i - 1;
      if (input[i] == '1')
         n = (int)(pow(2, x));
      else
         n = 0;
      sum += n;
   }
   cout << sum << "(decimal)";
}