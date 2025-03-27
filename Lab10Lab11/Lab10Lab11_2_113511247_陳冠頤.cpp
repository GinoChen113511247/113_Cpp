#include <iostream>
using namespace std;

int isPalindrome(string);
int isMirrored(string);

int main(void)
{
   string input;
   cin >> input;
   int x = isPalindrome(input);
   int y = isMirrored(input);
   if (x == 0 && y == 0) // 1代表是，0代表不是
      cout << input << " -- is not a palindrome.";
   else if (x == 1 && y == 0)
      cout << input << " -- is a regular palindrome.";
   else if (x == 0 && y == 1)
      cout << input << " -- is a mirrored string.";
   else if (x == 1 && y == 1)
      cout << input << " -- is a mirrored palindrome.";
   return 0;
}

int isPalindrome(string a)
{
   int length = a.length();
   int result = 1;
   for (int i = 0; i < length / 2; i++)
   {
      if (a[i] != a[length - i - 1]) // 首尾一組檢查
      {
         result = 0;
         break;
      }
   }
   return result;
}

int isMirrored(string b)
{
   int length = b.length();
   int t = length / 2;
   int result = 1;
   for (int i = 0; i < length; i++) // 檢查有沒有不能鏡像的字元
   {
      if (b[i] != 'A' && b[i] != 'E' && b[i] != 'H' && b[i] != 'I' && b[i] != 'J' && b[i] != 'M' &&
          b[i] != 'O' && b[i] != 'S' && b[i] != 'T' && b[i] != 'U' && b[i] != 'V' && b[i] != 'W' &&
          b[i] != 'X' && b[i] != 'Y' && b[i] != 'Z' && b[i] != '1' && b[i] != '8' && b[i] != '3' &&
          b[i] != 'L' && b[i] != '2' && b[i] != '5')
      {
         result = 0;
         break;
      }
   }
   for (int i = 0; i < length / 2; i++) // 首尾一組檢查是否為對應的鏡像字元
   {
      if ((b[i] == '3' && b[length - 1 - i] != 'E') || (b[i] == 'E' && b[length - 1 - i] != '3'))
      {
         result = 0;
         break;
      }
      if ((b[i] == 'J' && b[length - 1 - i] != 'L') || (b[i] == 'L' && b[length - 1 - i] != 'J'))
      {
         result = 0;
         break;
      }
      if ((b[i] == '2' && b[length - 1 - i] != 'S') || (b[i] == 'S' && b[length - 1 - i] != '2'))
      {
         result = 0;
         break;
      }
      if ((b[i] == '5' && b[length - 1 - i] != 'Z') || (b[i] == 'Z' && b[length - 1 - i] != '5'))
      {
         result = 0;
         break;
      }
   }
   if (length % 2 == 1) // 字元長度是奇數的話還要檢查字元和其對應的鏡像是否一樣
   {
      if (b[t] == '3' || b[t] == 'J' || b[t] == '2' || b[t] == '5' || b[t] == 'E' || b[t] == 'L' ||
          b[t] == 'S' || b[t] == 'Z')
         result = 0;
   }
   return result;
}