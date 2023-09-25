#include <iostream>
#include<string>
#define sizes 100
using namespace std;

// Postfix to Infix 

class stack
{
    string item[100];
    int top;
    public:
        stack()
        {
            top=-1;
        }
        void push(string str)
        {
            if(top==sizes-1)
            {
                cout<<"stack overflow!!\n";
                return;
            }
            top++;
            item[top]=str;
        }
        string pop()
        {
            int i;
            string temp;
            if(top==-1)
            {
                cout<<"stack underflow!!\n";
                return "abc";
            }
            temp = item[top];
            top--;
            return temp;
        }
};
int main(int argc, char** argv) 
{
    int i,j=0;
    stack st;
    string postfix,infix;
    cout<<"Enter postfix expression:\n";
    cin>>postfix;
    for(i=0;i<postfix.size();i++)
    {
        if(postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='*' || postfix[i]=='/' || postfix[i]=='^')
        {
            string temp,op1,op2;
            op2=st.pop();
            op1=st.pop();
            temp='('+op1+postfix[i]+op2+')';
            st.push(temp);
        }
        else
        {
            string flag;
            flag=flag+postfix[i];
            st.push(flag);
        }
    }
    cout<<"The equivalent infix expression is:\n"<<st.pop();
    return 0;
}
