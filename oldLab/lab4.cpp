#include <iostream>
#define swap(a, b) ((a)^=(b), (b)^=(a), (a)^=(b))
using namespace std;

void rearrange(int &a, int &b, int &c, int &d)
{
    if (a<b)    swap(a,b);
    if (a<c)    swap(a,c);
    if (a<d)    swap(a,d);
    if (b<c)    swap(b,c);
    if (b<d)    swap(b,d);
    if (c<d)    swap(c,d);
}

int main() 
{
  int input;
  cin >> input;
  int a, b, c, d;
  int times=0;
  if (input == 1111 || input == 2222 || input == 3333 || 
        input == 4444 || input == 5555 || input == 6666 || 
        input == 7777 || input == 8888 || input == 9999)
  {
    cout << "Escape"<< endl;
    return 0;
  }
  while(input!=6174)
  {
    a=input/1000;
    b=(input/100)%10;
    c=(input/10)%10;
    d=input%10;
    rearrange(a, b, c, d);
    int maxium=a*1000+b*100+c*10+d;
    int minimum=d*1000+c*100+b*10+a;
    input=maxium-minimum;
    cout << input << endl;
    times ++;
  }
  cout << "Reached Kaprekar's constant 6174 in " << times << " steps!";
  return 0;
} 