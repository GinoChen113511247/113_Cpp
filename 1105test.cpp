#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
    struct NODE
    {
        int num = 0;
        NODE *next = nullptr;
    };
    /*typedef NODE *NODEptr;
    NODEptr head;*/
    NODE *head;
    NODE linkedList[10];
    for (int i = 0; i < 9; i++)
    {
        linkedList[i].next = &linkedList[i + 1];
    }
    linkedList[9].next = nullptr;
    head->next = &linkedList[0];
}
