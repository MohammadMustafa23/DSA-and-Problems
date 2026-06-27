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

class Stack
{
    Node *Top;
    void PushBottomRec(Node *head, int data)
    {
        if (head->next == NULL)
        {
            Node *newNode = new Node(data);
            head->next = newNode;
            return;
        }
        PushBottomRec(head->next, data);
    }
    Node *Reverse_Stack_Rec(Node *head)
    {
        if (head == NULL || head->next == NULL)  {
            return head;
        }

        Node *newHead = Reverse_Stack_Rec(head->next);

        head->next->next = head;
        head->next = NULL;

        return newHead;
    }

public:
    Stack()
    {
        Top = NULL;
    }

    void Push(int data)
    {
        Node *newNode = new Node(data);
        if (Top == NULL)
        {
            Top = newNode;
            return;
        }
        else
        {
            Node *temp = Top;
            Top = newNode;
            newNode->next = temp;
        }
    }

    void Pop()
    {
        if (isEmpty())
        {
            return;
        }
        else
        {
            Node *temp = Top->next;
            delete Top;
            Top = temp;
        }
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "Stack Empty";
            return -1;
        }
        return Top->data;
    }

    int isEmpty()
    {
        return Top == NULL;
    }

    void Push_Bottom(int data)
    {
        PushBottomRec(Top, data);
    }
    void PrintStack()
    {
        Node *temp = Top;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL";
    }

    void Reverse_Stack()
    {
        Node *newHhead = Reverse_Stack_Rec(Top);
        Node *temp = newHhead;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL";
    }
};

int main()
{
    Stack s1;
    s1.Push(1);
    s1.Push(2);
    s1.Push(3);
    s1.PrintStack();
    s1.Reverse_Stack();
    
}

// Using STL
// #include <iostream>
// #include <list>
// using namespace std;

// template <class T>

// class Stack
// {
//     list<T> L1;

// public:
//     void Push(T data)
//     {
//         L1.push_front(data);
//     }

//     void Pop()
//     {
//         L1.pop_front();
//     }

//     T Top()
//     {
//         return L1.front();
//     }

//     int isEmpty()
//     {
//         return L1.empty();
//     }
//     void PushBottom(Stack<T> &st, T data)
//     {
//         Stack<T> temp;
//         while (!st.isEmpty())
//         {
//             temp.Push(st.Top());
//             st.Pop();
//         }

//         st.Push(data);
//         while (!temp.isEmpty())
//         {
//             st.Push(temp.Top());
//             temp.Pop();
//         }
//     }

//     void PrintStack()
//     {
//         for (auto it = L1.begin(); it != L1.end(); ++it) {
//             cout << *it << " -> ";
//         }
//         cout << "NULL";
//     }
// };

// int main()
// {
//     Stack<char> s1;
//     s1.Push('A');
//     s1.Push('B');
//     s1.Push('C');
//     s1.PushBottom(s1, '9');
//     s1.PrintStack();
// }