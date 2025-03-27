#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

int main()
{
    int n, k;
    cin >> n >> k;

    // 建立循環鏈結串列
    Node *head = new Node{1, nullptr};
    Node *tail = head;
    for (int i = 2; i <= n; ++i)
    {
        tail->next = new Node{i, nullptr};
        tail = tail->next;
    }
    tail->next = head;

    Node *current = head;
    Node *prev = tail;

    while (current->next != current)
    {
        for (int i = 1; i < k; ++i)
        {
            prev = current;
            current = current->next;
        } // 移動到第k個人
        Node *toDelete = current;
        prev->next = current->next;
        current = current->next;
        delete toDelete;
    }

    cout << current->data << endl;

    delete current;
    return 0;
}
