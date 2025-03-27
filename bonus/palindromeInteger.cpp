#include <iostream>
using namespace std;

int main(void)
{
    int input, index=0, result=1;
    cin >> input;
    int bit[10];
    while(input>0)
    {
      bit[index]=input%10;
      input/=10;
      index++;
    }
    for (int i=0;i<index;i++)
    {
        if (bit[0]!=bit[index-1])
        {
            result=0;
            break;
        }
    }
    if (result==1)
        cout << "true";
    else
        cout << "false";
    return 0;
}