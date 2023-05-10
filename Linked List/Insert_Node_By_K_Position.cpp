/*Insert after a particular position in a linked list  */

#include<iostream>
using namespace std;

class LinkedList
{
    struct Node
    {
        int data;
        Node *next;
        Node(int d)
        {
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
            Node *newNode = new Node(data);

            if(head == NULL)
            {
                head = newNode;
                tail = head;
            }
            else{
                tail->next = newNode;
                tail = tail->next;
                // Node *current = head;
                // while(current->next != NULL)
                // {
                //     current = current->next;
                // }
                // current->next = newNode;
            }
        }

        void InsertAtBeginning(int data)
        {
            Node *newNode = new Node(data);
            if(head == NULL)
            {
               head = newNode;
               tail = newNode; //--.extra kr rahe hai
            }

            else{
                newNode->next = head;
                head = newNode;
            }
        }

        void deleteNode(int dataToDel)
        {
            Node *current = head;
            if(head == NULL)
            {
                cout<<" !! List is empty !!";
                return ;
            }

            else if(head->data == dataToDel)
            {
                head = head->next;
                free(current);
                return ;
            }

            else{
                while(current->next != NULL && current->next->data != dataToDel)
                {
                    current = current->next;
                }

                if(current->next == NULL)
                {
                    cout<<"!! Data does not exist !!";
                    return ;
                }
                else{
                    Node *NodeToDel = current->next;
                    current->next = current->next->next;
                    free(NodeToDel);
                }
            }
        }

        void InsertAtKPosition(int dataToIns , int k)
        {
            if(k<0){
                cout<<"!! Invalid Position !!"<<endl;
                return ;
            }
            if(empty())
            {
                cout<<"!! List is empty !!"<<endl;
                return ;
            }
            //creating a new node 
            Node *newNode = new Node(dataToIns); 
            
            if(k == 0)
            {
                newNode->next = head;
                head = newNode;
            }
            else{
                Node *current = head;

                /*Using for loop*/
                for(int i=0 ; i<k-1 ; i++)
                {
                    current = current->next;
                }
                newNode->next = current->next;
                current->next = newNode;

              /* while(current->next != NULL && --k)
               {
                current = current->next;
               }

               if(k == 0)
               {
                newNode->next = current->next;
                current->next = newNode;
               }
               else{
                 cout<<"!! Position does not exist !!"<<endl;
               }
            */
            }

        }

        void printList()
        {
            if(head == NULL)
            {
                cout<<"!! List is empty !!";
                return ;
            }
            else{
                Node *current = head;
                while(current != NULL)
                {
                    cout<<current->data<<"->";
                    current = current->next;
                }
                cout<<"NULL";
                cout<<"\n";
            }
        }

        bool empty()
        {
            return head == NULL;
        }
};

int main()
{
    LinkedList ll = LinkedList();
    ll.InsertAtEnd(40);
    ll.InsertAtEnd(20);
    ll.InsertAtEnd(50);
    ll.printList();
    // ll.InsertAtBeginning(10);
    // ll.InsertAtBeginning(20);
    // ll.InsertAtBeginning(30);
    // ll.printList();
    
    // cout<<"\nNode After deleting\n";
    // ll.deleteNode(30);
    // ll.printList();

    // ll.deleteNode(10);
    // ll.printList();

    // ll.deleteNode(20);
    // ll.printList();
    cout<<"\n";
    int data,pos;
    cout<<"Enter a Node data to insert : ";
    cin>>data;

    cout<<"What position you insert : ";
    cin>>pos;

    ll.InsertAtKPosition(data , pos);
    ll.printList();
    return 0;
}