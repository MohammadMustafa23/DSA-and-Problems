// Note That is Implement By doubly Linked List


#include <iostream>
using namespace std;
struct Node
{
    Node *prev;
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next=NULL;
        this->prev =NULL;
    }
};
class deque
{
private:
    Node *front;
    Node *back;

public:
    deque()
    {
        front = NULL;
        back = NULL;
    }
    ~deque()
    {
        while (front != NULL)
        {
            pop_front();
        }
    }
    deque(deque &copy)
    {
        Node *t=copy.front;
        front=NULL;
        back=NULL;
        while(t!=NULL)
        {
            push_back(t->data);
            t=t->next;
        } 
    }
    deque operator=(deque &copy)
    {
        while(front!=NULL)
        {
            pop_front();
        }
        Node *t=copy.front;
        front=NULL;
        back=NULL;
        while(t!=NULL)
        {
            push_back(t->data);
            t=t->next;
        } 
        return (*this);
    }
    void push_front(int value)
    {
        Node *NewNode = new Node(value);
        if (front == NULL)
        {
            front = NewNode;
            back = NewNode;
        } else {
            NewNode->next = front;
            NewNode->prev = NULL;
            front = NewNode;
        }
    }
    void push_back(int value)
    {
        Node *NewNode = new Node(value);
        if (front == NULL)
        {
            front = NewNode;
            back = NewNode;
        } else {
            back->next = NewNode;
            NewNode->prev = back;
            back = NewNode;
        }
    }
    void pop_front()
    {
        if(front == back) {
            delete front,back;
            front = back = NULL;
            return;
        } else if (front != NULL)
        {
            Node *t = front->next;
            t->prev = NULL;
            delete front;
            front = t;
            return;
        }
        cout << "Queue Empty";
    }
    void pop_back()
    {
        if(front == back) {
            delete front,back;
            front = back = NULL;
        } else if(back != NULL) {
            Node *temp = back->prev;
            delete back;
            back = temp;
            back->next = NULL;
        }
    }
    int Front()
    {
        if (front == NULL)
        {
            return -1;
        }
        return front->data;
    }
    int Back()
    {
        if (back == NULL)
        {
            return -1;
        }
        return back->data;
    }
    void printDeque()
    {
        if (front != NULL)
        {
            Node *temp = front;
            while (temp != NULL)
            {
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << "NULL";
            return;
        }
        cout << "Deque Is empty";
    }
};
int main()
{
    deque d;
      d.push_back(1);
     d.push_back(2);
      d.push_back(3);
       d.push_back(4);
        d.push_back(5);

        cout << d.Back();
}