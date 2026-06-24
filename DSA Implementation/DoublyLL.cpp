#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DoublyList
{
private:
    Node *head;
    Node *tail;

public:
    DoublyList()
    {
        head = NULL;
        tail = NULL;
    }

    ~DoublyList() {
        while (head != NULL)
        {
            pop_Front();
        }
        
    }

    void push_Front(int data) {
        Node *newNode = new Node(data);
        if(head == NULL) {
            head = tail = newNode;
            return;
        } else {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
            return;
        }
    }

    void pop_Front() {
        if(head == NULL) {
            cout << "List Empty";
            return;
        } else {
            Node *temp = head->next;
            delete head;
            head = temp;
        }
    }

    void push_Back(int data) {
        Node *newNode = new Node(data);
        if(head == NULL) {
            head = tail = newNode;
            return;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_Back() {
         if(head == NULL) {
            cout << "List Empty";
            return;
        } else {
            Node *temp = tail->prev;
            delete tail;  
            
            if(temp != NULL) {
                temp->next = NULL;
                tail = temp;
            } else {
                head = NULL;
                tail = NULL;
            }
        }
    }

    void print_List() {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL";
        
    }
};

int main()
{
    DoublyList l1;
    l1.push_Front(3);
     l1.push_Front(4);
     l1.push_Back(2);
     l1.push_Back(10);
     l1.pop_Back();
     l1.pop_Back();
     l1.pop_Back();
     l1.pop_Back();
     l1.push_Back(1);
     l1.push_Front(2);
    l1.print_List();
}