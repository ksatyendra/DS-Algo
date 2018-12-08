#include<iostream>
using namespace std;
int top;
int a[40];
char b[40];
char c[40];
void push(int k)
{
 a[++top]=k;
}
int pop()
{
 return a[top--];
}
void pu(char k)
{
 c[++top]=k;
}
char po()
{
 return c[top--];
}
int post_eval()
{
    int i,i1,i2;
    for(i=0;b[i]!='\0';i++)
    {
        if(b[i]>='0'&&b[i]<='9')
            push(int(b[i])-48);
        else
        {
            i1=pop(); i2=pop();
            switch(b[i])
            {
                case '+': push(i2+i1); break;
                case '-': push(i2-i1); break;
                case '*': push(i2*i1); break;
                case '/': push(i2/i1); break;
                case '%': push(i2%i1); break;
            }
        }
    }
    return pop();
}
int main()
{
    int k,i; top=-1;
    cout<<"\nEnter expression : ";
    cin>>b;
    k=post_eval();
    cout<<"\nans : "<<k;
}