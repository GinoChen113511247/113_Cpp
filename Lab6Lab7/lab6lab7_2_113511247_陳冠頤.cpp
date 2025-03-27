#include <iostream>
#include <iomanip>
using namespace std;

double factorial (int);
int main()
{
    int a, b;
    cin >> a >> b;
    if (a>15 || a<1 || b>15 || b<1)
       return 1;
    int c=a+b;
    double part1=factorial(c);
    double part2=factorial(a)*factorial(b); //高中排列組合走捷徑問題
    cout << setprecision(10) << part1/part2; //避免使用科學記號表示太大的數
    return 0;
}

double factorial (int x) //階乘函數
{
    double n=1;
    for (int i=1;i<=x;i++)
    {
      n*=i;
    }
    return n;
}