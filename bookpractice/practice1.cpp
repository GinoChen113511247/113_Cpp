#include <iostream>
using namespace std;

int main()
{
    int input;
    cin >> input;
    for (int i=1;i<=input;i++)
    {
        if (i%18==0)
          cout << i <<"_";
    }
    return 0;
}