#include<iostream>
#include<stack>
using namespace std;
void solve(stack<int> &st , int count , int size){
    //BASE CASE
    if(count == size/2){
        st.pop();
        return;
    }

    int num = st.top();
    st.pop();

    //Recursive call
    solve(st, count+1 ,size);
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
    int count=0;
    solve(s , count , n);
    print_stack(s,n);
    cout<<s.size();

    
}