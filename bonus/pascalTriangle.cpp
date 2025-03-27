#include <iostream>
using namespace std;

int main(void)
{
    int height;
    cin >> height;
    int elements[100]={0};
    elements[0]=1;
    for (int i=0;i<height;i++)
    {
        for (int j=height-1;j>i;j--)
            cout << " ";
        if (i>1)
        {
            for (int k=i-1;k>0;k--)
                elements[k]+=elements[k-1];
        }
        elements[i]=1;
        for (int l=0;l<=i;l++)
            cout << " " << elements[l];
        cout << " " << endl;
    }
    return 0;
}