#include <iostream>
using namespace std;

int main()
{
    double input;
    cin >> input;
    double t=input-(int)input;
    double p=input-input/1;
    cout << t << " vs. " << p;
    return 0;
}