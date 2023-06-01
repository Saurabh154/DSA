#include<iostream>
#include<stack>
using namespace std;

void sortedInsert(stack<int> &stack , int num)
{
	//BAse case
	if(stack.empty() || (!stack.empty() && stack.top() < num)){
		stack.push(num);
		return;
	}

	int n = stack.top();
	stack.pop();

	//Recursive call
	sortedInsert(stack,num);

	stack.push(n);
}
void sortStack(stack<int> &stack)
{
	//base case
	if(stack.empty()){
		return;
	}

	int num = stack.top();
	stack.pop();

	//Recursive call
	sortStack(stack);

	sortedInsert(stack , num);
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
    sortStack(s);
    print_stack(s,n);
    

    
}