#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
    char* input=new char[100];
    cin.getline(input, 100);
    char* p1=strchr(input, '(');
    char* p2=strchr(input, ')');
    char* p3=strchr(input, '[');
    char* p4=strchr(input, ']');
    char* p5=strchr(input, '{');
    char* p6=strchr(input, '}');
    int checkpoint=1;
    if (p1==nullptr||p2==nullptr||p3==nullptr||p4==nullptr||p5==nullptr||p6==nullptr)
        checkpoint=0;
    else
    {
        if (p1>p2)    checkpoint=0;
        if (p3>p4)    checkpoint=0;
        if (p5>p6)    checkpoint=0;
    }
    if (checkpoint==1)
        cout << "The string is valid.";
    else
        cout << "The string is invalid.";
    delete [] input;
    return 0;
}