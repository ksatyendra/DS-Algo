#include<iostream>
#include"heap sort by tree.cpp"
//#include<cstdlib>
using namespace std;
int main()
{
    int flag,n,i,choice;
     hnode *h,*head;
    cout<<"Menu:\n";
    cout<<"1.Insert all numbers\n2.Print Inorder\n3.Print Preorder\n";
    while(1)
    {
    cout<<"Enter your choice: ";
    cin>>choice;
    if(choice==1)
    {	
        cout<<"Enter number of elements: ";
        cin>>n;
        int num[n];
        cout<<"Enter the numbers: ";
        for(i=0;i<n;i++)
        cin>>num[i];
       h=new hnode;
        h->data=num[0];
        head=h;
        create(h,num,n);
        
    }
    
    if(choice==3)
    {
        inorder(head);
       cout<<endl;
       preorder(head);
       cout<<endl;
      print_level_order(head);
    }
}
}
    /*if(choice==2)
    {
        cout<<"Enter element to be deleted: ";
        cin>>num;
        delete_node(n,num);
    }
    if(choice==3)
    {
        inorder(n);
        cout<<endl;
    }
     if(choice==4)
     {
			cout<<"The maximum number is: "<<findmax(n)<<endl;
     }
      if(choice==5)
      {
         cout<<"The minimum number is: "<< findmin(n)<<endl;
      }
    if(choice==6)
    {
		cout<<"Enter element to be searched: ";
    	cin>>num;
		find(n,num);
	}
    if(choice==7)
    print_level_order(n);
	if(choice==8)
    exit(1);
    if(choice==9)
    {print_like_tree(n);
    spaces_id(n);}
    if(choice==10)
    cout<<"The height of root node is " <<height(n)<<endl;
    if(choice==11)
    balanced_tree(n);
	}*/

