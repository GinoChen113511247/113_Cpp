#include <iostream>
#include <cmath> 
using namespace std;

int main()
{
  int date; //把日期視為一個數字
  cin >> date;
  int year, month, day;
  day = date % 100;
  month = ((date % 10000)-day)/100; //從日期算出年月日
  year = date / 10000;

  int x;
  x = (int)(year+ floor((year-1)/4)- floor((year-1)/100)+ floor((year-1)/400)) % 7; //該年1/1是星期幾。floor運算出來是double，要強制轉為int

  int y;
  if ((year%4 == 0 && year%100 != 0) || (year%400 == 0)) //判斷是否為閏年
  {
    switch (month) //算1/1到任意月份的1號要經過多少天(閏年的情況)
    {
      case 1: y=0;
        break;
      case 2: y=31;
        break;
      case 3: y=(31+29);
        break;
      case 4: y=(31+29+31);
        break;
      case 5: y=(31+29+31+30);
        break;
      case 6: y=(31+29+31+30+31);
        break;
      case 7: y=(31+29+31+30+31+30);
        break;
      case 8: y=(31+29+31+30+31+30+31);
        break;
      case 9: y=(31+29+31+30+31+30+31+31);
        break;
      case 10: y=(31+29+31+30+31+30+31+31+30);
        break;
      case 11: y=(31+29+31+30+31+30+31+31+30+31);
        break;
      case 12: y=(31+29+31+30+31+30+31+31+30+31+30);
        break; 
    }
  }
  else 
  {
    switch (month) //算1/1到任意月份的1號要經過多少天(不是閏年的情況)
    {
      case 1: y=0;
        break;
      case 2: y=31;
        break;
      case 3: y=(31+28);
        break;
      case 4: y=(31+28+31);
        break;
      case 5: y=(31+28+31+30);
        break;
      case 6: y=(31+28+31+30+31);
        break;
      case 7: y=(31+28+31+30+31+30);
        break;
      case 8: y=(31+28+31+30+31+30+31);
        break;
      case 9: y=(31+28+31+30+31+30+31+31);
        break;
      case 10: y=(31+28+31+30+31+30+31+31+30);
        break;
      case 11: y=(31+28+31+30+31+30+31+31+30+31);
        break;
      case 12: y=(31+28+31+30+31+30+31+31+30+31+30);
        break; 
    }
  }
  int n;
  n = (x+y+day-1) % 7; //算出輸入的日期離該年的1/1過了多少天並mod 7後得到答案(注意要減1)
  switch(n) //由n值輸出最終答案
  {
    case 0: cout << "Sunday";
      break;
    case 1: cout << "Monday";
      break;
    case 2: cout << "Tuesday";
      break;
    case 3: cout << "Wednesday";
      break;
    case 4: cout << "Thursday";
      break;
    case 5: cout << "Friday";
      break;
    case 6: cout << "Saturday";
      break;
  }
  return 0;
}