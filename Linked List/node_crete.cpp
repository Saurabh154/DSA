#include<iostream>
using namespace std;

class Node{
public:
     int data;
     Node *next;

     ///Constructor
     Node(int data)
     {
         this -> data = data;
         this -> next = NULL;
     }
};

void InsertAtHead(Node* &head , int d)
{
    ///New node create

    Node *temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void InsertAtTail(Node* &tail , int d)
{
    ///New node create

    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}

void InsertAtPosition(Node* &head , Node* &tail , int pos , int d)
{
     Node* temp = head;
    int count=1;
    ///insert at start
    if(pos == 1)
    {
        InsertAtHead(head , d);
        return;
    }

    while(count<pos-1)
    {
        temp = temp -> next;
        count++;
    }

    ///inserting at Last Position
   if(temp->next==NULL)
    {
        InsertAtTail(tail,d);
    }

    /// creating a node for d
    Node *nodeToInsert = new Node(d);

    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;


}
void print(Node* &head)
{
   Node* temp = head;

   while(temp!=NULL)
   {
       cout<< temp -> data <<" ";
       temp = temp -> next;
   }
   cout<<endl;
}

int main()
{
    ///created a new node
    Node* node1 = new Node(10);
    /*//node1->data=20;
    cout<<node1->data <<endl;
    cout<<node1->next<<endl; */

    ///head pointed to node1

    Node* head = node1;

    cout<<"Insertion At Beginning"<<endl;
    InsertAtHead(head , 12);
    //InsertAtHead(head , 12);
    //InsertAtHead(head , 12);
     print(head);

    Node* tail = node1;
    cout<<"Insertion At End"<<endl;
    InsertAtTail(tail , 20);
    //InsertAtTail(tail , 30);
    //InsertAtTail(tail , 40);
     print(head);

    cout<<"Insertion At Postion"<<endl;
    InsertAtPosition(head ,tail, 4 , 30);
    print(head);

    cout<<"head " <<head->data<<endl;
    cout<<"tail " <<tail->data<<endl;
    return 0;
}
