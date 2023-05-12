#include<iostream>
using namespace std;

class LinkedList{
    struct Node{
        int data;
        Node *next; 
        Node(int d)
        {
            data = d;
            next = NULL;
        }
    };
    Node *head , *tail;
    public:
       LinkedList()
       {
          head = NULL;
       }

       void InsertAtEnd(int data)
       {
          Node *newNode = new Node(data);
          if(head == NULL)
          {
            head = newNode;
            tail = head;
          }
          else{
            tail->next = newNode;
            tail = tail->next;
          }
       }

       void PrintList()
       {
          Node * current = head;

          if(head == NULL)
          {
            cout<<"!! List is Empty !!";
            return ;
          }
          else{
            while(current != NULL)
            {
              cout<<current->data <<"->";
              current = current->next;
            }
            cout<<"NULL";
          }
       }

       void reverseLLIterative()
       {
          Node *prev = NULL;
          Node *current = head;
          Node *next = NULL;

          while (current != NULL)
          {
            /* code */
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
          }
          head = prev;
          
       }


};

int main()
{
    LinkedList li = LinkedList();
    li.InsertAtEnd(10);
    li.InsertAtEnd(20);
    li.InsertAtEnd(30);
    li.InsertAtEnd(40);
    li.InsertAtEnd(50);
    li.PrintList();
    cout<<"\n";
    li.reverseLLIterative();
    li.PrintList();
    return 0;
}