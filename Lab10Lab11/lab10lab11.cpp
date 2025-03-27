#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
    char* input=new char[100];
    cin.getline(input, 100);
    int length=strlen(input), count=0;
    for (int i=0;i<length;i++)
    {
        if(input[i]>='a' && input[i]<='z')
        {
            input[i]-=32;
        }
    }
    for (int j=0;j<length;j++)
    {
        cout << input[j];
    } 
    cout << endl;
    for (int k=length-1;k>-1;k--)
    {
        cout << input[k];
    }
    cout << endl;
    for (int l=0;l<length;l++)
    {
        if (input[l]=='A' || input[l]=='E' || input[l]=='I' || input[l]=='O' || input[l]=='U')
           count++;
    }
    cout << count;
    delete [] input;
    return 0;
}