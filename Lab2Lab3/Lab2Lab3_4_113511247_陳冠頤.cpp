#include <iostream>
using namespace std;
int main()
{
  double cardnumber; //把卡號視為一個數字
  cin >> cardnumber;
  if (cardnumber >= 5.1e15 && cardnumber < 5.6e15) //把題目的限制用數字表達，判斷該卡號在哪個區間後執行相對應的命令
    cout << "MasterCard";
  else if (cardnumber >= 4e15 && cardnumber < 5e15)
    cout << "Visa";
  else if (cardnumber >= 3e15 && cardnumber < 4e15)
    cout << "JCB";
  else
    cout << "Unknown Card Type";
  return 0;
}