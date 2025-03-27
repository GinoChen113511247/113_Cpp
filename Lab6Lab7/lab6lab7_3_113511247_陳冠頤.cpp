#include <iostream> 
using namespace std;

long long modular(int x, long long y, int m) 
{
    long long result=1;
    x=x%m; //避免x太大導致電腦當掉
    while (y>0) 
    {
        if (y%2==1) 
        {
            result=(result*x)%m;
        }//把一個x丟到mod外面去(mod的分配律)
        y=y/2; 
        x=(x*x)%m;
    } //快速冪算法&mod的性質
    return result;
}

int main() 
{
    int x, m;
    long long y;
    cin >> x >> y >> m;
    if (m<=0)
      return 1;
    cout << modular(x, y, m) << endl;
    return 0;
}