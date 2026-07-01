#include <iostream>
using namespace std;

class Queue
{

    int *arr;

    int capacity;
    int currSize;

    int front, rear;

public:
    Queue(int cap)
    {
        capacity = cap;
        currSize = 0;
        front = rear = -1;

        if(cap > 0) {
            arr = new int[capacity];
        } else {
            arr = NULL;
        }
    }

    ~Queue() {
        delete []arr;
    }
    
    // O(1)
    void push(int data)
    {
        if (front == -1)
        {
            currSize++;
            front++;
            rear++;
            arr[rear] = data;
        }
        else
        {
            if (currSize == capacity)
            {
                cout << "Queue is FUll";
            }
            else
            {
                currSize++;
                rear = (rear + 1) % capacity;
                arr[rear] = data;
            }
        }
    }

    // O(1)
    void pop()
    {
        if (front == -1)
        {
            cout << "Queue Empty";
        }
        else
        {
            front++;
            currSize--;
        }
    }

    // O(1)
    bool empty()
    {
        return currSize == 0;
    }

    // O(1)
    int Front()
    {
        if (front == -1)
        {
            return -1;
        }
        else
        {
            return arr[front];
        }
    }
};

int main()
{
    Queue q(4);

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout << q.Front() << endl;
    q.pop();

    cout << q.Front() << endl;
    q.push(5);

    cout << q.Front() << endl;
}