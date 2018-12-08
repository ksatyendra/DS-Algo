#include<iostream>
#include<conio.h>
using namespace std;
int top;
char a[40],b[40];
void push(char k)
{
 a[++top]=k;
}
char pop()
{
 if(top>=0)
    return a[top--];
 return '\0';
}
bool paren_check()
{
 for(int i=0;b[i]!='\0';i++)
 {
     switch(b[i])
     {
        case '(':
        case '{':
        case '[': push(b[i]); break;
        case ')': if(pop()!='(') return 0; break;
        case '}': if(pop()!='{') return 0; break;
        case ']': if(pop()!='[') return 0; break;
     }
 }
 return top==-1;
}
void in2post(char *c)
{
    char k;
    int i,j;
    for(i=0,j=0;b[i]!='\0';i++)
    {
        switch(b[i])
        {
            case '[':
            case '(':
            case '{': push(b[i]); break;
            case ')': for(k=pop();k!='(';c[j++]=k,k=pop()); break;
            case '}': for(k=pop();k!='{';c[j++]=k,k=pop()); break;
            case ']': for(k=pop();k!='[';c[j++]=k,k=pop()); break;
            case '+':
            case '-': if(top>=0)
                      {
                        for(k=pop();k=='*'||k=='/'||k=='+'||k=='-';c[j++]=k,k=pop());
                        push(k);
                      }
                      push(b[i]); break;
            case '*':
            case '/': if(top>=0)
                      {
                        for(k=pop();k=='*'||k=='/';c[j++]=k,k=pop());
                        push(k);
                      }
                      push(b[i]); break;
            default : c[j++]=b[i];
        }
    }
    while(top>=0) c[j++]=pop();c[j]='\0';
}
int main()
{
    int k=1;
    top=-1;
    char c[40];
    cout<<"1 for paren_check\n2 for in2post : ";
    cin>>k;
    cout<<"\nEnter expression : ";
    cin>>b;
    switch(k)
    {
        case 1:if(paren_check()) cout<<"\nokay\n";
               else cout<<"\nNOT okay"; break;
        case 2:in2post(c); cout<<"pf : "<<c<<endl;
    }
    getch();
}
