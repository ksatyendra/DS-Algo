#include<iostream>
using namespace std;
int top1,top2;
int a[40];
char b[40];
char c[40];
void push(int k)
{
 a[++top2]=k;
}
int pop()
{
 return a[top2--];
}
void pushc(char k)
{
 c[++top1]=k;
}
char popc()
{
 return c[top1--];
}
int in_eval()
{
 int i,i1,i2;
 for(i=0;b[i]!='\0';i++)
 {
  if(b[i]>='0'&&b[i]<='9')
   push(int(b[i])-48);
  else if(b[i]=='(')
   pushc(b[i]);
  else if(b[i]==')')
   for(char h=popc();h!='(';h=popc())
   {
    i1=pop();i2=pop();
    switch(h)
    { 
     case '+': push(i2+i1); break;
     case '-': push(i2-i1); break;
     case '*': push(i2*i1); break;
     case '/': push(i2/i1); break;
    }
   }
  else
  {
    for(;top1!=-1&&c[top1]!='(';)
    {
     char s=popc();
     if((b[i]=='*'||b[i]=='/')&&(s=='+'||s=='-'))
     { pushc(s);break; }
     i1=pop();i2=pop();
     switch(s)
     { 
      case '+': push(i2+i1); break;
      case '-': push(i2-i1); break;
      case '*': push(i2*i1); break;
      case '/': push(i2/i1); break;
     }
    }
   pushc(b[i]);
  }
 }
 while(top1!=-1)
 {
  i1=pop();i2=pop();
  switch(popc())
  { 
   case '+': push(i2+i1); break;
   case '-': push(i2-i1); break;
   case '*': push(i2*i1); break;
   case '/': push(i2/i1); break;
  }
 }
 return pop();
}
int main()
{
    top1=-1;top2=-1;
    cout<<"\nEnter expression : ";
    cin>>b;
    int k=in_eval();
    cout<<"\nans : "<<k<<endl;
    cin>>b;
}