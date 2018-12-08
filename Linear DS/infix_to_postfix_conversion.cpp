#include<iostream>
#include<conio.h>
using namespace std;
char *a,*b,*c,top,n=50;
bool isempty()
{
 return top==-1;
}
bool isfull()
{
 return top==n-1;
}
void display()
{
 if(!isempty())
 {
  cout<<"\nStack  is : ";
  for(int i=0;i<=top;i++)
  cout<<a[i]<<" ";
 }
 cout<<"\nStack is empty.";
}
void push(char k)
{
  a[++top]=k;
}
char pop()
{
 return a[top--];
}
void in_2_postfix()
{
     int i,k=0;
     char h;
     for(i=0;b[i]!='\0';i++)
     switch(b[i])
     {   
         case '(' :
         case '{' :
         case '[' : push(b[i]); break;
         case ')' : for(h=pop();h!='(';c[k++]=h,h=pop()); break;
         case '}' : for(h=pop();h!='{';c[k++]=h,h=pop()); break;
         case ']' : for(h=pop();h!='[';c[k++]=h,h=pop()); break;
         case '+' : 
         case '-' : if(top>=0)
                    {
                     for(h=pop();h=='*'||h=='/'||h=='+'||h=='-';c[k++]=h,h=pop());
                     push(h);
                    }
                    push(b[i]);
                    break;
         case '*' : if(top>=0)
                    {
                     for(h=pop();h=='*'||h=='/';c[k++]=h,h=pop());
                     push(h);
                    }
                    push(b[i]);
                    break;
         case '/' : if(top>=0)
                    {
                     for(h=pop();h=='/';c[k++]=h,h=pop());
                     push(h);
                    }
                    push(b[i]);
                    break;
         default : c[k++]=b[i];
     }  
     while(top>=0)
      c[k++]=pop();
     c[k]='\0';
}
int main()
{
 bool ch=1;
 top=-1;
 a = new char [n];
 b = new char[n];
 c = new char[n];
 while(ch)
 {
  cout<<"Enter infix Expression  :  ";
  cin>>b;
  in_2_postfix();
  cout<<"\nPostfix Expression : "<<c;
  cout<<"\nDo you want to continue then enter 1 else 0 : \n";
  cin>>ch;
 }
 return 0;
}
