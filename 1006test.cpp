#include <iostream>
using namespace std;

struct NODE
{
    int num = 0;
    NODE *next = nullptr;
};

NODE *searchList(NODE *, int);

int main(void)
{
    // 一次創建多個節點
    int size;
    cin >> size;
    NODE *linkedlist = new NODE[size];
    NODE *head = &linkedlist[0];
    for (int i = 0; i < size - 1; i++)
        linkedlist[i].next = &linkedlist[i + 1];
    linkedlist[size - 1].next = nullptr;
    /*to do */
    delete[] linkedlist;

    // 在中間插入一個節點
    NODE *current = new NODE({0, nullptr});
    linkedlist[5].next = current;
    current->next = &linkedlist[6];
    /*to do */
    delete current;

    // 在中間移除一個節點
    linkedlist[3].next = &linkedlist[5];
    delete &linkedlist[4];

    // 在linked list中尋找
    NODE *target = searchList(head, 6);
    return 0;
}

NODE *searchList(NODE *head, int value)
{
    for (NODE *curr = head; curr != nullptr; curr = curr->next)
    {
        if (curr->num == value)
            return curr;
        return nullptr;
    }
}
