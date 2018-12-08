#include<iostream>
using namespace std;
struct htree
{
	int size,data;
	htree *parent,**child;
	htree(int m);
};
htree::htree(int m)
{
	size=m;
	parent=NULL;
	child=new htree*[size];
	for(int i=0;i<size;i++)
	child[i]=NULL; 
}
struct node
{
	htree *d;
	node *next;
	node();
};
node::node()
{
	next=NULL;
}
class llqueue
{
	public:
	node *front,*rear;
	void enqueue(htree*);
	htree* dequeue();
	llqueue();
};
llqueue::llqueue()
{
	front=NULL;
	rear=NULL;
}
void llqueue::enqueue(htree *b)
{
	if(rear==NULL)
	{
		rear=new node;
		rear->d=b;
		front=rear;
		}
	else
	{
		rear->next=new node;
		rear->next->d=b;
		rear=rear->next;
		}
}
htree* llqueue::dequeue()
{
	htree *t=NULL;node *z=NULL;
	if(rear==NULL)
    {
    return t;
    }
    if(front==rear)
    {
    t=front->d;
    z=front;
    delete(z);
    front=NULL;
    rear=NULL;
    return t;
    }
    else
    {
    t=front->d;
    z=front;
    front=front->next;
    delete(z);
    return t;
    }
}
void swap(int &n1,int &n2)
{
	int t;
	t=n1;
	n1=n2;
	n2=t;
}
void percolateup(htree *h)
{
	if(h->parent!=NULL)
	{
		if(h->data<h->parent->data)
		{
			swap(h->data,h->parent->data);
			percolateup(h->parent);
		}
	}
}
void levelenqueue(llqueue q,int k,int d)
{
	htree *b=NULL;
	if(q.front!=q.rear)
	{
		b=q.dequeue();
		if(b!=NULL)
		{	
			for(int i=0;i<d;i++)
			{
				if(b->child[i]!=NULL)
				q.enqueue(b->child[i]);
				else
				{
					b->child[i]=new htree(d);
					b->child[i]->data=k;
					b->child[i]->parent=b;
					percolateup(b->child[i]);
					return;
				}
			}
		}
		else if(b==NULL&&q.rear!=NULL)
		q.enqueue(b);
		levelenqueue(q,k,d);
	}	
}
void insert(htree *&h,int k,int d)
{
	if(h==NULL)
	{
		h=new htree(d);
		h->data=k;
	}
	else
	{
		llqueue q;
		htree *t=NULL;
		q.enqueue(h);
		q.enqueue(t);
		levelenqueue(q,k,d);
	}
}
htree* lastelement(llqueue q,int d)
{
	htree *b=NULL;
	if(q.front!=q.rear)
	{
		b=q.dequeue();
		if(b!=NULL)
		{	
			if(b->child[0]==NULL&&q.front->next==NULL)
			{
				htree *t=b;
				b=b->parent;
				for(int i=0;i<d;i++)
				{
					if(b->child[i]==t)
					{
						b->child[i]=NULL;
						break;
					}
				}
				return t;
			}
			for(int i=0;i<d;i++)
			if(b->child[i]!=NULL)
			q.enqueue(b->child[i]);
		}
		else if(b==NULL&&q.rear!=NULL)
		{
			q.enqueue(b);
		}
		return(lastelement(q,d));
	}
}
void percolatedown(htree *&h,int d)
{
	int min,pos;
	if(h!=NULL)
	{
		if(h->child[0]!=NULL)
		{
			min=h->child[0]->data;pos=0;
			for(int i=0;i<d-1;i++)
			{
				if(h->child[i+1]!=NULL)
				{
					if(h->child[i+1]->data<min)
					{
						min=h->child[i+1]->data;
						pos=i+1;
					}
				}
				else break;
			}
			if(h->data>h->child[pos]->data)
			{
				swap(h->data,h->child[pos]->data);
				percolatedown(h->child[pos],d);
			}
			else return;
		}
	}
}
void deletion(htree *&h,int d)
{
	if(h!=NULL)
	{
		llqueue q;
		cout<<h->data<<" ";
		htree *t=NULL;
		q.enqueue(h);
		q.enqueue(t);
		if(h->child[0]==NULL)
		{
			h=NULL;return;
		}
		else
		h->data=(lastelement(q,d))->data;
		percolatedown(h,d);
		deletion(h,d);
	}
}
void roottreetoqueue(htree *b,llqueue &q)
{
	if(b!=NULL)
	{
	htree *t=NULL;
	q.enqueue(b);
	q.enqueue(t);
	}
}
void displaylevel(llqueue q,int d)
{
	htree *b=NULL;
	if(q.front!=q.rear)
	{
		b=q.dequeue();
		if(b!=NULL)
		{	
			cout<<b->data<<" ";
			for(int i=0;i<d;i++)
			{
				if(b->child[i]!=NULL)
				q.enqueue(b->child[i]);
			}
		}
		else if(b==NULL&&q.rear!=NULL)
		{
			cout<<"\n";
			q.enqueue(b);
			}
		displaylevel(q,d);
		}	
}
int main()
{
	htree *n=NULL,*m=NULL;
	int c,d;
	cout<<"For d_heap enter d=";
	cin>>d;
	llqueue q;
	cout<<"Enter numbers=";
	do
	{
		cin>>c;
		if(c!=-1)
		{
			if(n==NULL)
			{
				insert(n,c,d);
				m=n;
			}
			else
			insert(n,c,d);
		}
	}while(c!=-1);
	cout<<"\nPrint in level:-\n";
	roottreetoqueue(m,q);displaylevel(q,d);
	q.front=NULL;q.rear=NULL;
	cout<<"\nPriority Order=";
	deletion(m,d);
}
