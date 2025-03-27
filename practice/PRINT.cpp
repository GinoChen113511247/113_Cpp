#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream output("family.txt");
    for (int i = 0; i < 256; i++)
    {
        if (i != 0 && i != 1 && i != 2 && i != 5 && i != 7 && i != 11 && i != 16 && i != 32 && i != 64 && i != 128 && i != 192)
            output << i << ",";
    }
    return 0;
}