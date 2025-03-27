#include <iostream>
using namespace std;

int main(void)
{
    int L, sum = 0;
    cin >> L;
    int A[L] = {0};
    int B[L] = {0};
    for (int i = 0; i < L; i++)
        cin >> A[i];
    for (int i = 0; i < L; i++)
        cin >> B[i];
    for (int i = 0; i < L; i++)
        sum += (A[i] * B[L - i - 1]);
    cout << sum;
    return 0;
}