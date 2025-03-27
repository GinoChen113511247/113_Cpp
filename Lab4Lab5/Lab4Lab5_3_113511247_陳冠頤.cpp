#include <iostream>
#include <iomanip>
using namespace std;

void printHalfPyramid(int h) 
{
    int i,j;
    char ch;
    
    if ( h < 0 || h > 26) 
      return;
    ch = 'A'; // Start with 'A'
    for ( i = 1; i <= h; ++i)
     {     
        for ( j = 1; j < i; ++j) {
         cout << ch << " ";
           }
         cout << ch << endl; // last char add New line after each row   
        ch++; // Move to the next character
              
     }
    
}

void printFullPyramid(int h) {
    int i,j;

   if ( h < 0 || h > 26) 
      return;
    char ch = 'A'; // Start with 'A'
    for ( i = 1; i <= h; ++i) { 
        
        // Print leading spaces
        for ( j = i; j < h; ++j) {
            cout << "  ";
        }
        // Print  2*height-1 characters
        for ( j = 1; j < (2 * i - 1); ++j) { 
            cout << ch << " ";
           
        }
        cout << ch << endl; // last char add New line after each row 
        ch++;
    }
}



void printDiamond(int h) {

    int i,j;

   if ( h < 0 || h >13) 
      return;
    char ch = 'A'; // Start with 'A'
    // Print the upper part of the diamond
    for ( i = 1; i <= h; i++) {     
        // Print leading spaces
        for ( j = i; j < h; j++) {
            cout << "  ";
        }
        
         // Print  2*height-1 characters
        for ( j = 1; j < (2 * i - 1); j++) {
            cout << ch << " ";
               }
        cout << ch << endl; // last char add New line after each row 
        ch++;
    }

    // Print the lower part of the diamond
    for ( i = h - 1; i >= 1; i--) {
       
        // Print leading spaces
       for ( j = i; j < h; j++) {
            cout << "  ";
        }
        // Print  2*height-1 characters
        for ( j = 1; j < (2 * i - 1); j++) {
            cout << ch << " ";
        }
        cout << ch << endl; // last char add New line after each row 
        ch++;
    }
}

int main() {
    int h;
    int choice;
  
   while (cin >> choice) {   
        
        cin >> h;
      
        if ( choice == 1)
            printHalfPyramid(h);
        else if ( choice == 2 )  
            printFullPyramid(h);
        else if ( choice == 3 ) 
            printDiamond(h);
    }
    return 0;
}



