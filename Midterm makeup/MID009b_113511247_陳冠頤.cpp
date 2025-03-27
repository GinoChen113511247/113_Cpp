#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cin >> n;
    double part1, part2=0;
    if(n<0)
      cout << "Incorrect Input(s)!"; 
    else
    {
      for (int i=0;i<n;i++)
      {
        part1=pow((2*(n-1-i)+1), 2)/(7.0+part2); 
        part2=part1;
      }//考試時有大概想出來但不確定對錯，所以就去通分導致花了太多時間
      cout << fixed  << setprecision(3) << part1+5;
    }   
}