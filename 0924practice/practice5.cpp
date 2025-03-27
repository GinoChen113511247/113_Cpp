#include <iostream>
#include <string>
using namespace std;

 int main ()
 {
   string input;
   cin >> input;
   size_t position1=input.find('{');
   size_t position2=input.find('}');
   size_t position3=input.find('[');
   size_t position4=input.find(']');
   size_t position5=input.find('(');
   size_t position6=input.find(')');

   if (position1!=0 && position2!=0 && position3!=0 
        && position4!=0 && position5!=0 && position6!=0 )
     cout << "It's valid.";
   else 
     cout << "It's invalid.";

    return 0;
 }