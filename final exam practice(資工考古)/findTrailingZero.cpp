#include <iostream>
using namespace std;

int main(void)
{
    int N, num5 = 0, x = 0, fix = 0;
    cin >> N;
    for (int i = 2; i <= N; i++)
    {
        if (i % 5 == 0)
            num5++;
    }

    while (N > 4)
    {
        x++;
        N /= 5;
    }
    for (int i = 1; i < x; i++)
        fix += i;

    cout << num5 + fix;
    return 0;
}