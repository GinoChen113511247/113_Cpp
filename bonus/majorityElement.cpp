#include <iostream>
using namespace std;

int compare(const void*, const void*);
int counting(int[], int, int);

int main(void)
{
    int size, answer=0, target, index=0;
    cin >> size;
    int input[size];
    int elements[size];
    int counts[size]={0};//記得初始化
    for (int i=0;i<size;i++)
        cin >> input[i];
    qsort(input, size, sizeof(int), compare);
    target=input[0];
    while(index<size)
    {
        elements[index]=target;
        counts[index]=counting(input, target, size);
        index++;
        while (index<size-1 && input[index]==input[index+1])//隨時檢查index有沒有超出範圍
            index++;
        if (index<size)//隨時檢查index有沒有超出範圍
            target=input[index];
    }
    int max=counts[0];
    for (int i=0;i<index;i++)//不是<= 
    {
        if (max<counts[i])
        {
            answer=i;
            max=counts[i];
        }
    }
    cout << elements[answer];
    return 0;
}

int compare (const void* a, const void* b)
{
    return (*(int*)a-*(int*)b);
}

int counting (int input[], int target, int size)
{
    int times=0;
    for (int i=0;i<size;i++)
    {
        if (target<input[i])
           break;
        else
        {
            if (target==input[i])
                times++;
        }
    }
    return times;
}