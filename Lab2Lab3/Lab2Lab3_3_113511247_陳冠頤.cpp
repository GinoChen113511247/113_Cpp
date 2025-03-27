#include <iostream>
#include <iomanip> //有用到fixed和setprecision
using namespace std;

int main ()
{
    int midterm, final, homework;
    float  weightedscore; //會有小數點

    cin >> midterm >> final >> homework;

    weightedscore = midterm*0.3 + final*0.5 + homework*0.2;

    if (midterm >= 0 && midterm <= 100 && final >= 0 && final <= 100 && homework >= 0 && homework <= 100) //判斷輸入的數值是否符合規範
    {
      if (weightedscore >= 80)
        cout << fixed << setprecision(1) << weightedscore << endl << "A"; //用fixed和setprecision(1)限制輸出格式
      else if (weightedscore < 80 && weightedscore >= 70) //判斷weightedscore在哪個區間並執行相對應的命令
        cout << fixed << setprecision(1) << weightedscore << endl << "B";
      else if (weightedscore < 70 && weightedscore >= 60)
        cout << fixed << setprecision(1) << weightedscore << endl << "C";
      else if (weightedscore < 60)
        cout << fixed << setprecision(1) << weightedscore << endl << "F";
    }
    else 
    {
      cout << "There is an error in one or more scores.";
    }
    return 0;
}