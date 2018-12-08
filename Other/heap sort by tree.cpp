#include<iostream>
#include"queuetemplate.cpp"
using namespace std;
struct hnode
{
	int data,space_id;
	hnode *lchild,*rchild,*parent;
	hnode();
};
void swap(int &x,int &y)
{
	int temp;
	temp=x;
	x=y;
	y=temp;
}
hnode::hnode()
{
	lchild=rchild=parent=NULL;
}
void create(hnode* &h,int *a,int size)
{	 int i=1;
	queue<hnode*> q(20);
	q.enqueue(h);
	hnode *temp,*t;
	while(!q.empty()&&i<size)
	{	//cout<<"in"<<i<<endl;
	temp=q.dequeue();
	temp->lchild=new hnode;
		temp->lchild->data=a[i++];
		temp->lchild->parent=temp;
		t=temp->lchild;
		while(t->data<t->parent->data)
		{
		    cout<<"swapped left"<<endl;
			swap(t->data,t->parent->data);
			t=t->parent;
			if(t->parent==NULL)
			break;
		}
		if(i<size)
		{
            q.enqueue(temp->lchild);
            temp->rchild=new hnode;
            temp->rchild->data=a[i++];
            temp->rchild->parent=temp;
            t=temp->rchild;
            while(t->data<t->parent->data)
		{
		    cout<<"swapped right"<<endl;
			swap(t->data,t->parent->data);
			t=t->parent;
			if(t->parent==NULL)
			break;
		}
		q.enqueue(temp->rchild);
		}
	}
}
void delete_top(hnode* h)
{

}
int i=0;
void spaces_id(hnode *b)
{
	if(b!=NULL)
	{
	spaces_id(b->lchild);
	b->space_id=i;
	i++;
	spaces_id(b->rchild);
	}
}
void print_spaces(int n)
{	for(int i=0;i<2*n;i++)
	cout<<"*";
}
void print_level_order(hnode *root)
{	if(root==NULL)
	return;
	queue<hnode*> q(20);
	hnode *temp,*l,*r;
	q.enqueue(root);
	q.enqueue(NULL);

	while(!q.empty())
	{
		temp=q.dequeue();
		if(temp!=NULL)
		{
		cout<<temp->data<<" ";
		if(temp->lchild!=NULL) q.enqueue(temp->lchild);
		if(temp->rchild!=NULL) q.enqueue(temp->rchild);
		}
		else
		 if (!q.empty())
            {	cout<<endl;
				q.enqueue(NULL);
			}


	}
}
void inorder(hnode *b)
{
	if(b!=NULL)
	{
	inorder(b->lchild);
	cout<<b->data<<" ";
	inorder(b->rchild);
	}
}
void preorder(hnode *b)
{
	if(b!=NULL)
	{
	cout<<b->data<<" ";
	preorder(b->lchild);
	preorder(b->rchild);
	}
}
