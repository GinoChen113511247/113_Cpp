#include <iostream>
#include <cmath>
using namespace std;

int f(int x)
{
    if (x == 1)
        return 1;
    else
        return x * sqrt(1 + f(x - 1));
}
int main(void)
{
    int n;
    cin >> n;
    cout << f(n);
    return 0;
}