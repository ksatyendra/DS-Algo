#include<iostream>
#include<list>
#include<stdlib.h>

using namespace std;
int IndexOfZero(int ar[][10], int n, int prev[])
{
	int flag = 0;
	for(int a=1; a <= n; a++)
	{
		for(int b = 1; b <= n; b++)
		{
			if(ar[b][a] == 0)
				flag = 1;
			else
			{
				flag = 0; break;
			}
		}
		if(flag)
		{
			int flg = 1;
			for(int i=1 ; i<n; i++)
				if(a == prev[i])
				{ flg=0; break; }
			if(flg)
			return a;
		}
	}
	return 0;
}
int main()
{
	int k=1,a,b,V;  int adj[10][10]={{}}; int prev[10]={};
	cin>>V;
	while(k)
	{
		//cout<<"Enter ( X -> Y) to connect : ";
		cin>>a>>b;
		adj[a][b] = 1;
		//cout<<"\nAdd More ? (1/0) : ";
		cin>>k;
	}
	cout<<"\n\n";
	for( a = 1; a <= V; a++)
	{
		k = IndexOfZero(adj, V, prev);
		prev[a]=k;
		if(k==0)
		{
			cout<<"\nCyclic Graph ..!!";
			exit(0);
		}
		for( b = 0; b<=V; b++)
			adj[k][b] = 0;
		cout<<" "<<k;
	}
	return 0;
}