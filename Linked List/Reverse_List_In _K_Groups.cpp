#include<iostream>
using namespace std;

class LinkedList{
    struct Node{
        int data;
        Node *next;
        Node(int d){
            data = d;
            next = NULL;
        }
    };
    Node *head,*tail;

    public:
        LinkedList()
        {
            head = NULL;
        }

        void InsertAtEnd(int data)
        {
            Node* newNode = Node(data);
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

        void printList()
        {
            Node *current = head;
            if(head == NULL)
            {
                cout<<"!! List is empty !!";
                return;
            }
            else{
                while(current != NULL)
                {
                    cout<<current->data<<" -> ";
                    current = current->next;
                }
                cout<<"NULL";
                cout<<"\n";
            }
        }

        void kReverse(*Node , int k)
        {
            if(head == NULL){
            return head;
        }

        Node* forward = NULL;
        Node* curr = head;
        Node* prev = NULL;
        int count=0;
        while(curr != NULL && count<k)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            count++;
        }
        //step2 : Recursion dekh lega aage ka
        if(forward != NULL)
        {
            head->next = kReverse(forward , k);
        }

        }
};

int main()
{
    LinkedList ll = LinkedList();
    ll.InsertAtEnd(4);
    ll.InsertAtEnd(2);
    ll.InsertAtEnd(5);
    ll.InsertAtEnd(2);
    ll.InsertAtEnd(6);
    ll.InsertAtEnd(3);
    ll.InsertAtEnd(0);
    ll.InsertAtEnd(9);
    ll.printList();

    cout<<endl;
    
    ll.kReverse(head , 2);
    ll.printList();
}