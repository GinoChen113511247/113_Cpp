#include <iostream>
//#include <iomanip>
using namespace std;

void printUpperPart(int);
void printDownPart(int);
int main()
{
    int height;
    cin >> height;
    printUpperPart(height);
    printDownPart(height);
    return 0;
}

void printUpperPart(int height)
{
    for (int i=1;i<=height;i++)
    {
        for (int j=i;j<height;j++)
        {
            cout << " ";
        }
        int r=height-i+1;
        for (int k=1;k<=(2*i-1);k++)
        {
            cout << r ;
            r++;
        }
        cout << endl;
    }
}
void printDownPart(int height)
{
    for (int i=height-1;i>0;i--)
    {
        for (int j=i;j<height;j++)
        {
            cout << " ";
        }
        int r=height-i+1;
        for (int k=1;k<=(2*i-1);k++)
        {
            cout << r ;
            r++;
        }
        cout << endl;
    }
}
