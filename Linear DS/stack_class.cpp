#include<iostream>
using namespace std;
class stack
{
    public:
    struct node
    {
     int data;
     node *n;
    }*h;
    stack(){ h=NULL; }
    bool isEmpty(){ return h==NULL; }
    int topElement() { return h->data; }
    void push()
    {
     int k; node *t=new node;
     cout<<"\nEnter the data : ";
     cin>>t->data; t->n=h; h=t;
    }
    int pop()
    {
     if(isEmpty()) return -1;
     node *t=h; h=h->n;
     return t->data;
    }
    void show()
    {
     for(node *t=h;t;t=t->n)
      cout<<t->data<<" ";
    }
}st;
int main()
{
  int k;
  while(k)
  {
   cout<<"\nEnter 1 to push, 2 to top element,v3 to pop, 4 to show stack, 5 to isEmpty & 0 to terminate : ";
   cin>>k;
   if(k==1) st.push();
   if(k==2) cout<<"\nTop Element : "<<st.topElement()<<endl;
   if(k==3) cout<<"\nPopped data : "<<st.pop()<<endl;
   if(k==4) st.show();
   if(k==5) cout<<"\n"<<st.isEmpty()<<endl;
  }
}
