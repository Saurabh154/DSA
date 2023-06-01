#include<iostream>
#include<stack>
using namespace std;
void solve(stack<int> &st , int ele){
    //BASE CASE
    if(st.empty()){
        st.push(ele);
        return;
    }

    int num = st.top();
    st.pop();

    //Recursive call
    solve(st, ele);
    st.push(num);

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
    int element = 10;
    solve(s ,element);
     print_stack(s,n);
    cout<<s.size();

    
}