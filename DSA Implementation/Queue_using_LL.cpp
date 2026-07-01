#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    // O(1)
    void push(int data) {
        Node *newNode = new Node(data);
        if(front == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // O(1)
    void pop() {
        if(isEmpty()) {
            cout << "Queue Empty";
        } else {
            Node *temp = front->next;
            delete front;
            front = temp;
        }

    }

    // O(1)
    int Front() {
        if(isEmpty()) {
            return -1;
        } else {
            return front->data;
        }
    }

    bool isEmpty() {
        return front == NULL;
    }
    

    // O(n)
    void PrintQueue() {
        Node *temp = front;
        while (temp!=NULL)
        {
            cout << temp->data << "  ";
            temp = temp->next;
        }        
    }
};

int main()
{
    Queue q;
    q.push(1);
    q.push(2);

    q.pop();
    q.push(3);

    cout << "Queue Front -> "<< q.Front() << "  ";

    q.PrintQueue();
}