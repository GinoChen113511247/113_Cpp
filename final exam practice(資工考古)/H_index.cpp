#include <iostream>
using namespace std;

int main(void)
{
    int size, answer = -1, x = 0, h = 1;
    cin >> size;
    int citation[size];
    for (int i = 0; i < size; i++)
        cin >> citation[i];
    while (h <= size)
    {
        x = 0;
        for (int k = 0; k < size; k++)
        {
            if (citation[k] > h)
                x++;
        }

        if (x == h)
            answer = h;
        h++;
    }
    cout << answer;
    return 0;
}