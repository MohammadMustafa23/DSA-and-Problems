#include <iostream>
#include <vector>
using namespace std;

template <class T>
// Stack Using Vector
class Stack
{
    vector<T> vec;
public:
    void Push(T data)
    {
        vec.push_back(data);
    }
    void Pop()
    {
        if(isEmpty()) {
            return;
        }
        vec.pop_back();
    }
    T Top()
    {
        if(isEmpty()) {
            return -1;
        }
        return vec[vec.size()-1];
    }

    bool isEmpty() {
        return vec.size() == 0;
    }
};

int main()
{
    Stack<char> s1;
    s1.Push('a');
    s1.Push('b');
    s1.Push('c');

    while (!s1.isEmpty())
    {
       cout << s1.Top() << "  ";
       s1.Pop();
    }
    
}