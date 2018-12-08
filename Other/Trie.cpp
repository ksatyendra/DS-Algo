#include<iostream>
#define Z 12
using namespace std;
class Trie
{
	struct tr
	{
		bool l;
		tr **a;
		tr()
		{
			l=0;
    		a=new tr*[26];
    		for(int i=0;i<26;i++)
    			a[i]=NULL;
		}
	}*tt;
	public :
	Trie()
	{
    	tt=new tr;
	}
	bool search(char s[])
	{
		tr* t=tt;
		for(int i=0;s[i]!='\0';i++)
			if(!(t=t->a[int(s[i])-97]))
				break;
		return t && t->l;
	}
	void insert(char s[])
	{
		int ind;
		tr* t=tt;
		for(int i=0;s[i]!='\0';i++)
		{
			ind=int(s[i])-97;
			if(!(t->a[ind]))
				t->a[ind]=new tr;
			t=t->a[ind];
		}
		t->l=1;
	}
	void del(char s[])
	{
		tr* t=tt;
		for(int i=0;s[i]!='\0';t=t->a[int(s[i])-97],i++);
		t->l=0;
	}
	void disp(tr* t,string k)
	{
		if(!t)
			return;
		if(t->l)
			cout<<k<<endl;
		for(int i=0;i<26;i++)
			disp(t->a[i],k+char(i+97));
	}
	void display()
	{
		disp(tt,"");
	}
	void init(char c[][15])
	{
		for(int i=0;i<Z;i++)
			insert(c[i]);
	}
};
int main()
{
	Trie dict;
	while(1)
	{
		cout<<"\n\n0 to quit, 1 to insert, 2 to search, 3 to delete, 4 to display & 5 to initialize\n";
		cout<<"\nEnter choice : ";
		int ch;
		cin>>ch;
		if(!ch) break;
		char c[Z][15]={"satyendra","kumar","yadav","shiva","singh","kettle","rate","sweet","son","sky","sun","cut"};
		char s[15];
		switch(ch)
		{
			case 1 : cout<<"\nEnter string : ";
					 cin>>s;
					 dict.insert(s);
					 break;
			case 2 : cout<<"\nEnter string : ";
					 cin>>s;
					 if(dict.search(s))
						cout<<"\nYes\n";
					 else
					 	cout<<"\nNo\n";
					 break;
			case 3 : cout<<"\nEnter string : ";
					 cin>>s;
					 dict.del(s); 
					 break;
			case 4 : dict.display();
					 break;
			case 5 : dict.init(c);
		}
	}
}