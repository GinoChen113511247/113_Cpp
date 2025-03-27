#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int times, size = 0, c = 0;
    cin >> times;
    cin.ignore(1);
    for (int i = 0; i < times; i++)
    {
        string A = "", B = "", answer = "";
        getline(cin, A, '\n');
        getline(cin, B, '\n');
        size = A.length();
        for (int i = size - 1; i >= 0; i--)
        {
            int s = 0;
            int a = A[i] - '0';
            int b = B[i] - '0';
            s = (a ^ b) ^ c;
            answer += (s + '0');
            c = (a & b) | (a ^ b) & c;
        }

        for (int i = size; i >= 0; i--)
            cout << answer[i];
        cout << endl
             << c << endl;
    }
    return 0;
}