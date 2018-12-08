#include<bits/stdc++.h>
using namespace std;
int main()
{
 queue<int> q;
 deque<int> dq;
 stack<int> s;
 list<int> l;
 
 //queue
 cout<<"QUEUE : ";
 q.push(5); q.push(6); q.push(7);
 cout<<q.front()<<" "<<q.back()<<" "<<endl;
 q.pop();
 cout<<q.front()<<" "<<q.back()<<" "<<endl;
 cout<<endl;

 //DEqueue
 cout<<"DEQUEUE : ";
 dq.push_front(5); dq.push_back(6); dq.push_front(9);
 cout<<dq.front()<<" "<<dq.back()<<" "<<endl;
 dq.pop_front();
 cout<<dq.front()<<" "<<dq.back()<<" "<<endl;
 cout<<endl;
 
 //stack
 cout<<"STACK : ";
 s.push(5); s.push(6);
 cout<<s.top()<<endl;
 s.pop();
 cout<<s.top()<<endl;
 cout<<endl;

 //list
 cout<<"LIST : ";
 l.push_back(5); l.push_back(6); l.push_front(9);
 cout<<l.front()<<" "<<l.back()<<endl;
 l.pop_front();
 cout<<l.front()<<" "<<l.back()<<endl;
}