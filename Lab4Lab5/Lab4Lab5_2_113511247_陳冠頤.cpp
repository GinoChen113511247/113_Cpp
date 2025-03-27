#include <iostream>
#include <cmath> 
#include <iomanip>  
using namespace std;

void printWeekCalendar(int year, int month, int day)
{
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

  cout << "Sun Mon Tue Wed Thu Fri Sat" << endl;

  int n;
  n = (x+y+day-1) % 7; //算出輸入的日期離該年的1/1過了多少天並mod 7後得到答案(注意要減1)

  int startday;
  int i;

  //決定星期天是哪一天
  if( (day-n) <= 0 )
  {
   switch (month) 
    {
      case 5: //前一個月是小月
      case 7:
      case 10:
      case 12:
                startday= day-n+30;  
                for (i = 0; i < 7; i++) 
                {   // 輸出一周七天
                  cout << setw(2) << startday++ << "  ";  //setw(2) 設定2 個字元寬度
                  if( startday >30 )
                    startday = 1;
                } 
                cout << endl;
                break;
      case 1 : //前一個月是大月
      case 2 :   
      case 4 :         
      case 6 :
      case 8 :
      case 9 :
      case 11 :
                startday= day-n+31;
                for (i = 0; i < 7; i++) 
                {   // 輸出一周七天
                  cout << setw(2) << startday++ << "  ";  //setw(2) 設定2 個字元寬度
                  if( startday > 31 )
                    startday = 1;
                } 
                cout << endl;  
                break; 
      case 3 :
               if((year%4 == 0 && year%100 != 0) || (year%400 == 0)) //判斷是否為閏年
                { 
                  startday= day-n+29; //閏年
                  for (i = 0; i < 7; i++) 
                  {   // 輸出一周七天
                    cout << setw(2) << startday++ << "  ";  //setw(2) 設定2 個字元寬度
                    if( startday > 29 )  
                      startday = 1;
                  } 
                  cout << endl;
                }
                else
                { 
                  startday= day-n+28; 
                   for (i = 0; i < 7; i++) 
                   {   // 輸出一周七天
                    cout << setw(2) << startday++ << "  ";  //setw(2) 設定2 個字元寬度
                    if( startday > 28 )  
                      startday = 1;
                   } 
                  cout << endl;
                }
              break;  
    }
  }
  else
  {
   switch (month) 
    {
      case 1 : //是大月
      case 3 :   
      case 5 :         
      case 7 :
      case 8 :
      case 10 :
	    case 12 :
                startday= day-n;  
                for (i = 0; i < 7; i++) 
                {   // 輸出一周七天
                  cout << setw(2) << startday++ << "  ";  //setw(2) 設定2 個字元寬度
                  if( startday >31 )
                    startday = 1;
                } 
                cout << endl;
                break;
      case 4 : //小月
      case 6 :     
      case 9 :
      case 11 :
                startday= day-n;
                for (i = 0; i < 7; i++) 
                {   // 輸出一周七天
                  cout << setw(2) << startday++ << "  ";  //setw(2) 設定2 個字元寬度
                  if( startday > 30 )
                    startday = 1;
                } 
                cout << endl;  
                break; 
      case 2 : if((year%4 == 0 && year%100 != 0) || (year%400 == 0)) //判斷是否為閏年
                { 
                  startday= day-n; //閏年
                  for (i = 0; i < 7; i++) 
                  {   // 輸出一周七天
                    cout << setw(2) << startday++ << "  ";  //setw(2) 設定2 個字元寬度
                    if( startday > 29 )  
                      startday = 1;
                  } 
                  cout << endl;
                }
                else
                { 
                  startday= day-n; 
                   for (i = 0; i < 7; i++) 
                  {   // 輸出一周七天
                    cout << setw(2) << startday++ << "  ";  //setw(2) 設定2 個字元寬度
                    if( startday > 28 )  
                      startday = 1;
                  } 
                  cout << endl;
                }
              break;    
    }
   }
  }

int main() 
{
  int date; 
  cin >> date;
  int year, month, day;
  day = date % 100;
  month = ((date % 10000)-day)/100; 
  year = date / 10000;
  printWeekCalendar(year, month, day);
  return 0;
}