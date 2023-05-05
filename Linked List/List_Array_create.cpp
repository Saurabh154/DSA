#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*first = NULL;

void Create_Array(int A[] , int n)
{
    struct Node *t,*last;
    first = new Node();
    first -> data = A[0];
    first -> next = NULL; 
    last = first;

    for(int i=1;i<n;i++)
    {
        t = new Node();
        t -> data = A[i];
        t -> next = NULL;
        last -> next = t;
        last = t;
    }
}

void Printlist(struct Node *p)
{
    while(p!= NULL)
    {
        cout<<p->data<<"->";
        p = p->next;       
    }
    cout<<"NULL";
}
int main()
{
    int Arr[]={2,4,5,4,3};
    int n = sizeof(Arr)/sizeof(Arr[0]);
    Create_Array(Arr,n);
    Printlist(first);
}
