#include <iostream>
using namespace std;

int main(void)
{
    struct distance
    {
        int feet = 0;
        int inch = 0;
    };
    distance d1, d2, sum;
    cout << "Enter first distance in feet & inches" << endl;
    cin >> d1.feet >> d1.inch;
    cout << "Enter second distance in feet & inches" << endl;
    cin >> d2.feet >> d2.inch;
    sum.inch = (d1.inch + d2.inch) % 12;
    sum.feet = (d1.feet + d2.feet) + (d1.inch + d2.inch) / 12;
    cout << "Total distance - " << "Feet: " << sum.feet << "," << "Inches:" << sum.inch << endl;
    return 0;
}