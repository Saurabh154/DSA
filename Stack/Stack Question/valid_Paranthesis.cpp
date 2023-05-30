#include<iostream>
#include<stack>
using namespace std;
bool isValidParenthesis(string expression)
{
    stack<char> s;
    for(int i=0 ; i<expression.length();i++){
        char ch = expression[i];

        //If opening bracket, stack push
        //If closing bracket, stack top check and pop

        if(ch == '(' || ch == '[' || ch == '{')
        {
            s.push(ch);
        }
        else
        {
            //For closing bracket
            /*
              It may be stack is already empty so 
              in this case an exception can raise
            */
            if(!s.empty()){  
                char top = s.top(); //to check matching char
                if( (ch == '}' && top == '{') || 
                    (ch == ')' && top == '(') ||
                    (ch == ']' && top == '[') )
                
                {
                    s.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }

    if(s.empty())
        return true;
    else
        return false;
}
int main()
{
    string str="{[(]}";
    //cout<<isValidParenthesis(str);
    if(isValidParenthesis(str)){
        cout<<"Valid Parenthesis";
    }
    else{
        cout<<"Not Valid Parenthesis";
    }
    return 0;
}