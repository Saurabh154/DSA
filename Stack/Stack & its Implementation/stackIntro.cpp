#include<iostream>
using namespace std;

class Stack{
    //Properties
    public:
        int *arr;
        int top;
        int size;
    //Behaviour
    Stack(int size){
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element)
    {
        if(size - top > 1){
            top++;
            arr[top] = element;
        }
        else{
            cout<<"Stack Overflow!!";
        }
    }

    void pop()
    {
        if(top >=0){
            top--;
        }
        else{
            cout<<"Stack Underflow!!";
        }
    }

    int peek(){
        if(top >= 0)
        return arr[top];
        else{
            cout<<"Stack is Empty!!";
        }
    }

    bool IsEmpty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }

    bool IsFull() {
        if(top == size){
            return true;
        }
        else{
            return false;
        }
    }
};

int main()
{
    int size;
    cout<<"Enter the size of stack !!\n";
    cin>>size;
    Stack st(size);
    /*int ch;
    do{
        cout<<"\nEnter any one Option:";
        cout<<"\n1.PUSH \n 2.POP \n 3.PEEK \n 4.Is Empty \n 5.Is Full\n";
        cin>>ch;
        switch (ch)
        {
        case 1: 
            int ele;
            cout<<"Enter Element you want to PUSH:";
            cin>>ele;
            st.push(ele);
            break;
        
        case 2:
            cout<<st.peek()<<endl;
        default:
            break;
        }
    }while(ch>6); */

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    cout<<st.peek()<<endl;

    st.pop();

    cout<<st.peek()<<endl;


    return 0;
}