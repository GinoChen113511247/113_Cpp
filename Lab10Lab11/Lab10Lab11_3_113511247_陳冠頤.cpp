#include <iostream>
#include <cstdlib>
using namespace std;

int compare(const void *, const void *);

int main(void)
{
    int number, times, target;
    cin >> number;
    int chamber[number];
    for (int idx = 0; idx < number; idx++)
        cin >> chamber[idx];
    int n = sizeof(chamber) / sizeof(chamber[0]);
    qsort(chamber, n, sizeof(int), compare); // 把陣列以遞增的方式排列好
    cin >> times;
    int answer[times]; // 把答案存到這個陣列再一起輸出
    for (int i = 0; i < times; i++)
    {
        cin >> target;
        int count = 0;
        for (int j = 0; j < number; j++)
        {
            if (target == chamber[j])
                count++;
            else if (chamber[j] > target)
                break; // 當陣列的元素值大於目標時就不用再找了，因為後面的元素只會更大(遞增)，根本不可能再找到
        }
        answer[i] = count;
    }
    for (int i = 0; i < times; i++)
        cout << answer[i] << endl;
    return 0;
}

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}