#include <iostream>
using namespace std;

void payAmount(int&, int&);

int main()
{
    int input, count=-1;
    cin >> input;
    if (input<0 || input>2147483647)
       return 1;
   payAmount(input, count);
    cout << "Total number of bills/coins used: " << count;
    return 0;
}

void payAmount(int& a, int& count)
{
   count+=1;
   if (a>=1000)
   {
      cout << 1000 << endl;
      a-=1000;
      payAmount(a, count);
   }

   if (a<1000 && a>=500)
   {
      cout << 500 << endl;
      a-=500;
      payAmount(a, count);
   }

   if (a<500 && a>=100)
   {
      cout << 100 << endl;
      a-=100;
      payAmount(a, count);
   }

   if (a<100 && a>=50)
   {
      cout << 50 << endl;
      a-=50;
      payAmount(a, count);
   }

   if (a<50 && a>=10)
   {
      cout << 10 << endl;
      a-=10;
      payAmount(a, count);
   }

   if (a<10 && a>=5)
   {
      cout << 5 << endl;
      a-=5;
      payAmount(a, count);
   }

   if (a<5 && a>=1)
   {
      cout << 1 << endl;
      a-=1;
      payAmount(a, count);
   }
}