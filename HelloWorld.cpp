#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Linked List CPP

class ListNode
{
public:
    int key;
    ListNode *next;
};

class List
{
    ListNode *head;
    ListNode *tail;
    ListNode *temp;
    bool isEmpty()
    {
        return head == NULL;
    }

public:
    List()
    {
        head = NULL;
        tail = NULL;
    }

    ListNode* insert(int x)
    {
        temp = new ListNode;
        temp->key = x;
        if (isEmpty())
        {
            temp->next = NULL;
            tail = temp;
        }
        else
            temp->next = head;
        head = temp;
        return temp;
    }

    void insertAtEnd(int x)
    {
        temp = new ListNode;
        temp->key = x;
        temp->next = NULL;
        if (isEmpty())
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    void remove(int x)
    {
        temp = head;
        ListNode *prev;
        while (temp->next != NULL && temp->key != x)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp->key == x)
        {
            prev->next = temp->next;
            delete temp;
        }
        else if (temp->next == NULL)
        {
            cout << "Error: Number Not found..." << endl;
        }
    }

    void removeNode(ListNode* node)
    {
        ListNode *temp;
        ListNode *prev;
        temp = head;
        while (temp->next != NULL && temp != node)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == node) 
        {
            prev->next = temp->next;
            delete temp;
        }
    }

    void find(int x)
    {
        int i;
        for (i = 1, temp = head; temp->next != NULL && temp->key != x; temp = temp->next, i++)
            ;
        if (temp->key == x)
        {
            cout << "Found at position:" << i << endl;
        }
        else if (temp->next == NULL)
        {
            cout << "Error: Number Not found..." << endl;
        }
    }

    void display()
    {
        if (!isEmpty())
        {
            for (temp = head; temp != NULL; temp = temp->next)
                cout << temp->key << " ";
            cout << endl;
        }
        else
        {
            cout << "List is Empty!" << endl;
        }
    }
};

int main()
{
    List l;
    ListNode *ll1, *ll2, *ll3, *ll4;

    l.display();
    ll1 = l.insert(15);
    l.display();
    ll2 = l.insert(25);
    l.display();
    ll3 = l.insert(35);
    l.display();
    ll4 = l.insert(45);
    l.display();

    l.removeNode(ll3);
    l.display();

    // l.find(15);
    // l.remove(25);
    // l.display();
    // l.insertAtEnd(55);
    // l.insertAtEnd(65);
    // l.display();
}