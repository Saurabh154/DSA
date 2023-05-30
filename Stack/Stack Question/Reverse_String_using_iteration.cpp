#include<iostream>
#include<stack>
#include<string>
using namespace std;


int main()
{
    //string str = "babbar";
    string str;
    cout<<"Enter Any String : "<<endl;
    cin>>str;
    stack<char> s;  //STL stack

    /* 
        This loop is going to traverse the whole string
        and alongwith push current element to the stack
    */
    for(int i=0 ; i<str.length() ; i++){
        char ch = str[i];
        s.push(ch);
    }

    /*Create an empty stack to store popped element*/
    string ans="";

    /*
        This loop is going to pop the current top element
        and push back to the empty string ans
    */
    while(!s.empty()){
        char ch = s.top();  // Store top element in ch variable
        ans.push_back(ch);  // keep in ans string

        s.pop();  //Pop the element
    }
    /* 
        At the end of the loop the pop element are
        arranged in reverse .
    */
    cout<<"Reverse is : "<<ans<<endl;
}