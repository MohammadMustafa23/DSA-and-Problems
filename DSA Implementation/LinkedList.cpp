#include <iostream>
#include<list>
using namespace std;
class Node {
   public :
   int data;
   Node *next;
   Node(int val) {
      this->data = val;
      this->next = NULL;
   }
};

class List {
   Node *head;
   Node *tail;

   public :
   List() {
      head = NULL;
      tail = NULL;
   }
   
   ~List() {
      while(head != NULL) {
         pop_Front();
      }
   }

   void push_Front(int data) {
      Node *newNode = new Node(data);
      if(head == NULL) {
         head = newNode;
         tail = newNode;
         return;
      } else {
         Node *temp = head;
         head = newNode;
         newNode->next = temp; 
      }
   }

   void pop_Front() {
      if(head == NULL) {
         return;
      }

      Node *temp = head->next;
      delete head;
      head = temp;
   }

   void push_Back(int data) {
      Node *newNode = new Node(data);
      if(head == NULL) {
         head = newNode;
         tail = newNode;
         return;
      } else {
         tail->next = newNode;
         tail = newNode;
      }
   }

   void pop_Back() {
      if(head == NULL || head->next == NULL) {
         delete head,tail;
         head = tail = NULL;
      } else {
         Node *temp = head;
         while(temp->next->next != NULL) {
            temp = temp->next;
         }

         delete tail;
         temp->next = NULL;
         tail = temp;
      }
   }

   void insertMiddle(int data,int pos) {
      Node *newNode = new Node(data);
      int count = 1;
      Node *temp = head;
      while(temp != NULL) {
         if(count == pos) {
            break;
         } else {
            count++;
            temp = temp->next;
         }
      }

      if(temp != NULL) {
         Node *hold = temp->next;
         temp->next = newNode;
         newNode->next = hold;
      } else {
         cout << "In-Valid Index or Position";
      }
   } 

   int serach_Key(int key) {
      if(head == NULL) {
         cout << "List Empty";
         return -1;
      } else {
         int pos = 0;
         Node *temp = head;
         while(temp!=NULL) {
            if(temp->data == key) {
               return pos;
            } else {
               pos++;
               temp=temp->next;
            }
         }

         return -1;
      }
   }

   int recursive_search(Node *head,int key) {
      if(head == NULL) {
         return -1;
      } else if(head->data == key) {
         return 0;
      }

      int idx = recursive_search(head->next,key);
      if(idx == -1) {
         return -1;
      } else {
         return idx+1; 
      }
   }

   int search(int key) {
      return recursive_search(head,key);
   }
   
   void Remove_Nth(int idx) {
      if(head == NULL) {
         return;
      } else {
         Node *curr = head;
         Node *prev = NULL;
         int pos = 0;

         while(curr != NULL) {
            if(idx == pos) break;
            ++pos;
            prev = curr;
            curr = curr->next;
         }

         if(prev!=NULL  && curr!=NULL) {
            prev->next = curr->next;
           delete curr;
         } else if(curr==NULL) {
            return;
         } else {
            pop_Front();
         }
      }
   }

   void ReverseList() {
      Node *newHead = NULL;
      Node *temp = head;
      while(temp != NULL) {
         Node *newNode = new Node(temp->data);
         if(newHead == NULL) {
            newHead = newNode;
         } else {
            newNode->next = newHead;
            newHead = newNode;
         }
         temp = temp->next;
      }
      // PrintList(newHead);
   }


   void PrintList() {
      Node *temp = head;
      while (temp!=NULL)
      {
         cout << temp->data << "->";
         temp=temp->next;
      }
      cout<<"NULL";
      return;
   }
};

int main() {
   List l1;   
}

