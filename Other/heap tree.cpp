#include<iostream>
using namespace std;
struct node
{
	int data;
	node *left,*right;
};
node *a[20],*root;
int f=-1,r=-1;
struct node*create(int n)
{
	node *temp=new node;
	temp->data=n;
	temp->right=NULL;
	temp->left=NULL;
	return temp;
}
void push(struct node*t)
{
	r++;
	a[r]=t;
}
struct node*parent(struct node*t)
{
	int u=0;
	node *m=a[u];
	while(m!=t && m->left!=t && m->right!=t)
	{
		u++;
		m=a[u];
	}
	return m;
}
void process()
{
	node *p=parent(a[r]);
	node *p1=a[r];
	while(p->data<p1->data)
	{
		int k=p1->data;
		p1->data=p->data;
		p->data=k;
		p1=p;
		p=parent(p);
	}
}
void display()
{
	f=0;
	while((f-1)!=r)
	{
		cout<<a[f]->data;
		f++;
	}
}
int main()
{
    int n;
	cout<<"enter the elements you want to insert and press -1 to stop";
	cin>>n;
	root=create(n);
	f++;
	push(root);
	cin>>n;
	while(n!=-1)
	{
		a[f]->left=create(n);
		push(a[f]->left);
		process();
		cin>>n;
		if(n==-1)
		break;
		a[f]->right=create(n);
		push(a[f]->right);
		process();
		cin>>n;
		f++;
	}
	display();
	int b1;
	cin>> b1;
}
