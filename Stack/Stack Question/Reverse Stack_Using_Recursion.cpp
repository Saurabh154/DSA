#include<iostream>
#include<stack>
using namespace std;
void InserAtBottom(stack<int>st , int ele)
{
    //BASE CASE
    if (st.empty()) {
      st.push(ele);
      return;
    }

    int num = st.top();
    st.pop();

    // Recursive call
    InserAtBottom(st, ele);
    st.push(num);
}
void reverseStack(stack<int> stack) {
    //Base Case
    if(stack.empty()){
        return;
    }

    int num = stack.top();
    stack.pop();

    //Recursive call
    reverseStack(stack);
    InserAtBottom(stack , num);
}

void print_stack( stack <int>t , int size)
{
    while(!t.empty()){
        cout<<t.top()<<" ";
        t.pop();
    }
}

int main()
{
    int arr[]={1,2,3,4,5};
    int n=5;
    stack <int> s;

    for(int i=0 ; i<5;i++){
        int c = arr[i];
        s.push(c);     
    }
    reverseStack(s);
    print_stack(s,n);
    cout<<s.size();

    
}