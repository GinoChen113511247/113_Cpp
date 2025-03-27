//考試時想說先拿十二分所以只寫了交換四位數的程式
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

//void swap(string, string);

int main()
{
    string input, n;
    cin >> input;
    double sum1=0, sum2=0;
    double x, y;

    bool check_int=0; //檢查input裡有沒有什麼怪東西
    for(int i=0;i<input.length();++i) 
    {
        check_int=isdigit(input.at(i));
        if (check_int == 0) break;
    }

    for (int j=0;j<input.length();j++)  
      {
        switch (input[j])
        {
          case '0': x=0; break;
          case '1': x=1*pow(10, input.length()-1-j); break;
          case '2': x=2*pow(10, input.length()-1-j); break;
          case '3': x=3*pow(10, input.length()-1-j); break;
          case '4': x=4*pow(10, input.length()-1-j); break;
          case '5': x=5*pow(10, input.length()-1-j); break;
          case '6': x=6*pow(10, input.length()-1-j); break;
          case '7': x=7*pow(10, input.length()-1-j); break;
          case '8': x=8*pow(10, input.length()-1-j); break;
          case '9': x=9*pow(10, input.length()-1-j); break;
        }
        sum1+=x;
      } //把input轉換成整數以檢查有沒有在所給範圍內
    

    if (check_int==0 || sum1>pow(2, 31)-1)
      cout << "Incorrect Input(s)!";
    else
    {
      for (int i=0;i<input.length()/2;i++)
      {
        swap(input[i], input[input.length()-1-i]);
      }
      for (int j=0;j<input.length();j++)
      {
        switch (input[j])
        {
          case '0': y=0; break;
          case '1': y=1*pow(10, input.length()-1-j); break;
          case '2': y=2*pow(10, input.length()-1-j); break;
          case '3': y=3*pow(10, input.length()-1-j); break;
          case '4': y=4*pow(10, input.length()-1-j); break;
          case '5': y=5*pow(10, input.length()-1-j); break;
          case '6': y=6*pow(10, input.length()-1-j); break;
          case '7': y=7*pow(10, input.length()-1-j); break;
          case '8': y=8*pow(10, input.length()-1-j); break;
          case '9': y=9*pow(10, input.length()-1-j); break;
        }
        sum2+=y;
      }
      cout << setprecision(input.length()) << sum2;
    }
    return 0;
}

/*void swap(string x, string y)
{
    string tmp=x;
    x=y;
    y=tmp;
} */