#include <iostream>
#include <string>
using namespace std;

struct Order
{
    int id;       // Order ID
    string name;  // Product name
    int quantity; // Product quantity
    Order *next;  // Pointer to the next node
};

void printOrders(Order *head)
{
    if (head == nullptr)
    {
        cout << "No orders available!" << endl;
        return;
    }

    cout << "Order list:" << endl;
    Order *current = head;
    while (current != nullptr)
    {
        cout << "Order ID: " << current->id
             << ", Product Name: " << current->name
             << ", Quantity: " << current->quantity << endl;
        current = current->next;
    }
}

void addOrder(Order *&head, int id, string name, int quantity)
{
    Order *newOrder = new Order{id, name, quantity, nullptr};

    if (head == nullptr)
        head = newOrder;
    else
    {
        Order *current = head;
        while (current->next != nullptr)
            current = current->next;
        current->next = newOrder;
    } // 在最後端插入
}

void searchOrder(Order *head, int id)
{
    Order *current = head;
    while (current != nullptr)
    {
        if (current->id == id)
        {
            cout << "Order found: Order ID: " << current->id
                 << ", Product Name: " << current->name
                 << ", Quantity: " << current->quantity << endl;
            return;
        }
        current = current->next;
    }
    cout << "No order found with ID: " << id << endl;
}

void deleteOrder(Order *&head, int id)
{
    if (head == nullptr)
    {
        cout << "No orders available!" << endl;
        return;
    }

    // 如果要刪除的對象是head的話
    if (head->id == id)
    {
        Order *temp = head;
        head = head->next;
        delete temp;
        cout << "Order with ID " << id << " has been deleted!" << endl;
        return;
    }

    // 要刪的對象不是head
    Order *current = head;
    Order *prev = nullptr;
    while (current != nullptr && current->id != id)
    {
        prev = current;
        current = current->next;
    } // 移動到要刪的對象

    if (current == nullptr)
    {
        cout << "No order found with ID: " << id << endl;
        return;
    }

    prev->next = current->next;
    delete current;
    cout << "Order with ID " << id << " has been deleted!" << endl;
}

int main()
{
    Order *head = nullptr;
    int choice, id, quantity;
    string name;

    while (true)
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> id >> name >> quantity;
            addOrder(head, id, name, quantity);
            break;
        case 2:
            cin >> id;
            searchOrder(head, id);
            break;
        case 3:
            cin >> id;
            deleteOrder(head, id);
            break;
        case 4:
            printOrders(head);
            break;
        case 5:
            cout << "System exiting, thank you for using!" << endl;
            return 0;
        default:
            cout << "Invalid option, please try again!" << endl;
        }
    }

    return 0;
}
